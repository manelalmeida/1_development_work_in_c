#include <stdlib.h>
#include <errno.h>
#include "dynvec.h"

#define DYNVEC_INIT_CAPACITY 4

typedef struct Dynvec {

// Apontador para o array de inteiros
    int *data;

// Quantos inteiros cabem fisicamente
// capaciade total do vetor
// size_t é tipo inteiro sem sinal (unsigned)
    size_t capacity; 

// invariante: capacity >= length
// Quantos inteiros estão realmente usados 
    size_t length;

// no vetor, com o invariante: 0<=length<=capacity 
} dynvec;

// criar um dynvec com a sua configuração inicial mínima

dynvec *dynvec_create(void){

// v é ponteiro para uma estrutura dynvec
    dynvec *v = malloc(sizeof *v);

    if (!v){
        errno = ENOMEM;
        #ifdef DEBUG_ON
        perror("Create. Erro ao almalloc(v->capacity * sizeof *v->data);ocar memória");
        #endif
    return NULL;
    }
    
    v->capacity = DYNVEC_INIT_CAPACITY;
    v->length = 0;
    v->data = malloc(v->capacity * sizeof *v->data);

    if (!(v->data)) {
        errno = ENOMEM;
        #ifdef DEBUG_ON
        perror("Create. Erro no array, ao alocar memória");
        #endif
        free(v);

    return NULL;
    }

// endereço da estrutura    
    return v;
}

void dynvec_empty(dynvec *v){
    

// alocar em uma variavel temporaria     
    int *t = malloc(DYNVEC_INIT_CAPACITY * sizeof *v->data);

//
    if(!t){

        errno = ENOMEM;
        #ifdef DEBUG_ON
        perror("Create. Erro no array, ao alocar memória");
        #endif       
        return;
    }
    free(v->data);

    v->data = t;

    v->capacity = DYNVEC_INIT_CAPACITY;
    v->length = 0;
    
    return;                  
}

size_t dynvec_capacity(dynvec *v){
    
}