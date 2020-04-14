#define _GNU_SOURCE
#include <syslog.h>
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define STACK_SIZE 10000
char child_stack[STACK_SIZE+1]; 

// function to make Daemon child
int app3Daemon(){
    pid_t pid = fork();
    if(pid == 0 ){
        char * args[2] = {"./app3",NULL};
	    execvp(args[0],args);
    }
    return 0;
}


int main(){
    // start with app1, and make a childs by fork
    pid_t pid = fork();
    if(pid == 0 ){
        // if i am the child- make app1
        char * args[2] = {"./app1",NULL};
	    execvp(args[0],args);
    } else {
        // make brother process for app2.
        pid_t pid = fork();
        if( pid == 0 ){
            // i am app2..
            char * args[2] = {"./app2",NULL};
	        execvp(args[0],args);
        }
        // and make the Daemon..
        app3Daemon();
    }
    printf("Parent id: %d\n" , getpid());
    sleep(10);

    return 0;
}