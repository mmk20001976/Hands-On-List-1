/*
============================================================================
Name : 1a.c
Author : Mohammed Mubashir Khan
Description : Create the following types of a files using system call
a.) soft link (symlink system call)
Date: 31th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

    char *path1 = "/home/mubashir/Software Systems/Hands On List-1/write.txt";
    char *path2 = "/home/mubashir/Desktop/softlinkticket.sh";
    int val=symlink(path1,path2);

    if(val==0){
        printf("The/home/mubashir/Software Systems/Hands On List-1/write.txt softlink has been created successfully. \n");
    }
    else{
        printf("The softlink creation was unsuccessful.\n");
    }

    return 0;
}