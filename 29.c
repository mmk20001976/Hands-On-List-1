/*
============================================================================
Name : 29.c
Author : Mohammed Mubashir Khan
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
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




void printPolicy(int policy){
    switch(policy){
        case SCHED_OTHER: printf("Current Scheduling Policy is: SCHED_OTHER\n");
                break;
        case SCHED_FIFO: printf("Current Scheduling Policy is: SCHED_FIFO\n");
                break;
        case SCHED_RR: printf("Current Scheduling Policy is: SCHED_RR\n");
                break;
        default: printf("Unknown policy\n");     
                
    }
}
int main(){
    int policy;
    struct sched_param param;
    policy = sched_getscheduler(0); 
    if (policy == -1){
        perror("sched_getscheduler");
        return 1;
    }
    printPolicy(policy);
    int choice;
    printf("Enter 1 for SCHED_FIFO and 2 for SCHED_RR: ");
    scanf("%d",&choice);
    getchar();
    switch (choice) {
        case 1:
            policy = SCHED_FIFO;
            break;
        case 2:
            policy = SCHED_RR;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    param.sched_priority = 1;
    if(sched_setscheduler(0,choice, &param) == -1){
        perror("sched_setscheduler");
        return 1;
    }
    else{
        printf("New Policy: ");
        policy = sched_getscheduler(0); 
        if (policy == -1){
            perror("sched_getscheduler");
            return 1;
        }
        printPolicy(policy);
    }

}

/*OUTPUT
============================================================================
Current Scheduling Policy is: SCHED_OTHER
Enter 1 for SCHED_FIFO and 2 for SCHED_RR: 2
New Policy: Current Scheduling Policy is: SCHED_RR
============================================================================
*/



