/*
============================================================================
Name : p3.c
Author : Mohammed Mubashir Khan
Description :Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit
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
    int fd;
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/ticket.txt";
    fd = open(filepath,O_RDWR | O_TRUNC | O_CREAT, S_IRUSR |S_IWUSR);
    if(fd<0){
        perror("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_pid = getpid();
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    fcntl(fd,F_SETLKW,&lock);
    write(fd,"12",2);
    lock.l_type = F_UNLCK;
    if(fcntl(fd,F_SETLK,&lock) == -1){
        printf("\nLock can't be relaseed\n");
        return 1;
    }
    return 0;
}