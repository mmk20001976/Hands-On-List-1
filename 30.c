/*
============================================================================
Name : 30.c
Author : Mohammed Mubashir Khan
Description :Write a program to run a script at a specific time using a Daemon process(executes sum.out)
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>

void createDaemon() {
    pid_t id = fork();
    if (id < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (id > 0) {
        exit(EXIT_SUCCESS);
    }

    int sid = setsid();
    if (sid < 0) {
        perror("New Session can't be created");
        exit(EXIT_FAILURE);
    }

    id = fork();
    if (id < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (id > 0) {
        exit(EXIT_SUCCESS);
    }

    close(0); // input
    close(1);  // output
    close(2); // err

}

void execute_at_time(int hour, int min) {
    while (1) {
        time_t now = time(NULL);
        struct tm *current_time = localtime(&now);

        if (current_time->tm_hour == hour && current_time->tm_min == min) {
            char *path = "/home/mubashir/Software Systems/Hands On List-1/sum.out";
            if (execl(path, path, "100", "5", NULL)) {  // output in a file sum.txt
                perror("Exec failed");
                exit(EXIT_FAILURE);
            }
        }

        sleep(30);
    }
}

int main() {
    createDaemon(); // creates a daemon process
    execute_at_time(23, 6); // Set hour to 18 and minute to 9

    return 0;
}