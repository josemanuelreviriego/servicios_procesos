#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
//gcc -o Prueba Prueba.cpp -lpthread

const char *msg = "Hola mundo";

void *imprime(void *mensaje) {
	printf("%s", &msg);
}

int main() {

	pthread_t hola;

	pthread_create(&hola, NULL, (void *)imprime, NULL);

	pthread_join(hola, NULL);

	return EXIT_SUCCESS;
}