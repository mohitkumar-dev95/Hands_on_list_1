/*
======================================================================================
Name        : 25
Author      : Mohit Kumar
Description : 25. Write a program to create three child processes. 
              The parent should wait for a particular child (use waitpid system call).
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int c1, c2, c3;
    int st, w;

    c1 = fork();
    if (c1 == 0) {
        printf("i am child1 pid=%d ppid=%d\n", getpid(), getppid());
        exit(1);
    }

    c2 = fork();
    if (c2 == 0) {
        printf("i am child2 pid=%d ppid=%d\n", getpid(), getppid());
        exit(2);
    }

    c3 = fork();
    if (c3 == 0) {
        printf("i am child3 pid=%d ppid=%d\n", getpid(), getppid());
        exit(3);
    }

    printf("i am parent pid=%d\n", getpid());

    w = waitpid(c2, &st, 0);

    if (WIFEXITED(st)) {
        printf("parent waited for child2 pid=%d exitstatus=%d\n", w, WEXITSTATUS(st));
    }

    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list1/
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 25.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 25.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
i am child1 pid=4204 ppid=4203
i am parent pid=4203
i am child2 pid=4205 ppid=4203
i am child3 pid=4206 ppid=4203
parent waited for child2 pid=4205 exitstatus=2
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ 

======================================================================================
*/

