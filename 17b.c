/*
============================================================================
Name : p3.c
Author : Mohammed Mubashir Khan
Description :Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 29th Aug, 2024.
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
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/ticket.txt";
    fd = open(filepath,O_RDWR);
    char buffer[20];
    if(fd<0){
        perror("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    
    lock.l_type = F_WRLCK;
    lock.l_pid = getpid();
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;


    printf("Before Entering Critical Section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Inside the Critical Section\n");
    lseek(fd,0,SEEK_SET);
    char ch;
    int i = 0;
    while (read(fd, &ch, 1) > 0) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';
    int ticket = atoi(buffer);
    printf("Before ticket:%d\n",ticket);
    ticket++;
    printf("After ticket:%d\n",ticket);
    int len = sprintf(buffer, "%d",ticket);
    lseek(fd,0,SEEK_SET);
    write(fd,buffer,len);
    printf("Press Enter to Unlock:\n");
    getchar();
    lock.l_type = F_UNLCK;
    if(fcntl(fd,F_SETLK,&lock) == -1){
        printf("\nLock can't be relaseed\n");
        close(fd);
        return 1;
    }
    else
    printf("\nlock released\n");
    close(fd);
    return 0;
}