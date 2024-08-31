/*
============================================================================
Name : 8.c
Author : Mohammed Mubashir Khan
Description :Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
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
    char* read_filepath = "/home/mubashir/Software Systems/Hands On List-1/read.txt";
    char* write_filepath = "/home/mubashir/Software Systems/Hands On List-1/write.txt";
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
    int i = 0;
    char ch;
    while(read(rfd,&ch,1)>0){  
        rbuffer[i++] = ch;
        if(ch == '\n'){
            write(wfd,rbuffer,i);
            i=0;
        }
    }
    write(wfd,rbuffer,i);
    close(rfd);
    close(wfd);

    return 0;
    

}