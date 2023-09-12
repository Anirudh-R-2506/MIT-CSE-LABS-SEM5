#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "/tmp/my_fifo"
#define TEN_MEG (1024 * 1024 * 10)

int main(int argc, char *argv[])
{
    int pipe_fd;
    int res;
    int open_mode = O_WRONLY;
    int i = 7;    
    if (access(FIFO_NAME, F_OK) == -1) {
        res = mkfifo(FIFO_NAME, 0777);
        if (res != 0) {
            fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
            exit(1);
        }
    }
    if (argc == 2){
        pipe_fd = open(FIFO_NAME, O_RDONLY);
        if (pipe_fd != -1) {
            while ((res = read(pipe_fd, &i, sizeof(int))) > 0){
                fprintf(stdout, "Read in child: %d\n", i);
            }
            (void)close(pipe_fd);
        }
        else {
            exit(1);
        }
        exit(0);
    }
    int status;
    pid_t pid;
    pid = fork();
    if (pid == -1){
        perror("Child not created");
        exit(0);
    }
    else if (pid == 0){
        if(execlp("./q2.o", "./q2.o", "child", NULL) == -1){
            perror("Error while executing");
            exit(-1);
        }
        exit(0);
    }
    pipe_fd = open(FIFO_NAME, open_mode);
    if (pipe_fd != -1) {
        res = write(pipe_fd, &i, sizeof(i));
        if (res == -1) {
            fprintf(stderr, "Write error on pipe\n");
            exit(1);
        }   
        else{
            fprintf(stdout, "Wrote: %d\n", i);
        }
        (void)close(pipe_fd);
    }
    else {
        exit(1);
    }
}