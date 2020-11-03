#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

char text[] = "From Edgar Allan Poe: She whom I loved in youth, and of whom I now pen calmly and distinctly these remembrances, was the sole daughter of the only sister of my mother long departed. Eleonora was the name of my cousin. We had always dwelled together, beneath a tropical sun, in the Valley of the Many-Colored Grass. No unguided footstep ever came upon that vale; for it lay away up among a range of giant hills that hung beetling around about it, shutting out the sunlight from its sweetest recesses. No path was trodden in its vicinity; and, to reach our happy home, there was need of putting back, with force, the foliage of many thousands of forest trees, and of crushing to death the glories of many millions of fragrant flowers. Thus it was that we lived all alone, knowing nothing of the world without the valley -- I, and my cousin, and her mother.";

void* run(void * arg)
{
  for(int i = 0; i < strlen(text); i++)
  {
    //usleep(30000);
    //printf("%c", text[i]);
    printf("%c", text[i]);
    if(text[i] == ' '){usleep(100000);} //printf("%c", text[i]);
  }
  return NULL;
}

void space()
{
  while(1)
  {
    usleep(20000);
    printf(" ");
  }
}

void main()
{
pthread_t newthread;
pthread_create(&newthread, NULL, run, NULL);
space();
pthread_join(newthread, NULL);
}
