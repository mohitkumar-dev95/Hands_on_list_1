/*
======================================================================================
Name        : 22
Author      : Mohit Kumar
Description : 22. Write a program, open a file, call fork, and then write to the file by both the 
              child as well as the parent processes. Check output of the file.
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int f;
    int p;

    f = open("file22.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (f < 0) {
        printf("error\n");
        return 1;
    }

    p = fork();

    if (p == 0) {
        write(f, "child here\n", 11);
    } else {
        write(f, "parent here\n", 12);
    }

    close(f);
    return 0;
}

/*
======================================================================================
output:mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 22a.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cat file22.txt
parent here
child here
parent here
child here
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ 


======================================================================================
*/

