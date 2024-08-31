#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>

int main(int argc,char* argv[]){
    if(argc<3){
        printf("Not sufficent arguments");
        exit(0);
    }
    int fd;
    char buffer[100];
    char* filepath = "/home/mubashir/Software Systems/Hands On List-1/sum.txt";
    fd = open(filepath,O_WRONLY | O_CREAT | O_APPEND, S_IRUSR|S_IWUSR);
    if(fd == -1){
        printf("error");
        return 1;
    }
    dup2(fd,1);
    close(fd);
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int bytes_written = sprintf(buffer,"Sum of %d and %d is:%d\n",a,b,a+b);
    write(1,buffer,bytes_written);
    return 0;
}