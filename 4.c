/*
============================================================================
Name : 4.c
Author : Mohammed Mubashir Khan
Description :Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 28th Aug, 2024.
============================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

int main(){
    char* file_path = "/home/mubashir/Software Systems/Hands On List-1/sample.txt";
    int fd;
    fd = open(file_path,O_CREAT| O_RDWR | O_EXCL, 0644);
    if(fd == -1)
    printf("File already exists");
    else
    printf("file created successfully");
}
/*OUTPUT
============================================================================
File already exists
============================================================================
*/


