#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char buf[80];

#define TIME(time) strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", localtime(&time))

int main(int argc, char *argv[]){
    if (argc < 2){
        exit(-1);
    }
    struct stat fs;
    int s;
    if((s = stat(argv[1], &fs)) != 0){
        printf("File could not be opened");
        exit(-1);
    }
    printf("File Size: \t\t%ld bytes\n", fs.st_size);
    printf("Number of Links: \t%ld\n", fs.st_nlink);
    printf("File inode: \t\t%ld\n", fs.st_ino);
    printf("Device: \t\t%ld\n", fs.st_dev);
    printf("Owner ID: \t\t%d\n", fs.st_uid);
    printf("Group ID: \t\t%d\n", fs.st_gid);
    printf("Device Node: \t\t%ld\n", fs.st_rdev);
    TIME(fs.st_atime);
    printf("Last Accessed: \t\t%s\n", buf);
    TIME(fs.st_mtime);
    printf("Last Modified: \t\t%s\n", buf);
    TIME(fs.st_ctime);
    printf("Last Changed: \t\t%s\n", buf);
    printf("Block Size: \t\t%ld\n", fs.st_blksize);
    printf("No. of Blocks: \t\t%ld\n", fs.st_blocks);
    printf("File Permissions: \t");
    printf( (S_ISDIR(fs.st_mode)) ? "d" : "-");
    printf( (fs.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fs.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fs.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fs.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fs.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fs.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fs.st_mode & S_IROTH) ? "r" : "-");
    printf( (fs.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fs.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");

    printf("The file %s a symbolic link\n", (S_ISLNK(fs.st_mode)) ? "is" : "is not");
    printf("The file %s a hole/leak\n", (fs.st_blksize * fs.st_blocks < fs.st_size) ? "has" : "does not have");
    return 0;
}