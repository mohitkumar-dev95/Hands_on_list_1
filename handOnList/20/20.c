/*
======================================================================================
Name        : 20
Author      : Mohit Kumar
Description : 20. Find out the priority of your running program. Modify the priority with nice command.
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int myid;
    int myprio;

    // get my process id
    myid = getpid();

    // get my priority
    myprio = getpriority(PRIO_PROCESS, myid);

    printf("My process id is: %d\n", myid);
    printf("My current priority is: %d\n", myprio);

    return 0;
}

/*
======================================================================================
OUTPUT:mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 20.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 20.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
My process id is: 5035
My current priority is: 0
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ nice -n ./a.out
nice: invalid adjustment ‘./a.out’
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
My process id is: 5038
My current priority is: 0
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 20.c -o p
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ nice -n 10 ./p
My process id is: 5068
My current priority is: 10
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ nice -n 5 ./p
My process id is: 5073
My current priority is: 5
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./p
My process id is: 5074
My current priority is: 0
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ 

======================================================================================
*/

