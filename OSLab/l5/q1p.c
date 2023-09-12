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

int main()
{
    int pipe_fd;
    int res;
    int open_mode = O_WRONLY;
    int i;
    if (access(FIFO_NAME, F_OK) == -1) {
        res = mkfifo(FIFO_NAME, 0777);
        if (res != 0) {
            fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
            exit(1);
        }
    }
    pipe_fd = open(FIFO_NAME, open_mode);
    if (pipe_fd != -1) {
        for (i = 0; i < 4; i++){
            res = write(pipe_fd, &i, sizeof(i));
            if (res == -1) {
                fprintf(stderr, "Write error on pipe\n");
                exit(1);
            }   
            else{
                fprintf(stdout, "Wrote: %d\n", i);
            }
        }
        i = -1;
        res = write(pipe_fd, &i, sizeof(i));
        if (res == -1) {
            fprintf(stderr, "Write error on pipe\n");
            exit(1);
        } 
        (void)close(pipe_fd);
    }
    else {
        exit(1);
    }
    printf("Process %d finished writing to pipe\n", getpid());
    exit(0);
}