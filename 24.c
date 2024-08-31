/*
============================================================================
Name : 24.c
Author : Mohammed Mubashir Khan
Description : Write a program to create an orphan process.
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
    int id = fork();
    if(id<0){
        printf("fork failed");
        exit(1);
    }
    else if(id == 0){
        printf ("Child Process(%d)\n",getpid());
        printf("Old Parent Process Id(%d)\n",getppid());
        sleep(5);
        printf("New Parent Process id(%d)\n",getppid());
        while(1){

        }
    }
    else{
        sleep(2);
        printf("Parent Process(%d)\n",getpid());
        exit(0);
    }
}

/*OUTPUT
============================================================================
Child Process(16179)
Old Parent Process Id(16178)
Parent Process(16178)
New Parent Process id(1499)
============================================================================
*/

