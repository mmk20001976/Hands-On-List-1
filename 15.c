/*
============================================================================
Name : 15.c
Author : Mohammed Mubashir Khan
Description :Write a program to display the environmental variable of the user (use environ)
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

int main(){
    extern char **environ; 
    printf("Environment Variables:\n");
    for (char **env = environ; *env != NULL; env++) 
    printf("%s\n", *env);
    

    return 0;

}

