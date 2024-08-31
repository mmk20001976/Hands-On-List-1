/*
============================================================================
Name : 1a.c
Author : Mohammed Mubashir Khan
Description : Create the following types of a files using system call
a.) FIFO (mkfifo library function)
Date: 31th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *path = "/home/mubashir/Desktop/pipe.txt";
    if (mkfifo(path, 0666) == -1) {
        printf("Error creating");
        exit(EXIT_FAILURE);
    }

    printf("FIFO file created at: %s\n", path);
    
    return 0;
}
