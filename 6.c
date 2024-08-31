/*
============================================================================
Name : 6.c
Author : Mohammed Mubashir Khan
Description :Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls 
Date: 28th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

int main(){
    char buffer[128];
    ssize_t bytesread;
    bytesread = read(0,buffer,10);
    buffer[bytesread+1] = '\0';
    write(1,buffer,10);
}


