/*
============================================================================
Name : 10.c
Author : Mohammed Mubashir Khan
Description :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
 a. check the return value of lseek
 b. open the file with od and check the empty spaces in between the dataWrite 
Date: 28th Aug, 2024.
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
    int fd;
    char buffer[20];
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/space.txt";
    fd = open(filepath, O_RDWR | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR);
    printf("Enter 10 characters:\n");
    read(0,buffer,10);
    buffer[10] = '\0';
    write(fd,buffer,10);
    off_t offset = lseek(fd,10,SEEK_CUR);
    printf("Offset: %ld\n", offset);
    write(fd,buffer,10);
    system("od -td1z space.txt");
    return 0;
}
/*OUTPUT
============================================================================
Offset: 20
0000000   97   98   99  100  101  102  103  104  105   10    0    0    0    0    0    0  >abcdefghi.......<
0000020    0    0    0    0   97   98   99  100  101  102  103  104  105   10            >....abcdefghi.<
0000036
============================================================================
*/

