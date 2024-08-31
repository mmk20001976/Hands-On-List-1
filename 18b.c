/*
============================================================================
Name : p3.c
Author : Mohammed Mubashir Khan
Description :Write a program to perform Record locking.
 a. Implement write lock
 b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 29th Aug, 2024.
============================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

struct record{
    int flight_no;
    int ticket_no;
};

int main(){
    struct record detail;
    struct flock lock;
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/records.txt";
    int fd = open(filepath,O_RDWR);
    if(fd == -1){
        perror("Error opening File");
        return 1;
    }
    int choice,size;
    char rw_lock;
    printf("Enter r to fetch detail and w to book a ticket: ");
    scanf("%c",&rw_lock);
    getchar();
    printf("Choose Flight 1,2,3: ");
    scanf("%d",&choice);
    getchar();
    size = (sizeof(detail) + 1) * (choice - 1);
    printf("\n");
    lock.l_type = rw_lock == 'r' ? F_RDLCK : F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = lseek(fd,size,SEEK_SET);
    lock.l_len = sizeof(detail);
    lock.l_pid = getpid();
    printf("Before Entering Critical Section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Inside Critical Section\n");
    read(fd,&detail,sizeof(detail));
    printf("Fetch Details\n");
    printf("Flight No:%d   Ticket No:%d\n",detail.flight_no,detail.ticket_no);
    if(rw_lock == 'w'){
        detail.ticket_no++;
        printf("Update Details\n");
        printf("Flight No:%d   Ticket No:%d\n",detail.flight_no,detail.ticket_no);
        lseek(fd,-sizeof(detail),SEEK_CUR);
        write(fd,&detail,sizeof(detail));
        printf("Booking Done\n");
    }
    printf("Press Enter to Unlock:\n");
    getchar();
    lock.l_type = F_UNLCK;
    if(fcntl(fd,F_SETLK,&lock) == -1){
        printf("\nLock can't be relaseed\n");
        return 1;
    }
    else
    printf("\nlock released\n");
    return 0;

}    