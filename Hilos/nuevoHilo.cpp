#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//gcc -o nuevoHilo nuevoHilo.cpp -lpthread

/* this function is run by the second thread */
void *inc_x(void *x_void_ptr)
{

	/* increment x to 100 */
	int *x_ptr = (int *)x_void_ptr;

	while ((*x_ptr)++ < 100);

	printf("x increment finished\n");

	/* the function must return something - NULL will do */
	return NULL;

}

int main()
{

	int x = 0, y = 0;

	/* show the initial values of x and y */
	printf("x: %d, y: %d\n", x, y);

	/* this variable is our reference to the second thread */
	pthread_t inc_x_thread;

	/* create a second thread which executes inc_x(&x) */
	// pthread_create(hilo creado, NULL, funcion del hilo, parametro funcion del hilo)
	if (pthread_create(&inc_x_thread, NULL, inc_x, &x)) {

		fprintf(stderr, "Error creating thread\n");
		return 1;

	}
	/* increment y to 100 in the first thread */
	while (y++ < 100);

	printf("y increment finished\n");

	/* wait for the second thread to finish */
	//El prototipo de  pthread_join es el siguiente: int pthread_join(pthread_t hilo_al_que_hay_que_esperar, void *valor_de_retorno_de_la_función de hilo)
	if (pthread_join(inc_x_thread, NULL)) {

		fprintf(stderr, "Error joining thread\n");
		return 2;

	}

	/* show the results - x is now 100 thanks to the second thread */
	printf("x: %d, y: %d\n", x, y);

	return 0;

}
//
//This code will print something like:
//
//x: 0, y:0
//y increment finished
//x increment finished
//x: 100, y: 100
