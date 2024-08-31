/*
============================================================================
Name : 23.c
Author : Mohammed Mubashir Khan
Description :Write a program to create a Zombie state of the running program.
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
#include<sys/wait.h>

// Zombie process : a process which has finished executing but its entry is still available in the process table to report to its parent
int main(){
    int id = fork();
    if(id<0)
    printf("fork failed");
    else if(id == 0){
        printf("child process(%d) exits\n",getpid());
        exit(0);
    }
    else{
        system("ps -l | grep Z");
        printf("Parent process(%d)\n",getpid());
        sleep(5);
    }

}


/*OUTPUT
============================================================================
child process(15659) exits
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
1 Z  1000   15659   15658  0  80   0 -     0 -      pts/4    00:00:00 a.out
Parent process(15658)
============================================================================
*/