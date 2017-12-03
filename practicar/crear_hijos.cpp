#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int status;
    int contador; //Creamos un contador

    //Para controlar los hilos que queremos crear
    for(contador = 0; contador <5; contador++) //Para crear 5hijos y el padre
        if(fork()==0){ //Creamos hijos
            printf("Procesos creados \n ");
            printf("PID del HIJO %i proceso = %i Pid Padre = %i \n \t", getpid(),contador,getpid());
        }else{//Si lo devuelve el fork(distinto de 0)

            wait(&status); //esperamos a que termine el hijo
            printf("####################### \n");
            printf("Procesos terminados: \n ");
            printf("PID del hijo %i = %i Pid padre = %i \n \t", getpid(),contador,getpid());

            exit(0);
        }
        }

