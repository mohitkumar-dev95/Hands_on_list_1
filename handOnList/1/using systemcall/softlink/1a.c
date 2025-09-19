/*
======================================================================================
Name   : 1.a
Author : MOHIT KUMAR
Description: Create the following types of a files using system call Soft Link (symlink)
======================================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    int status = symlink("hello.txt", "soft_link");
    if (status == 0)
        printf("Soft link created successfully!\n");
    else
        perror("Failed to create soft link");
    return 0;
}

/*
======================================================================================
OUTPUT:

mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim softlink.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc softlink.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Soft link created successfully!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -l softlink.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar 745 Aug 21 18:36 softlink.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -l
total 56
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 21 18:37 a.out
-rw-rw-r-- 1 mohit-kumar mohit-kumar   279 Aug 17 16:10 create_file.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 18 18:51 file1.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 18 18:51 file2.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 18 18:51 file3.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 18 18:51 file4.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 18 18:51 file5.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar   222 Aug 17 15:02 hardlink.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar    20 Aug 17 14:47 hardlink.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar   143 Aug 17 15:44 infinite.c
prw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 18:15 myfifo
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 17 16:42 newfile.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar   336 Aug 17 16:34 openfile.c
lrwxrwxrwx 1 mohit-kumar mohit-kumar     9 Aug 21 18:37 soft_link -> hello.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 17 14:42 softlink
-rw-rw-r-- 1 mohit-kumar mohit-kumar   745 Aug 21 18:36 softlink.c
-rwxr-xr-x 1 mohit-kumar mohit-kumar     0 Aug 17 16:11 test.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$


====================================================================================== 
*/

