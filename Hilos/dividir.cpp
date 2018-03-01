#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//gcc -o dividir dividir.cpp -lpthread

void *dividir(void *numero) {
	int dividendo = (int)numero;

	dividendo / 2;

	return NULL;
}

int main() {

	int num = 10;

	pthread_t hilo1;

	pthread_create(&hilo1, NULL, (void *)dividir, (void *)&num);

	pthread_join(hilo1, NULL);

	printf("%i", num);
}
