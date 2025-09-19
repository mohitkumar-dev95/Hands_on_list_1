/*
======================================================================================
Name        : 27
Author      : Mohit Kumar
Description : 27. Write a program to execute "ls -Rl" using different exec() family calls
              a. execl
              b. execlp
              c. execle
              d. execv
              e. execvp
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    char *args[] = {"ls", "-Rl", NULL};
    char *envp[] = {NULL};  // custom environment for execle

    // a) execl
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execl:\n");
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // b) execlp
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execlp:\n");
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // c) execle
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execle:\n");
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
        perror("execle failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // d) execv
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execv:\n");
        execv("/bin/ls", args);
        perror("execv failed");
        exit(1);
    } else {
        wait(NULL);
    }

    // e) execvp
    pid = fork();
    if (pid == 0) {
        printf("\nUsing execvp:\n");
        execvp("ls", args);
        perror("execvp failed");
        exit(1);
    } else {
        wait(NULL);
    }

    return 0;
}

/*
======================================================================================
output:
.:
total 292
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1690 Aug 22 15:29 10.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1928 Aug 22 15:47 11.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1609 Aug 22 15:57 12.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1865 Aug 22 16:12 13.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2702 Aug 22 17:57 14.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  4419 Aug 22 18:03 15.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2017 Aug 23 13:42 16a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1483 Aug 23 13:46 16b.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  3429 Aug 23 14:19 18.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1308 Aug 23 14:28 19.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1879 Aug 23 14:36 20.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1263 Aug 23 17:29 21.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1320 Aug 23 17:48 22a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2299 Aug 23 17:57 23.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1278 Aug 23 18:11 24.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1811 Aug 26 14:53 25.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1295 Aug 28 14:11 26.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1953 Sep  2 14:08 27.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1757 Aug 21 20:01 7.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1334 Aug 22 15:10 8.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1898 Aug 22 15:20 9.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16384 Sep  2 14:08 a.out
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1074 Aug 21 19:15 create_file.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 26 15:13 exec
-rw-rw-r-- 1 mohit-kumar mohit-kumar    56 Aug 22 15:09 file1.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar    46 Aug 23 17:47 file22.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar    30 Aug 22 15:27 file2.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar   190 Aug 22 15:56 file3.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar     0 Aug 22 15:56 file4.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Sep  2 14:18 file.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1950 Aug 21 19:45 fivefiles.c
-rw-rw-r-- 2 mohit-kumar mohit-kumar    12 Aug 21 18:48 hardlink.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 15960 Aug 28 14:09 hello
-rw-rw-r-- 1 mohit-kumar mohit-kumar   106 Aug 28 14:07 hello.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2011 Aug 21 19:03 infinite.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 28 14:09 main
prw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 18:15 myfifo
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 19:24 newfile.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1443 Aug 21 19:26 openfile.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16168 Aug 23 18:06 orphan
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 23 14:34 p
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 readlock
-rw-rw-r-- 1 mohit-kumar mohit-kumar    47 Aug 23 14:26 records.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1111 Aug 21 19:51 rwstdio.c
lrwxrwxrwx 1 mohit-kumar mohit-kumar     9 Aug 21 18:37 soft_link -> hello.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 17 14:42 softlink
-rw-r-Sr-- 1 mohit-kumar mohit-kumar     0 Aug 22 19:56 test.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2513 Aug 23 13:59 ticketbook.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar   806 Aug 23 13:57 ticketno.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar     4 Aug 23 13:58 ticket.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 writelock
.:
total 296
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1690 Aug 22 15:29 10.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1928 Aug 22 15:47 11.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1609 Aug 22 15:57 12.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1865 Aug 22 16:12 13.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2702 Aug 22 17:57 14.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  4419 Aug 22 18:03 15.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2017 Aug 23 13:42 16a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1483 Aug 23 13:46 16b.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  3429 Aug 23 14:19 18.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1308 Aug 23 14:28 19.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1879 Aug 23 14:36 20.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1263 Aug 23 17:29 21.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1320 Aug 23 17:48 22a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2299 Aug 23 17:57 23.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1278 Aug 23 18:11 24.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1811 Aug 26 14:53 25.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1295 Aug 28 14:11 26.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1953 Sep  2 14:08 27.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1757 Aug 21 20:01 7.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1334 Aug 22 15:10 8.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1898 Aug 22 15:20 9.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16384 Sep  2 14:08 a.out
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1074 Aug 21 19:15 create_file.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 26 15:13 exec
-rw-rw-r-- 1 mohit-kumar mohit-kumar    56 Aug 22 15:09 file1.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar    46 Aug 23 17:47 file22.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar    30 Aug 22 15:27 file2.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar   190 Aug 22 15:56 file3.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar     0 Aug 22 15:56 file4.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  3270 Sep  2 14:18 file.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1950 Aug 21 19:45 fivefiles.c
-rw-rw-r-- 2 mohit-kumar mohit-kumar    12 Aug 21 18:48 hardlink.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 15960 Aug 28 14:09 hello
-rw-rw-r-- 1 mohit-kumar mohit-kumar   106 Aug 28 14:07 hello.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2011 Aug 21 19:03 infinite.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 28 14:09 main
prw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 18:15 myfifo
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 19:24 newfile.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1443 Aug 21 19:26 openfile.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16168 Aug 23 18:06 orphan
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 23 14:34 p
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 readlock
-rw-rw-r-- 1 mohit-kumar mohit-kumar    47 Aug 23 14:26 records.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1111 Aug 21 19:51 rwstdio.c
lrwxrwxrwx 1 mohit-kumar mohit-kumar     9 Aug 21 18:37 soft_link -> hello.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 17 14:42 softlink
-rw-r-Sr-- 1 mohit-kumar mohit-kumar     0 Aug 22 19:56 test.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2513 Aug 23 13:59 ticketbook.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar   806 Aug 23 13:57 ticketno.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar     4 Aug 23 13:58 ticket.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 writelock
.:
total 300
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1690 Aug 22 15:29 10.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1928 Aug 22 15:47 11.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1609 Aug 22 15:57 12.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1865 Aug 22 16:12 13.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2702 Aug 22 17:57 14.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  4419 Aug 22 18:03 15.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2017 Aug 23 13:42 16a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1483 Aug 23 13:46 16b.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  3429 Aug 23 14:19 18.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1308 Aug 23 14:28 19.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1879 Aug 23 14:36 20.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1263 Aug 23 17:29 21.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1320 Aug 23 17:48 22a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2299 Aug 23 17:57 23.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1278 Aug 23 18:11 24.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1811 Aug 26 14:53 25.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1295 Aug 28 14:11 26.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1953 Sep  2 14:08 27.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1757 Aug 21 20:01 7.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1334 Aug 22 15:10 8.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1898 Aug 22 15:20 9.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16384 Sep  2 14:08 a.out
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1074 Aug 21 19:15 create_file.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 26 15:13 exec
-rw-rw-r-- 1 mohit-kumar mohit-kumar  6540 Sep  2 14:18 file.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar    56 Aug 22 15:09 file1.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar    30 Aug 22 15:27 file2.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar    46 Aug 23 17:47 file22.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar   190 Aug 22 15:56 file3.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar     0 Aug 22 15:56 file4.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1950 Aug 21 19:45 fivefiles.c
-rw-rw-r-- 2 mohit-kumar mohit-kumar    12 Aug 21 18:48 hardlink.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 15960 Aug 28 14:09 hello
-rw-rw-r-- 1 mohit-kumar mohit-kumar   106 Aug 28 14:07 hello.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2011 Aug 21 19:03 infinite.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 28 14:09 main
prw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 18:15 myfifo
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 19:24 newfile.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1443 Aug 21 19:26 openfile.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16168 Aug 23 18:06 orphan
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 23 14:34 p
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 readlock
-rw-rw-r-- 1 mohit-kumar mohit-kumar    47 Aug 23 14:26 records.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1111 Aug 21 19:51 rwstdio.c
lrwxrwxrwx 1 mohit-kumar mohit-kumar     9 Aug 21 18:37 soft_link -> hello.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 17 14:42 softlink
-rw-r-Sr-- 1 mohit-kumar mohit-kumar     0 Aug 22 19:56 test.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar     4 Aug 23 13:58 ticket.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2513 Aug 23 13:59 ticketbook.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar   806 Aug 23 13:57 ticketno.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 writelock
.:
total 304
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1690 Aug 22 15:29 10.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1928 Aug 22 15:47 11.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1609 Aug 22 15:57 12.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1865 Aug 22 16:12 13.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2702 Aug 22 17:57 14.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  4419 Aug 22 18:03 15.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2017 Aug 23 13:42 16a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1483 Aug 23 13:46 16b.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  3429 Aug 23 14:19 18.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1308 Aug 23 14:28 19.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1879 Aug 23 14:36 20.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1263 Aug 23 17:29 21.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1320 Aug 23 17:48 22a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2299 Aug 23 17:57 23.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1278 Aug 23 18:11 24.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1811 Aug 26 14:53 25.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1295 Aug 28 14:11 26.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1953 Sep  2 14:08 27.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1757 Aug 21 20:01 7.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1334 Aug 22 15:10 8.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1898 Aug 22 15:20 9.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16384 Sep  2 14:08 a.out
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1074 Aug 21 19:15 create_file.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 26 15:13 exec
-rw-rw-r-- 1 mohit-kumar mohit-kumar    56 Aug 22 15:09 file1.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar    46 Aug 23 17:47 file22.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar    30 Aug 22 15:27 file2.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar   190 Aug 22 15:56 file3.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar     0 Aug 22 15:56 file4.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  9810 Sep  2 14:18 file.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1950 Aug 21 19:45 fivefiles.c
-rw-rw-r-- 2 mohit-kumar mohit-kumar    12 Aug 21 18:48 hardlink.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 15960 Aug 28 14:09 hello
-rw-rw-r-- 1 mohit-kumar mohit-kumar   106 Aug 28 14:07 hello.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2011 Aug 21 19:03 infinite.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 28 14:09 main
prw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 18:15 myfifo
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 19:24 newfile.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1443 Aug 21 19:26 openfile.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16168 Aug 23 18:06 orphan
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 23 14:34 p
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 readlock
-rw-rw-r-- 1 mohit-kumar mohit-kumar    47 Aug 23 14:26 records.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1111 Aug 21 19:51 rwstdio.c
lrwxrwxrwx 1 mohit-kumar mohit-kumar     9 Aug 21 18:37 soft_link -> hello.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 17 14:42 softlink
-rw-r-Sr-- 1 mohit-kumar mohit-kumar     0 Aug 22 19:56 test.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2513 Aug 23 13:59 ticketbook.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar   806 Aug 23 13:57 ticketno.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar     4 Aug 23 13:58 ticket.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 writelock
.:
total 308
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1690 Aug 22 15:29 10.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1928 Aug 22 15:47 11.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1609 Aug 22 15:57 12.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1865 Aug 22 16:12 13.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2702 Aug 22 17:57 14.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  4419 Aug 22 18:03 15.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2017 Aug 23 13:42 16a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1483 Aug 23 13:46 16b.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  3429 Aug 23 14:19 18.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1308 Aug 23 14:28 19.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1879 Aug 23 14:36 20.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1263 Aug 23 17:29 21.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1320 Aug 23 17:48 22a.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2299 Aug 23 17:57 23.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1278 Aug 23 18:11 24.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1811 Aug 26 14:53 25.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1295 Aug 28 14:11 26.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1953 Sep  2 14:08 27.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1757 Aug 21 20:01 7.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1334 Aug 22 15:10 8.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1898 Aug 22 15:20 9.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16384 Sep  2 14:08 a.out
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1074 Aug 21 19:15 create_file.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 26 15:13 exec
-rw-rw-r-- 1 mohit-kumar mohit-kumar    56 Aug 22 15:09 file1.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar    46 Aug 23 17:47 file22.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar    30 Aug 22 15:27 file2.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar   190 Aug 22 15:56 file3.txt
-rw-r--r-- 1 mohit-kumar mohit-kumar     0 Aug 22 15:56 file4.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar 13080 Sep  2 14:18 file.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1950 Aug 21 19:45 fivefiles.c
-rw-rw-r-- 2 mohit-kumar mohit-kumar    12 Aug 21 18:48 hardlink.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 15960 Aug 28 14:09 hello
-rw-rw-r-- 1 mohit-kumar mohit-kumar   106 Aug 28 14:07 hello.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2011 Aug 21 19:03 infinite.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16000 Aug 28 14:09 main
prw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 18:15 myfifo
-rw-rw-r-- 1 mohit-kumar mohit-kumar     0 Aug 21 19:24 newfile.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1443 Aug 21 19:26 openfile.c
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16168 Aug 23 18:06 orphan
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 23 14:34 p
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 readlock
-rw-rw-r-- 1 mohit-kumar mohit-kumar    47 Aug 23 14:26 records.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  1111 Aug 21 19:51 rwstdio.c
lrwxrwxrwx 1 mohit-kumar mohit-kumar     9 Aug 21 18:37 soft_link -> hello.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16048 Aug 17 14:42 softlink
-rw-r-Sr-- 1 mohit-kumar mohit-kumar     0 Aug 22 19:56 test.txt
-rw-rw-r-- 1 mohit-kumar mohit-kumar  2513 Aug 23 13:59 ticketbook.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar   806 Aug 23 13:57 ticketno.c
-rw-rw-r-- 1 mohit-kumar mohit-kumar     4 Aug 23 13:58 ticket.txt
-rwxrwxr-x 1 mohit-kumar mohit-kumar 16224 Aug 23 13:39 writelock
======================================================================================
*/

