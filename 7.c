/*
============================================================================
Name : 7.c
Author : Mohammed Mubashir Khan
Description :Write a program to copy file1 into file2 ($cp file1 file2)
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
int main(){
    int rfd,wfd;
    char rbuffer[128];
    // char wbuffer[128];
    char* read_filepath = "/home/mubashir/Software Systems/Hands On List-1/read.txt";;
    char* write_filepath = "/home/mubashir/Software Systems/Hands On List-1/write.txt";;
    rfd = open(read_filepath,O_RDONLY);
    if(rfd == -1){
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    wfd = open(write_filepath, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if(wfd == -1){
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    while(read(rfd,rbuffer,1)>0){
        write(wfd,rbuffer,1);
    }
    

}

