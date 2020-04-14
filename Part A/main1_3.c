#include "hello_Ariel.h"
#include <stdio.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <stddef.h>


void (*Hello)();

bool init_library(){
    // Open the shared object "./mylib.so" and map it in.
    // return a handle that can be passed to `dlsym' to get symbol values from it.
    // The function dlopen() loads the dynamic library file
    void* handle = dlopen("./mylib.so",RTLD_LAZY);

    if(handle == NULL){
        return false;
    }
    // Find the run-time address in the shared object handle refers to of the symbol called "hello".
    // The function dlsym() takes a "handle" of a dynamic library returned by dlopen().
    Hello = (void(*)())dlsym(handle,"HelloAriel");

    if(Hello == NULL){
        return false;
    }

    return true;
}

int main(){
    if(init_library() == true ){
        Hello();
    } else {
        printf("The library was not loaded\n");
    }
    return 0;
}