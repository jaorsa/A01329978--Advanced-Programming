#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define NUM_THREADS 12

FILE* fptr;

int main(int argc, char const *argv[]){
    fptr = fopen("ResultadoMultiplicación","w");
    int n= 10;
    float A[n][n];
    float B[n][n];
    float C[n][n];             //nueva matriz nxn
    int i,j,k;
    double t1,t2,tiempo;
    
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            A[i][j]=j;
            B[i][j]=j;
        }
    }
    
//    for (int i=0;i<n;i++){
//        for (int j=0;j<n;j++){
//            B[i][j]=j;
//        }
//    }
t1=omp_get_wtime();

#pragma omp parallel
    {
        
        #pragma omp for schedule(guided)
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                C[i][j]=0;
                for (int k=0;k<n;k++){
                    C[i][j]=C[i][j]+ (A[i][k]*B[k][j]);
                }
            }
        }
    
    }
    
    t2=omp_get_wtime();
         for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    fprintf(fptr,"%f\t", C[i][j]);
                }
             fprintf(fptr,"\n");
         }
   
        t2=omp_get_wtime();
        tiempo= t2-t1;
       
       
        printf("tiempo:%f\n", tiempo);
        fclose(fptr);
        return 0;
        
}
