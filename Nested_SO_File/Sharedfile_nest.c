#include"Sharedfile.h"
#include<unistd.h>
#include<dlfcn.h>
#include<stdio.h>
#include<string.h>


void ret_add_of_function(int (**aptr)(int,int))
{
    void * ptr = NULL;
    int (*fptr)(int, int) = NULL;
    char path[100] = {'\0'};

    getcwd(path,sizeof(path));
    strcat(path,"/library.so");

    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        ptr = NULL;
    }

    fptr = dlsym(ptr,"Addition");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        aptr = NULL;
    }

    *aptr = fptr;
}