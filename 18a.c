/*
============================================================================
Name : 18a.c
Author : Mohammed Mubashir Khan
Description :Write a program to perform Record locking(Creating structure for Record)
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
    struct record arr[3];
    int fd;
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/records.txt";
    fd = open(filepath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    char ch = '\n';
    if(fd == -1){
        perror("Error opening File");
        return 1;
    }
    for(int i=0;i<3;i++){
        arr[i].flight_no = i+1;
        arr[i].ticket_no = 0;
        write(fd,&arr[i],sizeof(arr[i]));
        write(fd,&ch,1);
    }

    return 0;
    
}