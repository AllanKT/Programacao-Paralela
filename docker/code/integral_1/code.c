#include "omp.h"
#include<stdio.h>
#include<stdlib.h>
#define num_steps 1000000


double step;

int main()
{
    int i; 
    double x, pi, sum = 0.0;

    step = 1.0/(double) num_steps;

    double tm = omp_get_wtime();
    for (i=0; i<num_steps; i++)
    {
        x = (i+0.5)*step;
        sum = sum+4.0/(1.0 + x * x);
    }
    double tfim = omp_get_wtime()-tm;

    printf("Tempo gasto com threads: %lf\n", tfim);

    pi = sum*step;
    printf("PI = %f\n", pi);

    return 0;
}
