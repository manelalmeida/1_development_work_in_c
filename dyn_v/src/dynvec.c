#include <stdlib.h>
#include <errno.h>
#include "dynvec.h"

#define DYNVEC_INIT_CAPACITY 4

typedef struct Dynvec {
    int *data;
//? os dados/inteiros arquivados no vetor 
//? capaciade total do vetor
    size_t capacity; 

//? invariante: capacity >= length 

    size_t length;
//quantidade atual de elementos arquivados
//no vetor, com o invariante: 0<=length<=capacity 
} dynvec;

// criar um dynvec com a sua configuração inicial mínima
dynvec *dynvec_create(void){
dynvec *v = malloc(sizeof *v);

if (!v){
errno = ENOMEM;
#ifdef DEBUG_ON
perror("Create. Erro ao alocar memória");
#endif
return NULL;
}

v->capacity = DYNVEC_INIT_CAPACITY;
v->length = 0;
v->data = (int *)malloc(sizeof(int) * v->capacity);
if (!(v->data)) {
errno = ENOMEM;
#ifdef DEBUG_ON
perror("Create. Erro no array, ao alocar memória");
#endif
free(v);
return NULL;
}
return v;
}
