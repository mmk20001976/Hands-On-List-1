/*
============================================================================
Name : 28.c
Author : Mohammed Mubashir Khan
Description : Write a program to get maximum and minimum real time priority.
Date: 31th Aug, 2024.
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
#include<sched.h>

int main(){
    int max_priority_FIFO,min_priority_FIFO,min_priority_RR,max_priority_RR;
    max_priority_FIFO = sched_get_priority_max(SCHED_FIFO);
    min_priority_FIFO = sched_get_priority_min(SCHED_FIFO);
    max_priority_RR = sched_get_priority_max(SCHED_RR);
    min_priority_RR = sched_get_priority_min(SCHED_RR);

    printf("FIFO\n");
    printf("Max: %d AND Min: %d\n",max_priority_FIFO,min_priority_FIFO);
    printf("RR\n");
    printf("Max: %d AND Min: %d\n",max_priority_RR,min_priority_RR);
}

/*OUTPUT
============================================================================
FIFO
Max: 99 AND Min: 1
RR
Max: 99 AND Min: 1
============================================================================
*/