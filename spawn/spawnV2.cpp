#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define N 0x100
#define PROMPT "MA-TEOS $>"
#define M 0x10 //16 en hexadecimal

void
spawn(char buffer[N])
{
    char *argv[M];
    int i = 0;
    pid_t mijo = 0;

    while( argv[i++] = strtok(buffer, " ") )
        buffer = NULL;

    strtok(argv[i-2], "\n");

    mijo = fork(); //En mijo guardas el pid del fork, el padre da verdadero por lo que hace otro programa y el hijo como lo tiene a null da falso y sigue
    // getpid te da el id propio y getppid te da el id del padre
    if(mijo)
        return;

    //execv("/usr/bin/firefox", ["firefox", "index.html", NULL]);
    execvp(argv[0], argv);
    fprintf(stderr, "No he podido ejecutar: %s\n", argv[0]);
    exit(1);
}

int main(int argc, char *argv[])
{
    char buffer[N];

    while(1)
    {
        printf(PROMPT);
        fgets(buffer, N, stdin);
        spawn (buffer);
    }



    return EXIT_SUCCESS;
}
