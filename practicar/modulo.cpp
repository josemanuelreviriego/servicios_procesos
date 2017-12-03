#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

void salir(const char *mssg)
{
    fprintf(stderr,"%s\n", mssg);
    exit(1);
}

void run(const char *mod, const char *funct)
{
    void *modulo;
    void(*fn)() = NULL; //puntero a una funcion
    modulo = dlopen(mod, RTLD_LAZY); //poner ./ delante de la libreria

    if(!modulo)
        salir("No se ha encontrado el modulo.");

    fn = (void (*)() ) dlsym(modulo, funct); //que se meta un modulo y dentro de modulo que busque greet

    if(!fn)
        salir("No se ha encontrado el modulo.");

    (*fn)();

    dlclose(modulo);
}

int main(int argc, char *argv[]){

    run("./libhola.so", "greet");
    run("./libadios.so", "farewell");

    return EXIT_SUCCESS;
}
