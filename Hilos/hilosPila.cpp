// hilosPila.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdin.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
//gcc -o hilosPila hilosPila.cpp -lpthread

int suma = 0;

void *sumando(void *num) {
	for (int i = 0; i < 5; i++)
		suma++;
}

int main()
{
	pthread_t hilo1;
	pthread_t hilo2;

	pthread_create(&hilo1, NULL, sumando, NULL);
	pthread_create(&hilo2, NULL, sumando, NULL);

	pthread_join(hilo1, NULL);
	pthread_join(hilo2, NULL);

	printf("Numero %i", suma);

    return EXIT_SUCCESS;
}

