/*
============================================================================
Name : 20.c
Author : Mohammed Mubashir Khan
Description :Write a program to execute ls -Rl by the following system calls
c)execle
Date: 30th Aug, 2024.
============================================================================
*/

 
#include<unistd.h>
#include<stdio.h>

int main(){
    printf("Before execle\n");
    char *envp[] = {NULL };

    if(execle("/bin/ls","ls","-Rl",NULL,envp) == -1){
        perror("execle failed");
        return 1;
    }

    printf("After execle\n");

    return 0;
}
/*OUTPUT
============================================================================
Before execle
.:
total 15167968
-rw-rw-r-- 1 mubashir mubashir       1518 Aug 31 13:57 10.c
-rw-rw-r-- 1 mubashir mubashir       1328 Aug 31 13:58 11.c
-rw-rw-r-- 1 mubashir mubashir       1038 Aug 31 13:59 12.c
-rw-rw-r-- 1 mubashir mubashir       1038 Aug 31 14:22 13.c
-rw-rw-r-- 1 mubashir mubashir        987 Aug 31 14:01 14.c
-rw-rw-r-- 1 mubashir mubashir        663 Aug 31 14:22 15.c
-rw-rw-r-- 1 mubashir mubashir       1799 Aug 31 14:02 16.c
-rw-rw-r-- 1 mubashir mubashir       1155 Aug 31 14:09 17a.c
-rw-rw-r-- 1 mubashir mubashir       1742 Aug 31 14:11 17b.c
-rw-rw-r-- 1 mubashir mubashir        952 Aug 31 14:13 18a.c
-rw-rw-r-- 1 mubashir mubashir       2178 Aug 31 14:14 18b.c
-rw-rw-r-- 1 mubashir mubashir       1012 Aug 31 14:15 19.c
-rw-rw-r-- 1 mubashir mubashir        820 Aug 31 13:29 1a.c
-rw-rw-r-- 1 mubashir mubashir        815 Aug 31 13:28 1b.c
-rw-rw-r-- 1 mubashir mubashir        661 Aug 31 13:28 1c.c
-rw-rw-r-- 1 mubashir mubashir       2204 Aug 31 13:45 2.c
-rw-rw-r-- 1 mubashir mubashir       1041 Aug 31 14:15 20.c
-rw-rw-r-- 1 mubashir mubashir        886 Aug 31 14:16 21.c
-rw-rw-r-- 1 mubashir mubashir        991 Aug 31 14:17 22.c
-rw-rw-r-- 1 mubashir mubashir       1279 Aug 31 14:19 23.c
-rw-rw-r-- 1 mubashir mubashir       1174 Aug 31 14:21 24.c
-rw-rw-r-- 1 mubashir mubashir       1780 Aug 31 14:24 25.c
-rw-rw-r-- 1 mubashir mubashir       1058 Aug 31 14:28 26.c
-rw-rw-r-- 1 mubashir mubashir       5243 Aug 31 14:40 27a.c
-rw-rw-r-- 1 mubashir mubashir       5242 Aug 31 14:39 27b.c
-rw-rw-r-- 1 mubashir mubashir        857 Aug 31 14:40 27c.c
-rw-rw-r-- 1 mubashir mubashir          0 Aug 31 14:34 27d.c
-rw-rw-r-- 1 mubashir mubashir          0 Aug 31 14:34 27e.c
-rw-rw-r-- 1 mubashir mubashir       1221 Aug 31 14:27 28.c
-rw-rw-r-- 1 mubashir mubashir       2202 Aug 31 14:31 29.c
-rw-rw-r-- 1 mubashir mubashir        911 Aug 31 13:46 3.c
-rw-rw-r-- 1 mubashir mubashir       1681 Aug 31 14:32 30.c
-rw-rw-r-- 1 mubashir mubashir        885 Aug 31 13:45 4.c
-rw-rw-r-- 1 mubashir mubashir       1183 Aug 31 13:44 5.c
-rw-rw-r-- 1 mubashir mubashir        592 Aug 31 13:45 6.c
-rw-rw-r-- 1 mubashir mubashir       1049 Aug 31 13:47 7.c
-rw-rw-r-- 1 mubashir mubashir       1290 Aug 31 13:48 8.c
-rw-rw-r-- 1 mubashir mubashir       1873 Aug 31 13:50 9.c
drwxrwxr-x 2 mubashir mubashir       4096 Aug 31 00:01 Notes
-rwxrwxr-x 1 mubashir mubashir      16096 Aug 31 14:40 a.out
-rw------- 1 mubashir mubashir         21 Aug 30 21:51 duplicate.txt
-rw-r--r-- 1 mubashir mubashir 3106342683 Aug 31 00:02 file1.txt
-rw-r--r-- 1 mubashir mubashir 3106342683 Aug 31 00:02 file2.txt
-rw-r--r-- 1 mubashir mubashir 3106342683 Aug 31 00:02 file3.txt
-rw-r--r-- 1 mubashir mubashir 3106342683 Aug 31 00:02 file4.txt
-rw-r--r-- 1 mubashir mubashir 3106342683 Aug 31 00:02 file5.txt
-rwxrwxr-x 1 mubashir mubashir        392 Aug 31 13:45 mul.c
-rwxrwxr-x 1 mubashir mubashir      16040 Aug 30 22:47 mul.out
-rw-rw-r-- 1 mubashir mubashir         21 Aug 29 18:19 output.txt
-rw------- 1 mubashir mubashir         55 Aug 30 22:31 parent-child.txt
-rw-rw-r-- 1 mubashir mubashir         39 Aug 30 22:08 read.txt
-rw------- 1 mubashir mubashir         27 Aug 30 22:14 records.txt
-rw-r----- 1 mubashir mubashir          0 Aug 30 19:23 sample.txt
-rw------- 1 mubashir mubashir         30 Aug 31 13:56 space.txt
-rw-rw-r-- 1 mubashir mubashir        741 Aug 30 22:53 sum.c
-rwxrwxr-x 1 mubashir mubashir      16288 Aug 30 23:03 sum.out
-rw------- 1 mubashir mubashir         97 Aug 30 23:08 sum.txt
-rw------- 1 mubashir mubashir          2 Aug 31 14:10 ticket.txt
-rwx------ 2 mubashir mubashir         39 Aug 30 21:02 write.txt

./Notes:
total 60
-rw-rw-r-- 1 mubashir mubashir 2424 Aug 30 21:44 p10.txt
-rw-rw-r-- 1 mubashir mubashir 2540 Aug 27 19:46 p11.txt
-rw-rw-r-- 1 mubashir mubashir 1861 Aug 27 20:26 p12.txt
-rw-rw-r-- 1 mubashir mubashir  682 Aug 27 22:20 p14.txt
-rw-rw-r-- 1 mubashir mubashir  178 Aug 28 00:58 p15.txt
-rw-rw-r-- 1 mubashir mubashir 1519 Aug 29 15:55 p19.txt
-rw-rw-r-- 1 mubashir mubashir  112 Aug 29 16:08 p20.txt
-rw-rw-r-- 1 mubashir mubashir  740 Aug 29 16:21 p21.txt
-rw-rw-r-- 1 mubashir mubashir  597 Aug 29 18:19 p23.txt
-rw-rw-r-- 1 mubashir mubashir 1409 Aug 29 21:41 p25.txt
-rw-rw-r-- 1 mubashir mubashir 1320 Aug 30 15:38 p29.txt
-rw-rw-r-- 1 mubashir mubashir  778 Aug 30 19:25 p3.txt
-rw-rw-r-- 1 mubashir mubashir  667 Aug 30 19:28 p4.txt
-rw-rw-r-- 1 mubashir mubashir   11 Aug 30 20:37 p5.txt
-rw-rw-r-- 1 mubashir mubashir 1102 Aug 30 20:43 p6.txt
============================================================================
*/