/*
======================================================================================
Name        : 6
Author      : Mohit Kumar
Description : Write a program to take input from STDIN and display it on STDOUT.  
    Use only read() and write() system calls.
======================================================================================
*/

#include <unistd.h>

int main() {
    char buffer[100];
    int n;

    // read from STDIN (file descriptor 0)
    n = read(0, buffer, sizeof(buffer));

    // write to STDOUT (file descriptor 1)
    write(1, buffer, n);

    return 0;
}

/*
======================================================================================
Output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim rwstdio.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc rwstdio.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
hello mohit r u ok
hello mohit r u ok
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$


======================================================================================
*/

