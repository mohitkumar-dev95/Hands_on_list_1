/*
======================================================================================
Name        : 21
Author      : Mohit Kumar
Description : 21. Write a program, call fork and print the parent and child process id.
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    int pid;

    pid = fork();   // create a child 

    if (pid < 0) {
        // fork fail
        printf("Fork failed!\n");
    } 
    else if (pid == 0) {
        //  child
        printf("I am child, my id is %d, my parent id is %d\n", getpid(), getppid());
    } 
    else {
        // parent 
        printf("I am parent, my id is %d, my child id is %d\n", getpid(), pid);
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 21.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
I am parent, my id is 3937, my child id is 3938
I am child, my id is 3938, my parent id is 3937
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$
======================================================================================

*/
