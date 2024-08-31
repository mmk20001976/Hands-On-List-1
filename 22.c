/*
============================================================================
Name : 22.c
Author : Mohammed Mubashir Khan
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file. 
Date: 30th Aug, 2024.
============================================================================
*/

int main() {
    int fd;
    char *filepath = "/home/mubashir/Software Systems/Hands On List-1/parent-child.txt";
    fd = open(filepath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open failed");
        exit(EXIT_FAILURE);
    }

    int id = fork();
    if (id < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (id == 0) {
        char *s = "hi! I am the child process\n";
        write(fd, s, strlen(s));
    } else {
        char *s = "hi! I am the parent process\n";
        write(fd, s, strlen(s));
    }

    close(fd);

    return 0;
}