#include "omp.h"
#include<stdio.h>
#include<stdlib.h>
#define num_steps 1000000000
#define num_t 8

double step;

int main()
{
    int i;
    double x, pi, sum = 0.0, vet[num_t];

    for(i=0; i<num_t; i++) vet[i] = 0.0;

    // Set num_t threads
    omp_set_num_threads(num_t);

    step = 1.0/(double) num_steps;

    double tm = omp_get_wtime();
    #pragma omp parallel
    {
        int i = 0, num_thread = omp_get_thread_num();
        printf("%d\n", num_thread);
        // #pragma omp nowait
        for(i=0; i<(num_steps/num_t); i++){
            x = (i+0.5)*step;
            #pragma omp atomic
                sum = sum+4.0/(1.0 + x * x);
                // vet[num_thread] = vet[num_thread]+4.0/(1.0 + x * x);

            // sum = sum+4.0/(1.0 + x * x);
        }
    }
    double tfim = omp_get_wtime()-tm;

    printf("Tempo gasto com threads: %lf\n", tfim);

    for(i=0; i<num_t; i++) sum+=vet[i];
    pi = sum*step;
    printf("SUM = %f\nPI = %f\n", sum, pi);

    return 0;
}
