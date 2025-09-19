/*
======================================================================================
Name        : record_lock.c
Author      : Mohit Kumar
Description : 18. Write a program to perform Record locking.
              a. Implement write lock
              b. Implement read lock
              Create three records in a file. Whenever you access a particular record,
              first lock it then modify/access to avoid race condition.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd;
    struct flock mylock;
    char buff[50];
    int rec_size = 20; // size of each record (20 bytes)

    // open file
    fd = open("records.txt", O_RDWR);
    if (fd < 0)
    {
        perror("open");
        exit(1);
    }

    int rec_no;
    printf("Enter record number (0,1,2): ");
    scanf("%d", &rec_no);

    // prepare lock
    mylock.l_type = F_WRLCK;      // change this to F_RDLCK for read lock
    mylock.l_whence = SEEK_SET;
    mylock.l_start = rec_no * rec_size; // which record to lock
    mylock.l_len = rec_size;            // length of record

    // set lock
    fcntl(fd, F_SETLKW, &mylock);

    // move file pointer to that record
    lseek(fd, rec_no * rec_size, SEEK_SET);

    // read existing record
    read(fd, buff, rec_size);
    printf("Old Record: %s\n", buff);

    // write new data if write lock
    if (mylock.l_type == F_WRLCK)
    {
        printf("Enter new data: ");
        scanf("%s", buff);

        // move again
        lseek(fd, rec_no * rec_size, SEEK_SET);
        write(fd, buff, strlen(buff));
        printf("Record Updated!\n");
    }

    // unlock
    mylock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &mylock);

    close(fd);
    return 0;
}

/*
======================================================================================
Output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 18.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ echo -n "mohit Record0_data        " > records.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ echo -n "mohit Record1_data        " > records.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ echo -n "mohit Record2_data        " > records.txt
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cc 18.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Enter record number (0,1,2): 1
Old Record:
Enter new data: myfile 1
Record Updated!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Enter record number (0,1,2): 1
Old Record: myfile
Enter new data:
as
Record Updated!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Enter record number (0,1,2): 2
Old Record:
Enter new data: myfile2
Record Updated!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ ./a.out
Enter record number (0,1,2): 0
Old Record: myfile0ecord2_data
Enter new data: my file0
Record Updated!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ cat records.txt
myfile0ecord2_data  asfilemyfile2mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$ vim 18.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list1$

======================================================================================

*/

