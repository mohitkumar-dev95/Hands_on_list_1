/*
======================================================================================
Name        : 24_orphan
Author      : Mohit Kumar
Description : 24. Write a program to create an orphan process.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid;
    pid = fork();
    if (pid > 0) {
        exit(0);
    } else if (pid == 0) {
        sleep(20);
        printf("i am child my pid is %d my ppid is %d\n", getpid(), getppid());
    }
    return 0;
}
/*
==========================================================================================
OUTPUT:mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 24.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 24.c -o orphan
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./orphan
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ps -ef | grep orphan
mohit-k+    5963    2007  0 18:06 pts/0    00:00:00 ./orphan
mohit-k+    5967    3891  0 18:06 pts/0    00:00:00 grep --color=auto orphan
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~
===========================================================================================
 */
