/*
======================================================================================
Name        : 14
Author      : Mohit Kumar
Description : Take file name from command line and identify its type.
======================================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    struct stat f;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if (stat(argv[1], &f) < 0) {
        perror("stat failed");
        return 1;
    }

    if (S_ISREG(f.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(f.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(f.st_mode))
        printf("Character device file\n");
    else if (S_ISBLK(f.st_mode))
        printf("Block device file\n");
    else if (S_ISFIFO(f.st_mode))
        printf("FIFO/pipe\n");
    else if (S_ISLNK(f.st_mode))
        printf("Symbolic link\n");
    else if (S_ISSOCK(f.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    return 0;
}

/*
======================================================================================
output:
ohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 14.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls
10.c  12.c  14.c  8.c  a.out          file1.txt  file3.txt  fivefiles.c   hello.txt   myfifo       openfile.c  soft_link  test.txt
11.c  13.c  7.c   9.c  create_file.c  file2.txt  file4.txt  hardlink.txt  infinite.c  newfile.txt  rwstdio.c   softlink
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 14.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out file1.txt
Regular file
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out myfifo
FIFO/pipe
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out hardlink.txt
Regular file
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out a.out
Regular file
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out 10.c
Regular file
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out soft_link
Regular file
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out Hands_on_list1
stat failed: No such file or directory
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out softlink
Regular file
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 14.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ 


======================================================================================

*/

