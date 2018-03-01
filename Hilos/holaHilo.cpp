#include <stdio.h>
#include <pthread.h>

void *func_hilo(void *arg) {
	printf("Hilo creado : ¡Hola mundo!\n");
}
int main() {
	pthread_t hilo;

	printf("Hilo principal : INICIO\n");

	pthread_create(&hilo, NULL, func_hilo, NULL);
	printf("Hilo principal : HILO CREADO\n");

	pthread_join(hilo, NULL);
	printf("Hilo principal : FIN\n");

	return EXIT_SUCCESS;
}