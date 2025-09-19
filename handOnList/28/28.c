/*
======================================================================================
Name        : 28_realtime_priority
Author      : Mohit Kumar
Description : 28. Write a program to get maximum and minimum real time priority.
======================================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int minFIFO, maxFIFO;
    int minRR, maxRR;
    minFIFO = sched_get_priority_min(SCHED_FIFO);
    maxFIFO = sched_get_priority_max(SCHED_FIFO);
    minRR = sched_get_priority_min(SCHED_RR);
    maxRR = sched_get_priority_max(SCHED_RR);
    printf("Real-time priorities in Linux:\n");
    printf("\nSCHED_FIFO:\n");
    printf("  Minimum Priority = %d\n", minFIFO);
    printf("  Maximum Priority = %d\n", maxFIFO);
    printf("\nSCHED_RR:\n");
    printf("  Minimum Priority = %d\n", minRR);
    printf("  Maximum Priority = %d\n", maxRR);

    return 0;
}

/*
======================================================================================
Output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 28.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 28.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Real-time priorities in Linux:

SCHED_FIFO:
  Minimum Priority = 1
  Maximum Priority = 99

SCHED_RR:
  Minimum Priority = 1
  Maximum Priority = 99

======================================================================================
*/

