#include<stdio.h>
#include<dlfcn.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main(int argc, char * argv[])
{
    void * ptr = NULL;
    int (*fptr)(int,int) = NULL;
    int ret = 0;
    char path[100] = {'\0'};

    getcwd(path,sizeof(path));
    strcat(path,"/NumLib.so");


    ptr = dlopen(path,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }
    else
    {
        printf("Dynamic library link successfully..\n");
    }

    fptr = dlsym(ptr,"Addition");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }
    else
    {
        ret = fptr(atoi(argv[1]),atoi(argv[2]));
        printf("Addition is : %d\n",ret);
    }

    fptr = dlsym(ptr,"Subtraction");

    if(fptr == NULL)
    {
        printf("%s\n",dlerror());
        exit(-1);
    }
    else
    {
        ret = fptr(atoi(argv[1]),atoi(argv[2]));
        printf("Subtraction is : %d\n",ret);
    }

    exit(0);

}