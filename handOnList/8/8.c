/*
======================================================================================
Name        : 8
Author      : Mohit Kumar
Description : Open a file in read-only mode, read line by line and display each line.
Close the file when end of file is reached.
======================================================================================
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd;
    char ch;

    fd = open("file1.txt", O_RDONLY);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    while (read(fd, &ch, 1) > 0) {
        write(1, &ch, 1);
    }

    close(fd);
    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list1/
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 8.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim file1.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 8.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Hello Mohit
welcome to iiib
you are welcome
keep going
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$

======================================================================================

*/

