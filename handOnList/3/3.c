/*
======================================================================================
Name        : 3
Author      : Mohit Kumar
Description : 
    Write a program to create a file and print the file descriptor value. 
    Use creat() system call.
======================================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = creat("test.txt", 0666);

    if (fd == -1) {
        printf("Error creating file\n");
    } else {
        printf("File descriptor value: %d\n", fd);
        close(fd);
    }

    return 0;
}
/*
===================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
File descriptor value: 3
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -l test.txt
-rwxr-xr-x 1 mohit-kumar mohit-kumar 0 Aug 21 19:14 test.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ 



==================================================================
*/
