/*
======================================================================================
Name        : 16b
Author      : Mohit Kumar
Description : Program to perform mandatory locking (Read Lock).
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

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    printf("Trying to acquire read lock...\n");
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        return 1;
    }

    printf("Read lock acquired. Press Enter to release...\n");
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
terminal1:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./readlock
Trying to acquire read lock...
Read lock acquired. Press Enter to release...


terminal2:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./writelock
Trying to acquire write lock...
Write lock acquired. Press Enter to release...
l
Lock released.

======================================================================================

*/

