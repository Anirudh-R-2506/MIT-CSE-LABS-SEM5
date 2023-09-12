#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#define FIFO_NAME "/tmp/my_fifo"
#define BUFFER_SIZE 4096

int main()
{
    int pipe_fd;
    int res;
    int open_mode = O_RDONLY;
    int buffer;
    pipe_fd = open(FIFO_NAME, open_mode);
    if (pipe_fd != -1) {
        do {
            res = read(pipe_fd, &buffer, sizeof(int));
            if (buffer != -1)
                fprintf(stdout, "Read: %d\n", buffer);
            else{
                fprintf(stdout, "Process %d finished reading from pipe\n", getpid());
                break;
            }
        } while (res > 0);
        (void)close(pipe_fd);
    }
    else {
        exit(1);
    }
    exit(0);
}