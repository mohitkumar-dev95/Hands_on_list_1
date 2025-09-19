/*
======================================================================================
Name        : 4
Author      : Mohit Kumar
Description : 
    Write a program to open an existing file with read and write mode. 
    Try using the O_EXCL flag also.
======================================================================================
*/


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd;
    fd = open("newfile.txt", O_RDWR | O_CREAT | O_EXCL, 0666);
    if (fd == -1) {
        perror("open with O_EXCL failed");
        return 1;
    }
    printf("File created exclusively with fd with O_EXCL: %d\n", fd);
    close(fd);

    return 0;
}

/*
=========================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc openfile.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
open with O_EXCL failed: File exists
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -l newfile.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar 0 Aug 17 16:42 newfile.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ rm newfile.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
File created exclusively with fd with O_EXCL: 3
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$

=========================================================================
*/
