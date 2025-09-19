/*
======================================================================================
Name        : 30
Author      : Mohit Kumar
Description : 30. Write a program to run a script at a specific time using a Daemon process
======================================================================================
*/

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    if(!fork()) {
        setsid();
        chdir("/");
        umask(0);

        while(1) {
            time_t t;
            struct tm *ti;
            t = time(NULL);
            ti = localtime(&t);

            if(ti->tm_hour == 14 && ti->tm_min == 20) {
                system("myscript.sh");
                sleep(60);
            }
            sleep(1);
        }
    }
    else    
        exit(0);
    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ nano myscript.sh
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ chmod +x myscript.sh
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./myscript.sh
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 30.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 30.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./myscript.sh
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cat output.txt
Script ran at Thu Sep  4 02:19:10 PM IST 2025
Script ran at Thu Sep  4 02:20:44 PM IST 2025
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 30.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 30.c -o daemon_prog
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./daemon_prog &
[1] 3766
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cat output.txt
Script ran at Thu Sep  4 02:19:10 PM IST 2025
Script ran at Thu Sep  4 02:20:44 PM IST 2025
[1]+  Done                    ./daemon_prog
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ nano myscript.sh
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cat output.txt
Script ran at Thu Sep  4 02:19:10 PM IST 2025
Script ran at Thu Sep  4 02:20:44 PM IST 2025
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$

======================================================================================
*/

