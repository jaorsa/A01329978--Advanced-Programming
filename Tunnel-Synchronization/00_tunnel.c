/*
1. Pick a direction for travel, 
2. Wait until is safe to enter the tunnel
3. Travel inside tunnel for some amount of time
4. Get out of the tunnel on the other end

*/ 

#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct bufer_t{
	int * tunel; //tunnel
	int maxsize; //tamaño del perol
	int full; //tamaño actual del arreglo
}Bufer;

Bufer * tunnel;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t process;
sem_t semrght;

Bufer * create_buffer(){ //tamaño del 
	Bufer * nuevo = (Bufer * ) malloc(sizeof(Bufer));
	nuevo -> maxsize = 4;
	nuevo -> full = 1;
	nuevo -> tunel = (int *) calloc(4, sizeof(int));
    return nuevo;
}

void crossing(int i){
    
    tunnel->tunel[tunnel->full] = i;
    printf("Espacios llenos son: %d\n", tunnel->full);
    tunnel->full++;
    usleep(rand() %10000);
} 

void leaving(){
    tunnel->tunel[tunnel->full] = -1;
    tunnel->full--;
}

void * goingright(void * params){
    while(1){
        if(tunnel->tunel[tunnel-> full-1] != 0 && tunnel-> full < tunnel-> maxsize){
            sem_wait(&semrght);
            pthread_mutex_lock(&mutex);
            printf("Carro %d ingresando al tunel, llendo hacia la derecha\n", tunnel->full);
            pthread_mutex_unlock(&mutex);
            // sem_post(&semrght);
            // sem_wait(&process);
            printf("Carro está atravesando el tunel hacia la derecha \n ");
            crossing(1);
            sem_post(&process);
            pthread_mutex_lock(&mutex);
            printf("Saliendo del tunel por la entrada derecha\n");
            leaving();
            pthread_mutex_unlock(&mutex);
            sem_post(&process);
        }
        // else{
        //     sem_post(&process);
        //     // sem_wait(&semlft);
        // }

    }
}

void * goingleft(void * params){
    while(1){
        if(tunnel->tunel[tunnel-> full-1] != 1 && tunnel-> full < tunnel-> maxsize){
            sem_wait(&process);     
            pthread_mutex_lock(&mutex);
            printf("Carro %d ingresando al tunel, llendo hacia la izquierda\n", tunnel->full);
            pthread_mutex_unlock(&mutex);
            // sem_post(&semlft);
            
            printf("Carro está atravesando el tunel, llendo hacia la izquierda\n");
            crossing(0);
            // sem_post(&process);
            pthread_mutex_lock(&mutex);
            printf("Saliendo del tunel por la entrada izquierda\n");
            leaving();
            pthread_mutex_unlock(&mutex);
            sem_post(&semrght);
        }
        // else{
        //     sem_post(&semrght);
        //     // sem_wait(&semrght);
        // }
    }
}

void main(){
     sem_init(&process, 0, 4);
    sem_init(&semrght, 0, 4);
    tunnel = create_buffer();
    pthread_t lft1, lft2, lft3, lft4, lft5;
	pthread_t right1, right2, right3, right4;
	pthread_create(&lft1, NULL, &goingleft, NULL);
    pthread_create(&lft5, NULL, &goingleft, NULL);
	pthread_create(&right1, NULL, &goingright, NULL);
	pthread_create(&right2, NULL, &goingright, NULL);
	pthread_create(&lft2, NULL, &goingleft, NULL);
    pthread_create(&lft3, NULL, &goingleft, NULL);
    pthread_create(&lft4, NULL, &goingleft, NULL);
    pthread_create(&right4, NULL, &goingright, NULL);
	pthread_create(&right3, NULL, &goingright, NULL);

    pthread_join(lft1, NULL);
    pthread_join(lft2, NULL);
    pthread_join(lft3, NULL);
    pthread_join(lft4, NULL);
    pthread_join(lft5, NULL);
    pthread_join(right1, NULL);
    pthread_join(right2, NULL);
    pthread_join(right3, NULL);
}
