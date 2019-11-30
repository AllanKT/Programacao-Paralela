#include <omp.h>
#include <stdio.h>
 
int main() {
   int id;
   omp_set_num_threads(4);
 
   #pragma omp parallel
   {
       id = omp_get_thread_num();
       printf("Eu sou o id %d \n", id);
   }
 
   return 0;
}
