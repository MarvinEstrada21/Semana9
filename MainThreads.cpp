#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_HILOS 10

//Para compilar: agregar -lpthread al comando g++

void* PrintHello(void* threadid) {
	long id_thread;
	id_thread = (long)threadid;
	cout << "Hilo en ejecución! ID, " << id_thread << endl;
	for (int i = 0; i < 10; ++i) {
		cout << "Thread ID, " << id_thread << ": i- " << i << endl;
	}
	pthread_exit(NULL);
}//fin printhello

int main() {
	pthread_t threads[NUM_HILOS];
	int control, i;
	for (int i = 0; i < NUM_HILOS; ++i) {
		cout << "Creando thread " << i << endl;
		control = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
		if (control) {
			cout << "Error al crear un hilo," << control << endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}