/*
======================================================================================
Name        : 23_zombie
Author      : Mohit Kumar
Description : 23. Write a program to create a Zombie state of the running program.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid;
    pid = fork();
    if (pid > 0) {
        sleep(20);
    } else if (pid == 0) {
        exit(0);
    }
    return 0;
}
/*
======================================================================================
output:mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 23.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 23.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    3891    3882  0  80   0 -  2789 do_wai pts/0    00:00:00 bash
0 T  1000    4111    3891  0  80   0 -  6963 do_sig pts/0    00:00:00 vim
4 R  1000    4795    3891  0  80   0 -  3445 -      pts/0    00:00:00 ps
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out &
[2] 4820
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    3891    3882  0  80   0 -  2789 do_wai pts/0    00:00:00 bash
0 T  1000    4111    3891  0  80   0 -  6963 do_sig pts/0    00:00:00 vim
0 S  1000    4820    3891  0  80   0 -   637 hrtime pts/0    00:00:00 a.out
1 Z  1000    4821    4820  0  80   0 -     0 -      pts/0    00:00:00 a.out
4 R  1000    4826    3891 99  80   0 -  3445 -      pts/0    00:00:00 ps
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ps -l
F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    3891    3882  0  80   0 -  2789 do_wai pts/0    00:00:00 bash
0 T  1000    4111    3891  0  80   0 -  6963 do_sig pts/0    00:00:00 vim
4 R  1000    4953    3891  0  80   0 -  3445 -      pts/0    00:00:00 ps
[2]-  Done                    ./a.out

======================================================================================
 */
