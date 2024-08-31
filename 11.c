/*
============================================================================
Name : 11.c
Author : Mohammed Mubashir Khan
Description :Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
 a. use dup
 b. use dup2
 c. use fcntl
Date: 28th Aug, 2024.
============================================================================
*/



#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include<time.h>

int main(){
    int fd,fd_copy,fd_copy2,fd_copy3;
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/duplicate.txt";
    char buffer[41];
    fd = open(filepath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if(fd == -1){
        printf("error");
        return 1;
    }
    fd_copy = dup(fd);
    if(fd_copy == -1){
        perror("error copying file descriptor");
        return 1;
    }
    fd_copy2 = dup2(fd,0);
    fd_copy3 = fcntl(fd,F_DUPFD,0);
    lseek(fd_copy,0,SEEK_END);
    write(fd_copy,"Hello",5);
    write(fd_copy2," HI!",4);
    write(fd_copy3," Hello World",12);
    lseek(fd,0,SEEK_SET);
    scanf("%s", buffer);
    printf("Read from file: %s\n", buffer);
    close(fd);
    close(fd_copy2);
    close(fd_copy);
    return 0;
}