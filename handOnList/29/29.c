/*
======================================================================================
Name        : 29
Author      : Mohit Kumar
Description : Program to get current scheduling policy and change it to SCHED_FIFO and
              SCHED_RR using sched_setscheduler()
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main() {
    int policy;
    struct sched_param p;

    policy = sched_getscheduler(0);
    printf("Current Policy: %d\n", policy);

    p.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_FIFO, &p) == -1) {
        perror("sched_setscheduler FIFO");
        exit(1);
    }
    printf("Changed Policy to SCHED_FIFO\n");

    policy = sched_getscheduler(0);
    printf("Now Policy: %d\n", policy);

    p.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_RR, &p) == -1) {
        perror("sched_setscheduler RR");
        exit(1);
    }
    printf("Changed Policy to SCHED_RR\n");

    policy = sched_getscheduler(0);
    printf("Now Policy: %d\n", policy);

    return 0;
}

/*
======================================================================================
Sample Output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 29.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 29.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 29.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Current Policy: 0
sched_setscheduler FIFO: Operation not permitted
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ sudo ./a.out
[sudo] password for mohit-kumar: 
Sorry, try again.
[sudo] password for mohit-kumar: 
Current Policy: 0
Changed Policy to SCHED_FIFO
Now Policy: 1
Changed Policy to SCHED_RR
Now Policy: 2

======================================================================================
*/

