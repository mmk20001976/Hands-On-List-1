/*
============================================================================
Name : 20.c
Author : Mohammed Mubashir Khan
Description :Find out the priority of your running program. Modify the priority with nice command.
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
#include<sys/wait.h>
#include<sched.h>

int main(){
    struct sched_param param;
    sched_getparam(0, &param);
    int policy = sched_getscheduler(0);
    if(policy == 0)
    printf("SCHED_OTHER\n");
    if(policy == 1)
    printf("SCHED_FIFO\n");
    if(policy == 2)
    printf("SCHED_RR\n");
    printf("Current priority:%d\n",param.sched_priority);
    
}
/*OUTPUT
============================================================================
SCHED_OTHER
Current priority:0
============================================================================
*/

