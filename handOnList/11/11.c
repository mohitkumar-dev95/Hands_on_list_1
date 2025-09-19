/*
======================================================================================
Name        : 11
Author      : Mohit Kumar
Description : Open a file, duplicate the file descriptor using dup, dup2, and fcntl.
Append data using both descriptors and check whether file is updated properly.
======================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2, fd3;
    char data1[] = "Hello this is simple Dup\n";
    char data2[] = "Hello this is using Dup2\n";
    char data3[] = "Hello this is Fcntl\n";

    // Open file in append mode
    fd1 = open("file3.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd1 < 0) {
        perror("open failed");
        return 1;
    }

    // Duplicate using dup()
    fd2 = dup(fd1);
    if (fd2 < 0) {
        perror("dup failed");
        close(fd1);
        return 1;
    }

    // Duplicate using dup2() (fd3 will be 10)
    fd3 = 10;
    if (dup2(fd1, fd3) < 0) {
        perror("dup2 failed");
        close(fd1);
        close(fd2);
        return 1;
    }

    // Duplicate using fcntl()
    int fd4 = fcntl(fd1, F_DUPFD, 0);
    if (fd4 < 0) {
        perror("fcntl failed");
        close(fd1);
        close(fd2);
        close(fd3);
        return 1;
    }

    // Write using original fd
    write(fd1, data1, sizeof(data1) - 1);

    // Write using fd2 (dup)
    write(fd2, data2, sizeof(data2) - 1);

    // Write using fd3 (dup2)
    write(fd3, data1, sizeof(data1) - 1);

    // Write using fd4 (fcntl)
    write(fd4, data3, sizeof(data3) - 1);

    // Close all descriptors
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);

    return 0;
}

/*
======================================================================================
output:
======================================================================================

*/

