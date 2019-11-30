#include "omp.h"
#include<stdio.h>
#include<stdlib.h>
#define num_steps 1000000000
#define num_t 8

double step;


int validate(long long int num){
    if(num%3==0 || num%7==0 || num%11==0){
        return 1;
    }
    
    long long int i = 0;
    for(i=0; i*i<=num; i++){
        if(num%i==0){
            return 0;
        }
    }

    return 1;
}


int main()
{
    long long int f, l, i;
    scanf("%lld %lld", &f, &l);

    for(i=f; i<=l; i++){
        printf("%d\n", validate(i));
        // if(validate(i)){
        //     printf("%lld\t", i);
        // }
    }

    // Set num_t threads
    omp_set_num_threads(num_t);

    // double tm = omp_get_wtime();
    // #pragma omp parallel
    // {
    //     int i = 0, num_thread = omp_get_thread_num();
    //     printf("%d\n", num_thread);
    //     // #pragma omp nowait
    //     for(i=0; i<(num_steps/num_t); i++){
            
    //     }
    // }
    // double tfim = omp_get_wtime()-tm;

    return 0;
}
