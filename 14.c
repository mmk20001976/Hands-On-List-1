/*
============================================================================
Name : 14.c
Author : Mohammed Mubashir Khan
Description :Write a program to find the type of a file.
 a. Input should be taken from command line.
 b. program should be able to identify any type of a file. 
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

int main(int arg,char *argv[]){
    if(arg<2){
        printf("Please Enter file path");
        return 1;
    }
    char* filepath = argv[1];
    char command[100] = "file ";
    strcat(command,filepath);
    int status = system(command);
        if (status == 0){
            printf("File type: %s\n", filepath);
        } 
        else{
           printf("Error executing file command: %s\n", filepath);
        }
    return 0;    


}