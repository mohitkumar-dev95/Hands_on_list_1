/*
======================================================================================
Name        : 12
Author      : Mohit Kumar
Description : Find out the opening mode of a file using fcntl.
======================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    int flags;

    // Open file in read-write mode
    fd = open("file4.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    // Get file status flags using fcntl
    flags = fcntl(fd, F_GETFL);
    if (flags < 0) {
        perror("fcntl failed");
        close(fd);
        return 1;
    }

    // Determine opening mode
    switch (flags & O_ACCMODE) {
        case O_RDONLY:
            printf("File is opened in read-only mode\n");
            break;
        case O_WRONLY:
            printf("File is opened in write-only mode\n");
            break;
        case O_RDWR:
            printf("File is opened in read-write mode\n");
            break;
        default:
            printf("Unknown mode\n");
    }

    close(fd);
    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 12.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
File is opened in read-write mode
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$

======================================================================================

*/

