/*
============================================================================
Name : 19.c
Author : Mohammed Mubashir Khan
Description :Write a program to find out time taken to execute getpid system call. Use time stamp counter. 
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

int main(){
    struct timespec before, after;
    clock_gettime(CLOCK_REALTIME, &before);
    int pid = getpid();
    clock_gettime(CLOCK_REALTIME, &after);
    double time_taken = ((after.tv_sec - before.tv_sec) + (after.tv_nsec - before.tv_nsec))/1000000000.0;
    printf("Time taken: %.9f seconds",time_taken);

}

/*OUTPUT
============================================================================
Time taken: 0.000002238 seconds
============================================================================
*/


