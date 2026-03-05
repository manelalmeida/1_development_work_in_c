#include <stdlib.h>
#include <errno.h>
#include "intdynvec.h"

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
//!0	
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
//!1
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
//!2
size_t dynvec_capacity(dynvec *v){
    
    if(!v)return 0;

    return v->capacity;
}
//!3
size_t dynvec_length(dynvec *v){

    if(v == NULL)return 0;

    return v->length;
} 
//!4
static void dynvec_resize(dynvec *v, int size){
    
    if(size < v->length){
        return;
    }  

    int *t = realloc(v->data, size * sizeof *v->data);
    
    if(!t){
        
        errno = ENOMEM;
        #ifdef DEBUG_ON
        perror("Create. Erro no array, ao alocar memória");
        #endif
        return;     
    }
    v->data = t;
    v->capacity = size;

}
//!5
void dynvec_push(dynvec *v, int item){

    
}
