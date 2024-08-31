/*
============================================================================
Name : 16.c
Author : Mohammed Mubashir Khan
Description :Write a program to perform mandatory locking.
 a. Implement write lock
 b. Implement read lock
Date: 28th Aug, 2024.
============================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>


int main(){
    struct flock lock;
    int fd;
    char rbuffer[15];
    char wbuffer[15];
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/read.txt";
    fd = open(filepath,O_RDWR | O_CREAT,S_IRUSR|S_IWUSR);
    int choice;
    printf("Enter 0 to acquire read lock\nEnter 1 to acquire write lock");
    scanf("%d",&choice);
    getchar();
    switch(choice){
        case 0: lock.l_type = F_RDLCK;
                break;
        case 1: lock.l_type = F_WRLCK;

    }
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_start = 0;
    lock.l_pid = getpid();
    printf("Before entering into critical section\n");
    fcntl(fd, F_SETLKW, &lock); // waits if lock not available
    printf("Inside the critical section\n");
    lseek(fd,0,SEEK_SET);
    if(choice == 0){
        printf("\nreading from file\n");
        read(fd,rbuffer,10);
        printf("content of file: %s",rbuffer);
        getchar();
    }
    else{
        printf("\nwriting to a file\n");
        write(fd,"Hello World\n",13);
        getchar();
    }
    printf("\nPress enter to unlock\n");
    getchar();
    lock.l_type = F_UNLCK;
    if(fcntl(fd,F_SETLK,&lock) == -1){
        printf("\nLock can't be relaseed\n");
        return 1;
    }
    else
    printf("\nlock released\n");
    return 0;

}