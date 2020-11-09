/* En este archivo hay una implementaci�n del problema de productores y
   consumidores usando Pthreads y sem�foros Posix.

   Autor: Alberto Oliart Ros
*/

#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

// El tipo de datos del b�fer. Un apuntador para el arreglo, el tama�o y el
// tope del b�fer, que se implementa como pila.

typedef struct bufer_t {
  int * bufer;  // El arreglo que guarda los datos.
  int tam;   // El tama�o del arreglo.
  int tope;  // El tope del b�fer.
}Bufer;

// El b�fer global para los procutores y consumidores.

Bufer * bufer;

// Un mutex para exclusi�n mutua

pthread_mutex_t exmut = PTHREAD_MUTEX_INITIALIZER;

// Dos sem�foros contadores.

sem_t semc;
sem_t semt;  // Se inicializar�n en el main.

/* Las siguientes son las funciones para el b�fer. La funci�n inserta funciona
   como un push y la funci�n elimina como un pop. La funci�n nuevo_bufer genera
   un b�fer nuevo
*/

Bufer * nuevo_bufer(int n) {  // El par�metro es el tama�o del b�fer.

  Bufer * buf = (Bufer *) malloc(sizeof(Bufer));  // Crea el b�fer
  buf -> tam = n;  // Asigna el tama�o
  buf -> bufer = (int *) calloc(n, sizeof(int));  // Crea el arreglo de datos.
  buf -> tope = 0;  // Indica el primer elemento vac�o del b�fer.
  return buf;
}

void inserta(int dato, Bufer * buf) {

  int i = buf -> tope;

  if (i >= buf -> tam) { // Ya se pasa de la capacidad.

    printf("Error en el b�fer, adi�s\n");
    exit(1);
  }
  else { // Todav�a se puede poner al menos un elemento

    buf -> bufer[i] = dato;  // Se a�ade el dato.
    buf -> tope = buf -> tope + 1;  // Se incrementa el tope.
  }
}

int elimina(Bufer * buf) {

  int i = buf -> tope -1;   // i se posiciona donde est� el tope del arreglo

  if (i >= 0) {  // Hay datos
    i = buf -> bufer[i];   // Se pone el dato a devolver en i.
    buf -> tope = buf -> tope - 1;  // Se decrementa el tope.
    return i;
  }
  else {  // El b�fer est� vac�o, esto es un error
    printf("Error, b�fer vac�o. Adi�s\n");
    exit(1);
  }
}

/* Cocinero
*/

void * cocinero(void * params) {

  int dato;   // El dato a poner en el b�fer.

  // Primero se genera un n�mero aleatorio entre 0 y 99. La semilla se pondr�
  // en el main (no s� por qu�).


  do {

    // Ahora hace un wait en el sem�foro de los productores, que indica si el
    // b�fer est� lleno.

    sem_wait(&semc);

    for(int i = 0; i < 4; i++){
      dato = rand() % 100;  // Genera n�mero entre 0 y 99

      inserta(dato, bufer);
    }

    fprintf(stderr, "Cocinero cocinando\n");

    // Ahora hace un signal en el sem�foro de los consumidores.

    sem_post(&semt);

  }while (dato != 50);  // Cuando genere un 50 se sale del ciclo y termina.
}

/* La funci�n consumidor es la que controla c�mo se comportan los
   consumidores. Los consumidores leen un dato del b�fer y lo imprimen en la
   pantalla. Cuando obitnene un 50 dejan de ejecutarse.
*/

void * tribu(void * params) {

  int dato; // Variable donde se lee el dato.

  do {  // Repite lo siguiente hasta que encuentre un 50

    // Si pasa, ahora hace un wait en el sem�foto de exclusi�n mutua.

    pthread_mutex_lock(&exmut);

    if(bufer -> tope == 0){
      // Hace un wait en el sem�foro de los consumidores, que indica si acaso el
      // b�fer est� vac�o.
      
      sem_post(&semc);

      // Ahora signal en el sem�foro de los productores, para decir que el b�fer
      // no est� lleno.

      sem_wait(&semt);
    }

    // Ahora lee el dato del b�fer.

    dato = elimina(bufer);

    // Ahora lo imprime.

    printf("Dato del bufer : %d\n", dato);

    // Hace signal en el mutex

    pthread_mutex_unlock(&exmut);

  }while (dato != 50);
}

// La funci�n main. Por el momento pone a correr al mismo n�mero de productores
// y consumidores. Despu�s cambiar� esta implementaci�n, pero por lo pronto,
// as� se queda.

void main() {

  pthread_t c;  // Cocinero
  pthread_t t1, t2, t3, t4, t5;  // Los productores

  sem_init(&semc, 0, 0);   // Sem�foro productores.
  sem_init(&semt, 0, 0);  // Sem�foro consumidores.

  // Se crea el b�fer.

  bufer = nuevo_bufer(5);

  // Se pone la semilla en el generador de n�meros aleatorios.

  srand(time(0));

  pthread_create(&c, NULL, &cocinero, NULL);
  pthread_create(&t1, NULL, &tribu, NULL);
  pthread_create(&t2, NULL, &tribu, NULL);
  pthread_create(&t3, NULL, &tribu, NULL);
  pthread_create(&t4, NULL, &tribu, NULL);
  pthread_create(&t5, NULL, &tribu, NULL);

  pthread_join(c, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  pthread_join(t3, NULL);
  pthread_join(t4, NULL);
  pthread_join(t5, NULL);
}
