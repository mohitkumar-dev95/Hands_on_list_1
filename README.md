# Hands_on_list_1
This lab focuses on Linux File and Process Management using system calls in C. It covers file creation, descriptors, metadata, locking, and I/O, along with process creation, execution, scheduling, zombies, orphans, and daemons. It builds strong foundations in system-level programming.
# System Software Lab – File and Process Management

## 📖 Overview
This repository contains solutions for **CS 513 / EC 506 – System Software Lab Exercises**.  
The assignments focus on **UNIX/Linux file and process management** concepts using system calls in C.

## 🗂️ Lab Exercises

### 🔹 File Management
1. Create different types of files (soft link, hard link, FIFO).  
2. Infinite loop background process – inspect in `/proc`.  
3. Create a file and print file descriptor.  
4. Open file in read/write mode with `O_EXCL`.  
5. Create five files in infinite loop, check `/proc/pid/fd`.  
6. Read from STDIN, write to STDOUT (only `read`/`write`).  
7. Copy one file into another (like `cp`).  
8. Read file line by line, print until EOF.  
9. Display file metadata (inode, links, uid, gid, size, timestamps, etc.).  
10. Use `lseek` to create holes in files.  
11. Duplicate file descriptors (`dup`, `dup2`, `fcntl`).  
12. Find file opening mode (`fcntl`).  
13. Wait for STDIN with `select` (10 seconds).  
14. Identify file type from command line input.  
15. Display user environment variables.  
16. Perform mandatory locking (read/write).  
17. Simulate online ticket reservation (file locking).  
18. Implement record locking to avoid race conditions.  

### 🔹 Process Management
19. Measure execution time of `getpid` system call.  
20. Find and modify process priority (`nice`).  
21. Use `fork` to print parent & child process IDs.  
22. Parent & child writing to the same file (using `fork`).  
23. Create a Zombie process.  
24. Create an Orphan process.  
25. Parent waits for a specific child (`waitpid`).  
26. Execute another program using exec family.  
27. Execute `ls -Rl` with different `exec*` calls.  
28. Get max & min real-time priorities.  
29. Get & modify scheduling policy (`SCHED_FIFO`, `SCHED_RR`).  
30. Run a script at a specific time using a Daemon.  

## 🛠️ Requirements
- Linux/Unix environment  
- GCC compiler  
- Knowledge of C and system calls  

## 🚀 How to Run
Compile any program using:
```bash
gcc program.c -o program
./program

