#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
//gcc -o sumaHilo sumaHilo.cpp -lpthread

int suma = 0;

void *sumar(void *numero) {
	for (int i = 0; i < 10; i++)
		suma++;
}

int main() {

	pthread_t hilo1;
	pthread_t hilo2;

	pthread_create(&hilo1, NULL, sumar, NULL);
	pthread_create(&hilo2, NULL, sumar, NULL);

	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);

	printf("%i", sumar);

	return EXIT_SUCCESS;
}