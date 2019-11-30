#include "omp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_t 4
char* filename = "./file1.txt";


long long get_size(){
    FILE *fptr;

    fptr = fopen(filename,"r");

    fseek(fptr, 0L, SEEK_END);
    return ftell(fptr);
}

void valid(){
    FILE *fptr;

    fptr = fopen(filename,"r");
    if(fptr == NULL)
    {
        printf("Error!");   
        exit(1);             
    }
}

int comp(char *line, char *word, long long i){
    if(i+strlen(word) <= strlen(line)){
        for(long long j=i, k=0; j<=strlen(word)+i; j++, k++){
            if(line[j] != word[k]){
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int search_seq(char *word){
    double tm_s = omp_get_wtime();
    int find = 0;
    FILE *fptr;

    fptr = fopen(filename,"r");

    const size_t line_size = get_size();
    char* line = malloc(line_size);

    printf("\n Strings encontradas de forma sequencial: \n");
    fread(line, sizeof(char), line_size, fptr);

    for(long long i=0; i<strlen(line); i++){
        if(comp(line, word, i) == 1){
            find=1;
        }
    }
    printf("Codigo sequencial (Tempo): %lf\n", omp_get_wtime()-tm_s);
    return find;
}

int search_parallel(char *word){
    omp_set_num_threads(NUM_t);
    long long lines = get_size()/NUM_t;
    int find = 0;
    FILE *fptr[NUM_t];

    for(int i=0; i<NUM_t; i++){
        FILE *f;
        f = fopen(filename,"r");
        fptr[i] = f;
    }

    printf("\n Strings encontradas de forma paralela: \n");
    double tm_p = omp_get_wtime();
    #pragma omp parallel
    {
        int num_thread = omp_get_thread_num();

        long long start = num_thread*lines, end =(num_thread*lines)+(lines-1);
        const size_t line_size = end;
        char* line = malloc(line_size);

        fseek(fptr[num_thread], start, SEEK_CUR);
        fread(line, sizeof(char), line_size, fptr[num_thread]);

        for(long long i=0; i<strlen(line); i++){
            if(comp(line, word, i) == 1){
                find=1;
            }
        }

        fclose(fptr[num_thread]);
    }
    printf("Codigo paralelo (Tempo): %lf\n", omp_get_wtime()-tm_p);
    return find;
}

int main(){
    valid();

    char word[20] = "";
    printf("Digite a palavra:");
    // scanf("%s", word);
    scanf ("%[^\n]s", word);
    // fgets(word, 20, stdin);

    printf("%s\n", word);

    // printf("%d\n", search_seq(word));
    printf("%d\n", search_parallel(word));

    return 0;
}
