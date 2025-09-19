/*
======================================================================================
Name        : 7
Author      : Mohit Kumar
Description : 
    Write a program to copy the contents of file1 into file2. 
    (Equivalent to the shell command: $ cp file1 file2)
======================================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd1, fd2;
    char buffer[1024];
    int n;

    // Open file1 for reading
    fd1 = open("file1.txt", O_RDONLY);
    if (fd1 < 0) {
        perror("open file1");
        return 1;
    }

    // Create or open file2 for writing
    fd2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd2 < 0) {
        perror("open file2");
        close(fd1);
        return 1;
    }

    // Read from file1 and write to file2
    while ((n = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, n);
    }

    printf("File copied: file1.txt -> file2.txt\n");

    close(fd1);
    close(fd2);
    return 0;
}

/*
======================================================================================
Output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 7.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ echo "Hello Mohit" > file1.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 7.c 
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
File copied: file1.txt -> file2.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cat file2.txt
Hello Mohit
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ 

======================================================================================
*/

