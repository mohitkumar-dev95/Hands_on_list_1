/*
======================================================================================
Name        : 5
Author      : Mohit Kumar
Description : 
    Write a program to create five new files with an infinite loop. 
    Execute the program in the background and check the file descriptor 
    table at /proc/<pid>/fd.
======================================================================================
*/

#include <fcntl.h>
#include <unistd.h>

int main() {
    creat("file1.txt", 0666);
    creat("file2.txt", 0666);
    creat("file3.txt", 0666);
    creat("file4.txt", 0666);
    creat("file5.txt", 0666);
    while(1){
	    sleep(2);
    }
    return 0;
}
/*
======================================================================================
Output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list1/
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc fivefiles.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out &
[1] 8258
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -l /proc/8258/fd
total 0
lrwx------ 1 mohit-kumar mohit-kumar 64 Aug 21 19:44 0 -> /dev/pts/1
lrwx------ 1 mohit-kumar mohit-kumar 64 Aug 21 19:44 1 -> /dev/pts/1
lrwx------ 1 mohit-kumar mohit-kumar 64 Aug 21 19:44 2 -> /dev/pts/1
l-wx------ 1 mohit-kumar mohit-kumar 64 Aug 21 19:44 3 -> /home/mohit-kumar/Hands_on_list1/file1.txt
l-wx------ 1 mohit-kumar mohit-kumar 64 Aug 21 19:44 4 -> /home/mohit-kumar/Hands_on_list1/file2.txt
l-wx------ 1 mohit-kumar mohit-kumar 64 Aug 21 19:44 5 -> /home/mohit-kumar/Hands_on_list1/file3.txt
l-wx------ 1 mohit-kumar mohit-kumar 64 Aug 21 19:44 6 -> /home/mohit-kumar/Hands_on_list1/file4.txt
l-wx------ 1 mohit-kumar mohit-kumar 64 Aug 21 19:44 7 -> /home/mohit-kumar/Hands_on_list1/file5.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$

======================================================================================
*/
