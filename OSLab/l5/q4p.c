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
    pipe_fd = open(FIFO_NAME, open_mode);
    if (pipe_fd != -1) {
        while (1){
            printf("Enter stock to add or -1 to quit: ");
            scanf("%d", &i);
            if (i == -1)
                exit(0);
            res = write(pipe_fd, &i, sizeof(i));
            if (res == -1) {
                fprintf(stderr, "Write error on pipe\n");
                exit(1);
            }   
            else{
                fprintf(stdout, "Added %d items\n", i);
            }
        }
        (void)close(pipe_fd);
    }
    else {
        exit(1);
    }
}