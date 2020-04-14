#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// function that prints "Hello From..."
void print(const char *who){
    for(int i=0; i<20; i++){
        printf("Hello From %s\n", who);
        usleep(1000000);
    }
}

int main(){
    // make a child
    __pid_t pid = fork();

    // the first 0 = child
    if(pid == 0){
        // i am in the child
        // create grand-child
        __pid_t pid = fork();

        // second 0 = Grand-Child
        if(pid == 0 ){
            //i am in the grand-child
            print("Grand Child");
        } else {
            print("Child");
        }
    } else {
        print("Parent");
    }
    return 0;
}