#include"Arithmatic.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
    void * ptr = NULL;
    int (*fptr)(int,int) = NULL;
    int ret = 0;
    char path1[100] = {'\0'};
    char path2[100] = {'\0'};

    if(argc != 3)
    {
        printf("Insufficients arguments..\n");
        exit(-1);
    }

    getcwd(path1,sizeof(path1));

    strcat(path1,"/lib1.so");

    ptr = dlopen(path1,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to link li1.so\n");
        exit(-1);
    }
    
    fptr = dlsym(ptr,"Addition");

    if(fptr == NULL)
    {
        printf("Unable fatch the address of Addition function..\n");
    }
    else
    {
        ret = fptr(atoi(argv[1]),atoi(argv[2]));
        printf("Additon is : %d\n",ret);
    }

    getcwd(path2,sizeof(path2));
    strcat(path2,"/lib2.so");

    ptr = dlopen(path2,RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to laod lib2.so file \n");
        exit(-1);
    }

    fptr = dlsym(ptr,"Subtraction");

    if(fptr == NULL)
    {
        printf("Unable to load the address of subtraction fuction\n");
        return -1;
    }
    else
    {
        ret = fptr(atoi(argv[1]),atoi(argv[2]));
        printf("Subtraction is : %d\n",ret);
    }
    
    exit(0);
}