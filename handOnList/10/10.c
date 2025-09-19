/*
======================================================================================
Name        : 10
Author      : Mohit Kumar
Description : Open file in read-write mode, write 10 bytes, move file pointer by 10 bytes,
write 10 more bytes, check lseek return value and verify empty spaces.
======================================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    off_t offset;
    char data1[10] = "ABCDEFGHIJ";
    char data2[10] = "1234567890";

    fd = open("file2.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open failed");
        return 1;
    }

    write(fd, data1, 10);

    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("lseek failed");
        close(fd);
        return 1;
    }
    printf("File pointer after lseek: %ld\n", offset);

    write(fd, data2, 10);

    close(fd);
    return 0;
}

/*
======================================================================================
output:mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 10.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 10.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
File pointer after lseek: 20
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ od -c file2.txt
0000000   A   B   C   D   E   F   G   H   I   J   t  \n  \0  \0  \0  \0
0000020  \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0
0000036
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ 


======================================================================================

*/

