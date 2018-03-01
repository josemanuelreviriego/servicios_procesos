#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
//gcc -o hiloPrimo hiloPrimo.cpp -lpthread

#define MAX 1000

struct TPila {
	unsigned *num;
	unsigned cont;
	
} primos;

void push(struct TPila *numeros, int dato) {
	numeros->num[numeros->cont++] = dato;
}

bool es_primo(unsigned num) {
	for (unsigned i = 0; i < primos.cont;i++)
		if (num % primos.num[i] == 0)
			return false;

	return true;
}

void push_primo(unsigned num) {
	if (es_primo(num)) {
		push(&primos, num);
		fprintf(stderr, "%i \n", num);
	}
}

void *numeros_primos(void *) {
	for (unsigned i = 2; i < MAX; i++)
		push_primo(i);

	return NULL;
}

int main(int argc, char *argv[]) {

	primos.num = (unsigned *)malloc(10000 * sizeof(unsigned));

	pthread_t hilo, hilo2;

	pthread_create(&hilo, NULL, numeros_primos, NULL);
	pthread_create(&hilo2, NULL, numeros_primos, NULL);

	pthread_join(hilo, NULL);
	pthread_join(hilo2, NULL);

	free(primos.num);

	return EXIT_SUCCESS;

}
