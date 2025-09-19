/*
======================================================================================
Name   : 1.c
Author : MOHIT KUMAR
Description: Create the following types of a files using system call Hard Link (link)
======================================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    int status = link("hello.txt", "hardlink.txt");
    if (status == 0) {
        printf("Hard link created: hardlink.txt -> hello.txt\n");
    } else {
        perror("Hard Link failed");
    }
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc hardlink.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Hard link created: hardlink.txt -> hello.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -li hello.txt hardlink.txt
10756025 -rw-rw-r-- 2 mohit-kumar mohit-kumar 12 Aug 21 18:48 hardlink.txt
10756025 -rw-rw-r-- 2 mohit-kumar mohit-kumar 12 Aug 21 18:48 hello.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$


====================================================================================== 
*/


