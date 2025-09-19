/*
======================================================================================
Name:1.c
Author:MOHIT KUMAR
Description:Create the following types of a files using system call FIFO (mkfifo Library Function or mknod system call
=======================================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int status = mkfifo("myfifo", 0666);
    if (status == 0)
        printf("FIFO created successfully!\n");
    else
        printf("Failed to create FIFO\n");
    return 0;
}

/*
=======================================================================================
OUTPUT:
====================================================================================== 
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ rm myfifo
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc fifo.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
FIFO created successfully!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -l fifo
ls: cannot access 'fifo': No such file or directory
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -l fifo.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar 257 Aug 21 17:56 fifo.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$
====================================================================================== 
*/

