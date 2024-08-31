/*
============================================================================
Name : 25.c
Author : Mohammed Mubashir Khan
Description :Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
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

int main(){
    int id1,id2,id3;
    id1 = fork();
    if(id1 < 0)
    printf("fork failed\n");
    else if(id1 == 0){
        printf("Child Process 1 id :%d\n",getpid());
        sleep(10);
        exit(0);
    }
    id2 = fork();
    if(id2 < 0)
    printf("fork failed\n");
    else if(id2 == 0){
        printf("Child Process 2 id :%d\n",getpid());
        exit(0);
    }
    id3 = fork();
    if(id3 < 0)
    printf("fork failed\n");
    else if(id3 == 0){
        printf("Child Process 3 id :%d\n",getpid());
        exit(0);
    }
    sleep(1);
    printf("Parent Waiting for Child Process(%d)...\n",id1);
    int status;
    waitpid(id1,&status,0); // status gives information about how the child process terminated
    if(status == -1){
        printf("Wait Failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Child Process %d Terminated\n",id1);
    printf("Parent Exits\n");
    exit(0);

}

/*OUTPUT
============================================================================
Child Process 2 id :16930
Child Process 3 id :16931
Child Process 1 id :16929
Parent Waiting for Child Process(16929)...
Child Process 16929 Terminated
Parent Exits
============================================================================
*/