/*
============================================================================
Name :9.c
Author : Mohammed Mubashir Khan
Description :Write a program to print the following information about a given file.
 a. inode
 b. number of hard links
 c. uid
 d. gid
 e. size
 f. block size
 g. number of blocks
 h. time of last access
 i. time of last modification
 j. time of last change
Date: 28th Aug, 2024.
============================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
#include<time.h>

int main(){
    int fd;
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/write.txt";
    struct stat file_info;
    stat(filepath, &file_info);
    printf("Inode Number:%llu\n",(unsigned long long)file_info.st_ino);
    printf("Number of Hard links:%lu\n",(unsigned long)file_info.st_nlink);
    printf("User Id:%llu\n",(unsigned long long)file_info.st_uid);
    printf("Group Id:%llu\n",(unsigned long long)file_info.st_gid);
    printf("File Size:%llu\n",(unsigned long long)file_info.st_size);
    printf("Block Size:%llu\n",(unsigned long long)file_info.st_blksize);
    printf("Number of Blocks:%llu\n",(unsigned long long)file_info.st_blocks);
    printf("Access time:%s\n",ctime(&file_info.st_atime));
    printf("Last Modification:%s\n",ctime(&file_info.st_mtime));
    printf("Last Status:%s\n",ctime(&file_info.st_ctime));
    

}

/*OUTPUT
============================================================================
Inode Number:1084401
Number of Hard links:2
User Id:1000
Group Id:1000
File Size:39
Block Size:4096
Number of Blocks:8
Access time:Sat Aug 31 13:19:08 2024

Last Modification:Fri Aug 30 21:02:38 2024

Last Status:Sat Aug 31 13:19:03 2024
============================================================================
*/


