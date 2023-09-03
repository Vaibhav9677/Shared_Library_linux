The application is demostret the dynamic linking od shared lib
rary

The Number.h contain the protocal of the two fucntion
int Addition(int,int);
int Addition(int,int);

This Number.h include in the Number.c file
In this file Number.c contains the implimentation of those two fucntion

After that we have create .o file of the number.c file
command to craete .o file from .c :
  gcc -c -fPIC Number.c

after succesfully execution of this command we get Number.o file
then we have to create .so file that final library file
  gcc -shared -o library.so Number.o

