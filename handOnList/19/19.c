/*
======================================================================================
Name        : 19
Author      : Mohit Kumar
Description : 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    unsigned int a, b, c, d;
    unsigned long long start, end, diff;
    int id;

    asm volatile("rdtsc" : "=a"(a), "=d"(b));
    start = ((unsigned long long)b << 32) | a;

    id = getpid();

    asm volatile("rdtsc" : "=a"(c), "=d"(d));
    end = ((unsigned long long)d << 32) | c;

    diff = end - start;

    printf("id is: %d\n", id);
    printf("time taken: %llu cycles\n", diff);

    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 19.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 19.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
id is: 4908
time taken: 12660 cycles
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$


======================================================================================

*/
