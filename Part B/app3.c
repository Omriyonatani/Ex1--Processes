#define _GNU_SOURCE
#include <syslog.h>
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){

    // create child that will be Daemon
    pid_t pid = fork();

    //if this is the child-
    if( pid == 0 ){

        // move to root dir, to not block the file system
        chdir("/");

        // move to another session, to be independnt 
        setsid();

        printf("Starting my Daemon\n");

        // close the STD out,in,error
        close(STDOUT_FILENO);
        close(STDIN_FILENO);
        close(STDERR_FILENO);

        // open log and write to the log
        openlog ("myDaemon", LOG_PID, LOG_DAEMON);
        syslog (LOG_NOTICE, "Daemon started");
        usleep(3000000);
        syslog (LOG_NOTICE, "Working..");
        usleep(3000000);
        syslog (LOG_NOTICE, "Daemon finished");
        usleep(3000000);

    } else {
        printf("Daemon PID: %d\n" , pid);
    }
    return 0;
}
