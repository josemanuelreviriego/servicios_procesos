#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(){

    int status;
    int contador;

    for(contador = 0; contador<5;contador++){
        if(fork()==0){
            printf("PROCESOS CREADOS\n");
            printf("Tenemos un proceso  %i, con el PID %i y el PID del padre %i \n\t", contador, getpid(), getppid());
        }else{
            wait(&status); // se le mete el signal y le envias el codigo para matarlo
            printf("Procesos Terminados\n");
            printf("#################################\n");
            printf("Tenemos un proceso %i, con el PID %i  y el PID del padre %i \n\t", contador, getppid(), getppid());

            return EXIT_SUCCESS;

        }
    }
}
