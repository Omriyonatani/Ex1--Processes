#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 20


char child_stack[STACK_SIZE+1];

// function that prints "Hello From..."
void print(const char *who){
    for(int i=0; i<CYCLES; i++){
        printf("Hello From %s\n", who);
        usleep(1000000);
    }
}

// Child print
int child (void *params){
    print("child_thread");
    return 0;
}


int main(){
    // clones to make processes brothers
    int result1 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);
    int result2 = clone(child,child_stack+STACK_SIZE,CLONE_PARENT,0);

    printf("clone result1 = %d\n", result1);
    printf("clone result2 = %d\n", result2);
    
    print("Parent");
    return 0;
}