#include "omp.h"
#include<stdio.h>
#define MAX 500000


int main(){
    int id;

    int vet_1[MAX], vet_2[MAX], vet_3[MAX], vet_4[MAX], i = 0;

    for(i=0; i<MAX; i++){
        vet_1[i] = i;
        vet_2[i] = i;
    }

    //Calcular o tempo de execução sequencial
    double tm = omp_get_wtime();
    for(i=0; i<MAX; i++){
        vet_4[i] = vet_1[i] + vet_2[i];
    }
    double tfim = omp_get_wtime()-tm;
    printf("Tempo gasto sem threads: %lf\n", tfim);

    omp_set_num_threads(4);

    //Calcular o tempo de execução com MAX threads
    tm = omp_get_wtime();
    #pragma omp parallel
    {
        int i = 0, num_thread = omp_get_thread_num();
        for(i=0; i<MAX/4; i++){
            vet_3[num_thread*MAX/4 + i] = vet_1[num_thread*MAX/4 + i] + vet_2[num_thread*MAX/4 + i];
        }
    }
    tfim = omp_get_wtime()-tm;
    printf("Tempo gasto com threads: %lf\n", tfim);

    return 0;
}
