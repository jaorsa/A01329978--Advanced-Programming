#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct bufer_t{
	int * perol; //perol 
	int maxsize; //tamaño del perol
	int full; //tamaño actual del arreglo
}Bufer;

Bufer * perol;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t empty;
sem_t full;

int cond2 = 1;
int dato;

Bufer * crear_bufer(int i){ //tamaño del 
	Bufer * nuevo = (Bufer * ) malloc(sizeof(Bufer));
	nuevo -> maxsize = i;
	nuevo -> full = 0;
	nuevo -> perol = (int *) calloc(i, sizeof(int));
	
}

void cocinar(int i, Bufer * bufer){
	int n = bufer -> full;
	bufer -> perol[n] = i;
	bufer -> full = bufer -> full + 1;
}

void servir(Bufer * bufer){
	bufer -> full = bufer -> full-1;
}


void * miembro(void * params){
	cond2 = 1;
	do{
		cond2 = 1;
		dato = rand() %100;
		pthread_mutex_lock(&mutex);
		printf("Miembro de la tribu ingresa\n");
		if(perol->full == 0){
		
			sem_post(&full);
			sem_wait(&empty);
			
			printf("Cocinero cocina, perol tiene tamano  %d\n", perol->full);
			
		}
		servir(perol);
		printf("Miembro de la tribu come, pero tiene tamano  %d\n",perol->full);
		pthread_mutex_unlock(&mutex);
	}while(dato!= 30);
	//if(Thread.getState()!=Thread.State.TERMINATED){
	//cond2=0;}
	
}

void * cocinero(void * params){
		int dato2;
	do{
		sem_wait(&full);
		dato2 = rand() %100;
		do{
			cocinar(1, perol);
			printf("perol tiene tamano %d\n", perol->full);
		}while(perol->full < perol->maxsize);
		printf("cocinero duerme ");
		sem_post(&empty);
	}while(cond2!=0);
	
}

void main(){
	sem_init(&empty, 0, 0);
	sem_init(&full, 0,0);	
	
	perol = crear_bufer(10);
	pthread_t m1, m2, m3;
	pthread_t c;
	pthread_create(&m1, NULL, &miembro, NULL);
	pthread_create(&m2, NULL, &miembro, NULL);
	pthread_create(&m3, NULL, &miembro, NULL);
	pthread_create(&c, NULL, &cocinero, NULL);
	
	pthread_join(m1, NULL);
	pthread_join(m2, NULL);
	pthread_join(m3, NULL);
	//pthread_join(c, NULL);
}


