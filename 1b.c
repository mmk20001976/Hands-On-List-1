/*
============================================================================
Name : 1a.c
Author : Mohammed Mubashir Khan
Description : Create the following types of a files using system call
a.) hard link (link system call)
Date: 31th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

    char *path1 = "/home/mubashir/Software Systems/Hands On List-1/write.txt";
    char *path2 = "/home/mubashir/Desktop/hardlinkticket.sh";
    int val=link(path1,path2);

    if(val==0){
        printf("The/home/mubashir/Software Systems/Hands On List-1/write.txt hardlink has been created successfully. \n");
    }
    else{
        printf("The hardlink creation was unsuccessful.\n");
    }

    return 0;
}