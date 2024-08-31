/*
============================================================================
Name : 13.c
Author : Mohammed Mubashir Khan
Description :Write a program to find out the opening mode of a file. Use fcntl
Date: 30th Aug, 2024.
============================================================================
*/

#include<sys/types.h>
#include<sys/time.h>
#include<err.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
    int value =0;
    struct timeval tmo;
    fd_set readfds;

    printf("Enter the non-zero number: ");

    fflush(stdout);

    //wait only 10 seconds for user input*/
    FD_ZERO(&readfds);
    FD_SET(0, &readfds);
    tmo.tv_sec = 10;
    tmo.tv_usec = 0;

    switch(select(1, &readfds, NULL, NULL, &tmo)){
        case -1:
            err(1, "select");
            break;
        case 0:
            printf("User don't give input");
            return(1);
    }

    scanf("%d",&value);
    if(value!=0){
        printf("User input a number: %d\n",value);
    }
    else{
        printf("NO input received\n");
    }
    return 0;
}

/*OUTPUT
============================================================================
mubashir@mubashir-17Z90P-G-AH85A2:~/Software Systems/Hands On List-1$ ./a.out 
Enter the non-zero number: User don't give input


mubashir@mubashir-17Z90P-G-AH85A2:~/Software Systems/Hands On List-1$ ./a.out 
Enter the non-zero number: 15
User input a number: 15
============================================================================
*/

