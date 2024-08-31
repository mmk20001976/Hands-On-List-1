/*
============================================================================
Name : 3.c
Author : Mohammed Mubashir Khan
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 28th Aug, 2024.
============================================================================
*/



#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

int main(){
    int file_descriptor;
    char* file_path = "/home/mubashir/Software Systems/Hands On List-1/sample.txt";
    file_descriptor = creat(file_path,S_IWUSR | S_IRUSR |S_IRGRP);
    printf("file desriptor value: %d\n",file_descriptor);
    getchar();
    return 0;
}

/*OUTPUT
============================================================================
file desriptor value: 3
============================================================================
*/


