#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define FIREFOX 0
#define GEDIT 1

int total_hijos = 0;

void ejecutar_programa(int programa_hijo){

    switch(programa_hijo){

        case FIREFOX:
            execl("/usr/bin/firefox", "firefox", "www.google.es",NULL);
            break;

        case GEDIT:
            execl("/usr/bin/gedit", "gedit", "JoseManuel",NULL);

        default:
            break;
    }

    fprintf(stderr,"No se ha podido ejecutar el hijo %i", total_hijos);

}

void spawn(int programa){

    int pid_hijo = fork();

    if(pid_hijo){
        total_hijos++;
        return;
    }

    ejecutar_programa(programa);
}

    void muerteHijo(int signal){
        int muerte_natural;
        wait(&muerte_natural);//guarda el retorno en muerte natural para saber si ha sido bien o mal
        total_hijos--;
    }

int main(){

    struct sigaction sa; //Aqui vas a guardar lo que hacen los hijos (informacion)
    bzero(&sa,sizeof(sa));
    sa.sa_handler = &muerteHijo; //sa.handler es la funcion que se va a ejecutar en el proceso hijo por ejemplo -9 matarlo

    sigaction(SIGCHLD, &sa,NULL); //ahi matas al hijo pasando al hijo lo que tienes en sa

    for(int i = 0; i<2; i++)
        spawn(i);

    while(total_hijos){
        fprintf(stderr,"Tengo %i hijos activos\n", total_hijos);
        usleep(300000);
    }

    printf("ya no tengo hijos, adios\n");

    return EXIT_SUCCESS;
    }








