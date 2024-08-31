/*
============================================================================
Name : 12.c
Author : Mohammed Mubashir Khan
Description :Write a program to find out the opening mode of a file. Use fcntl
Date: 28th Aug, 2024.
============================================================================
*/



#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include<time.h>

int main(){
    int fd;
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/duplicate.txt";
    fd  = open(filepath,O_CREAT, S_IRUSR);
    if(fd == -1){
        perror("Error");
        return 1;
    }
    int flag = fcntl(fd, F_GETFL); 
    if(flag == -1){
        perror("Failure");
        return 1;
    }
    int mode = flag & O_ACCMODE;
      if (mode == O_RDONLY) {
        printf("read-only mode\n");
    } else if (mode == O_WRONLY) {
        printf("write-only mode\n");
    } else if (mode == O_RDWR) {
        printf("read-write mode\n");
    }

    close(fd);
    return 0;

  

}