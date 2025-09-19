/*
======================================================================================
Name        : 9
Author      : Mohit Kumar
Description : Display inode, hard links, uid, gid, size, block size, number of blocks,
              last access, modification, and change time of a file in simple format.
======================================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat f;

    if (stat("file1.txt", &f) < 0) {
        perror("stat failed");
        return 1;
    }

    printf("Inode: %lu\n", f.st_ino);
    printf("Hard links: %lu\n", f.st_nlink);
    printf("User ID: %u\n", f.st_uid);
    printf("Group ID: %u\n", f.st_gid);
    printf("Size: %ld bytes\n", f.st_size);
    printf("Block size: %ld\n", f.st_blksize);
    printf("Number of blocks: %ld\n", f.st_blocks);
    printf("Last access: %s", ctime(&f.st_atime));
    printf("Last modification: %s", ctime(&f.st_mtime));
    printf("Last change: %s", ctime(&f.st_ctime));

    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 9.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 9.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Inode: 10785710
Hard links: 1
User ID: 1000
Group ID: 1000
Size: 56 bytes
Block size: 4096
Number of blocks: 8
Last access: Fri Aug 22 15:09:44 2025
Last modification: Fri Aug 22 15:09:26 2025
Last change: Fri Aug 22 15:09:26 2025
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ls -l 9.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar 1253 Aug 22 15:19 9.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$


======================================================================================

*/

