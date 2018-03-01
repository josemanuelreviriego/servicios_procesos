#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct parametro {
	const char *frase;
	int numero;
};

//Funcion del hilo

void hiloMensaje(struct parametro *msg) {
	printf("%s %i", msg->frase, msg->numero);
}

int main() {
	pthread_t hilo1, hilo2;

	struct parametro para1 = { "Primer hilo", 1 };
	struct parametro para2 = { "Segundo hilo", 2 };

	//Se crean los dos hilos
	pthread_create(&hilo1, NULL, (void *)hiloMensaje, (void *)&para1);
	pthread_create(&hilo2, NULL, (void *)hiloMensaje, (void *)&para2);

	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);

	printf("Han finalizado los hilos\n");

	return EXIT_SUCCESS;

}