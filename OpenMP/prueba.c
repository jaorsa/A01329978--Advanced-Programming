#include <stdio.h>
#include <stdlib.h>
#include "omp.h"

void main()
{   
    #pragma omp parallel 
    {
        int ID = omp_get_thread_num();

        printf("HELLO (%d)\n", ID);
        printf("world (%d)\n", ID);
    }

}