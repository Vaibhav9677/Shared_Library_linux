#include"Sharedfile.h"
#include<unistd.h>
#include<dlfcn.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
    void * ptr = NULL;
    void (*fptr)(int (**)(int,int)) = NULL;
    int (*addptr)(int,int) = NULL;
    char path[100] = {'\0'};
    int ret = 0;

    getcwd(path,sizeof(path));
    strcat(path,"/library_nest.so");

    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    fptr = dlsym(ptr,"ret_add_of_function");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }

    fptr(&addptr);

    if(addptr == NULL)
    {
        printf("Unable to get address of funtion\n");
        exit(-1);
    }

    ret = addptr(atoi(argv[1]),atoi(argv[2]));

    printf("Addition is : %d\n",ret);

    exit(0);
}