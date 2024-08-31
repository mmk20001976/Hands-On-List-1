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
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("Multiplication of %d and %d is: %d\n",a,b,a*b);
}