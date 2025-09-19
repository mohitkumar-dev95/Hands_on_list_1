/*
======================================================================================
Name        : 26
Author      : Mohit Kumar
Description : 26. Write a program to execute an executable program.
              a. use some executable program
              b. pass some input to an executable program.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *prog = "./hello";   
    char *name = "Mohit";  

    execl(prog, prog, name, NULL);

    printf("this will not print if execl is successful\n");

    return 0;
}

/*
======================================================================================

output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim hello.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 26.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 26.c -o main
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc hello.c -o hello
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./main
Hello Mohit
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$


======================================================================================
*/

