/*
======================================================================================
Name    : 2
Author  : Mohit Kumar
Description : 
    Write a simple program to execute in an infinite loop at the background. 
    Go to /proc directory and identify all the process related information 
    in the corresponding /proc directory.
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("Running..\n");
        sleep(2);
    }
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd /proc/5913
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:/proc/5913$ ls
arch_status         fdinfo             ns             smaps_rollup
attr                gid_map            numa_maps      stack
autogroup           io                 oom_adj        stat
auxv                ksm_merging_pages  oom_score      statm
cgroup              ksm_stat           oom_score_adj  status
clear_refs          latency            pagemap        syscall
cmdline             limits             patch_state    task
comm                loginuid           personality    timens_offsets
coredump_filter     map_files          projid_map     timers
cpu_resctrl_groups  maps               root           timerslack_ns
cpuset              mem                sched          uid_map
cwd                 mountinfo          schedstat      wchan
environ             mounts             sessionid
exe                 mountstats         setgroups
fd                  net                smaps
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:/proc/5913$ kill -9 5913
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:/proc/5913$ ls
ls: cannot open directory '.': No such process
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:/proc/5913$


======================================================================================

*/

