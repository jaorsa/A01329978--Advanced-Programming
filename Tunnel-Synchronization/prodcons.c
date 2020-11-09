/* En este archivo hay una implementación del problema de productores y
   consumidores usando Pthreads y semáforos Posix.

   Autor: Alberto Oliart Ros
*/

#include<pthread.h>
#include<semaphore.h>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>

// El tipo de datos del búfer. Un apuntador para el arreglo, el tamaño y el
// tope del búfer, que se implementa como pila.

typedef struct bufer_t {
  int * bufer;  // El arreglo que guarda los datos.
  int tam;   // El tamaño del arreglo.
  int tope;  // El tope del búfer.
}Bufer;

// El búfer global para los procutores y consumidores.

Bufer * bufer;

// Un mutex para exclusión mutua

pthread_mutex_t exmut = PTHREAD_MUTEX_INITIALIZER;

// Dos semáforos contadores.

sem_t semc;
sem_t semt;  // Se inicializarán en el main.

/* Las siguientes son las funciones para el búfer. La función inserta funciona
   como un push y la función elimina como un pop. La función nuevo_bufer genera
   un búfer nuevo
*/

Bufer * nuevo_bufer(int n) {  // El parámetro es el tamaño del búfer.

  Bufer * buf = (Bufer *) malloc(sizeof(Bufer));  // Crea el búfer
  buf -> tam = n;  // Asigna el tamaño
  buf -> bufer = (int *) calloc(n, sizeof(int));  // Crea el arreglo de datos.
  buf -> tope = 0;  // Indica el primer elemento vacío del búfer.
  return buf;
}

void inserta(int dato, Bufer * buf) {

  int i = buf -> tope;

  if (i >= buf -> tam) { // Ya se pasa de la capacidad.

    printf("Error en el búfer, adiós\n");
    exit(1);
  }
  else { // Todavía se puede poner al menos un elemento

    buf -> bufer[i] = dato;  // Se añade el dato.
    buf -> tope = buf -> tope + 1;  // Se incrementa el tope.
  }
}

int elimina(Bufer * buf) {

  int i = buf -> tope -1;   // i se posiciona donde está el tope del arreglo

  if (i >= 0) {  // Hay datos
    i = buf -> bufer[i];   // Se pone el dato a devolver en i.
    buf -> tope = buf -> tope - 1;  // Se decrementa el tope.
    return i;
  }
  else {  // El búfer está vacío, esto es un error
    printf("Error, búfer vacío. Adiós\n");
    exit(1);
  }
}

/* Cocinero
*/

void * cocinero(void * params) {

  int dato;   // El dato a poner en el búfer.

  // Primero se genera un número aleatorio entre 0 y 99. La semilla se pondrá
  // en el main (no sé por qué).


  do {

    // Ahora hace un wait en el semáforo de los productores, que indica si el
    // búfer está lleno.

    sem_wait(&semc);

    for(int i = 0; i < 4; i++){
      dato = rand() % 100;  // Genera número entre 0 y 99

      inserta(dato, bufer);
    }

    fprintf(stderr, "Cocinero cocinando\n");

    // Ahora hace un signal en el semáforo de los consumidores.

    sem_post(&semt);

  }while (dato != 50);  // Cuando genere un 50 se sale del ciclo y termina.
}

/* La función consumidor es la que controla cómo se comportan los
   consumidores. Los consumidores leen un dato del búfer y lo imprimen en la
   pantalla. Cuando obitnene un 50 dejan de ejecutarse.
*/

void * tribu(void * params) {

  int dato; // Variable donde se lee el dato.

  do {  // Repite lo siguiente hasta que encuentre un 50

    // Si pasa, ahora hace un wait en el semáfoto de exclusión mutua.

    pthread_mutex_lock(&exmut);

    if(bufer -> tope == 0){
      // Hace un wait en el semáforo de los consumidores, que indica si acaso el
      // búfer está vacío.
      
      sem_post(&semc);

      // Ahora signal en el semáforo de los productores, para decir que el búfer
      // no está lleno.

      sem_wait(&semt);
    }

    // Ahora lee el dato del búfer.

    dato = elimina(bufer);

    // Ahora lo imprime.

    printf("Dato del bufer : %d\n", dato);

    // Hace signal en el mutex

    pthread_mutex_unlock(&exmut);

  }while (dato != 50);
}

// La función main. Por el momento pone a correr al mismo número de productores
// y consumidores. Después cambiaré esta implementación, pero por lo pronto,
// así se queda.

void main() {

  pthread_t c;  // Cocinero
  pthread_t t1, t2, t3, t4, t5;  // Los productores

  sem_init(&semc, 0, 0);   // Semáforo productores.
  sem_init(&semt, 0, 0);  // Semáforo consumidores.

  // Se crea el búfer.

  bufer = nuevo_bufer(5);

  // Se pone la semilla en el generador de números aleatorios.

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
