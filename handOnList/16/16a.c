/*
======================================================================================
Name        : 16a
Author      : Mohit Kumar
Description : Program to perform mandatory locking (Write Lock).
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    struct flock lock;

    fd = open("test.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire write lock...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        return 1;
    }

    printf("Write lock acquired. Press Enter to release...\n");
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released.\n");
    close(fd);

    return 0;
}

/*
======================================================================================
output:
TERMINAL1:
ohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list1/
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 16.c -o writelock
cc1: fatal error: 16.c: No such file or directory
compilation terminated.
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 16a.c -o writelock
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 16b.c -o readlock
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./writelock
Trying to acquire write lock...
Write lock acquired. Press Enter to release...
t
Lock released.
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$

TERMINAL2:mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list1/
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./writelock
Trying to acquire write lock...
Write lock acquired. Press Enter to release...


======================================================================================

*/

