/*
======================================================================================
Name        : 13
Author      : Mohit Kumar
Description : Wait for input on STDIN for 10 seconds using select and check if data is available.
======================================================================================
*/

#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
    fd_set fds;
    struct timeval t;
    int ret;

    FD_ZERO(&fds);
    FD_SET(0, &fds);   // STDIN

    t.tv_sec = 10;
    t.tv_usec = 0;

    printf("Waiting for input for 10 seconds...\n");

    ret = select(1, &fds, NULL, NULL, &t);

    if (ret == 0) {
        printf("No input within 10 seconds.\n");
    } else if (ret > 0) {
        printf("Input is available.\n");
    } else {
        printf("select error\n");
    }

    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 13.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 13.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Waiting for input for 10 seconds...
hello mohit
Input is available.
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ hello mohit
Command 'hello' not found, but can be installed with:
sudo snap install hello              # version 2.10, or
sudo apt  install hello              # version 2.10-3
sudo apt  install hello-traditional  # version 2.10-6
See 'snap info hello' for additional versions.
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Waiting for input for 10 seconds...
No input within 10 seconds.
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$


======================================================================================

*/

