/*
======================================================================================
Name        : 17
Author      : Mohit Kumar
Description : Open ticket.txt, lock for writing, read ticket number, increment and save it.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    struct flock lock;
    FILE *f;
    int ticket = 0;

    fd = open("ticket.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl (lock)");
        close(fd);
        return 1;
    }

    f = fdopen(fd, "r+");
    if (f == NULL) {
        perror("fdopen");
        lock.l_type = F_UNLCK;
        fcntl(fd, F_SETLK, &lock);
        close(fd);
        return 1;
    }

    if (fscanf(f, "%d", &ticket) != 1) {
        ticket = 0;
    }

    ticket++;

    if (ftruncate(fd, 0) == -1) {
        perror("ftruncate");
        // proceed anyway
    }
    rewind(f);

    fprintf(f, "%d\n", ticket);
    fflush(f);

    printf("Your ticket number is %d\n", ticket);

    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl (unlock)");
    }

    fclose(f); // closes fd as well

    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim ticketno.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim ticketbook.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc ticketno.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Ticket file initialized with 100
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc ticketbook.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Your ticket number is 101
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Your ticket number is 102
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Your ticket number is 103
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Your ticket number is 104
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$


======================================================================================

*/

