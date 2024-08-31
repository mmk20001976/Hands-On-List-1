/*
============================================================================
Name : 21.c
Author : Mohammed Mubashir Khan
Description :Write a program, call fork and print the parent and child process id.
Date: 30th Aug, 2024.
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
    int id = fork();
    if(id<0)
    printf("fork failed\n");
    else if(id == 0)
    printf("Child process id: %d\n",getpid());
    else
    printf("Parent process id: %d\n",getpid());
}

/*OUTPUT
============================================================================
Parent process id: 16410
Child process id: 16411
============================================================================
*/