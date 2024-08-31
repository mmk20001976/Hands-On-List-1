/*
============================================================================
Name : 26.c
Author : Mohammed Mubashir Khan
Description :26. Write a program to execute an executable program.
 a. use some executable program(mul.out) multiplies two integers
 b. pass some input to an executable program.
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
    char *path = "/home/mubashir/Software Systems/Hands On List-1/mul.out";
    if(execl(path,path,"123","546",NULL)){
        perror("Exce failed");
        return 1;
    }

}
/*OUTPUT
============================================================================
mubashir@mubashir-17Z90P-G-AH85A2:~/Software Systems/Hands On List-1$ ./a.out 
Multiplication of 123 and 546 is: 67158
============================================================================
*/