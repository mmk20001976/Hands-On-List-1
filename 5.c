/*
============================================================================
Name : 5.c
Author : Mohammed Mubashir Khan
Description :Write a program to create five new files with infinite loop.
Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 28th Aug, 2024.
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

#define n 5

int main(){
    char str[100];
    int fd[n];
    for(int i=0;i<5;i++){
        sprintf(str,"/home/mubashir/Software Systems/Hands On List-1/file%d.txt",i+1);
        fd[i] = open(str,O_CREAT | O_WRONLY, S_IRUSR|S_IWUSR);
        if(fd[i] == -1){
            printf("error opening file\n");
            exit(0);
        }

    }

    while(1){
        for(int i=0;i<5;i++){
            write(fd[i],"Hi!",3);
        }
    }
   
}
/*OUTPUT
============================================================================
0  1  2  3  4  5  6  7
============================================================================
*/
