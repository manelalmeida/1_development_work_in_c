#ifndef DYNVEC_H
#define DYNVEC_H
#include<stddef.h>
#include<stdbool.h>

//todo dynvec: declarado aqui, definido no .c
typedef struct Dynvec dynvec;

dynvec  *dynvec_create(void);
void    dynvec_empty(dynvec *);
size_t  dynvec_capacity(dynvec *);
size_t  dynvec_length(dynvec *);
void    dynvec_push(dynvec *, int);
int     dynvec_pop(dynvec *);
int     dynvec_top(dynvec *);
void    dynvec_set(dynvec *, size_t, int);
int     dynvec_get(dynvec *, size_t);
void    dynvec_insert(dynvec *, size_t, int);
void    dynvec_delete(dynvec *, size_t);
bool    dynvec_contains(dynvec *, int);
size_t  dynvec_index(dynvec *, int);
void    dynvec_print(dynvec *);
void    dynvec_free(dynvec *);

//todo o serviço seguinte é privado, colocado no
//todo ficheiro dynvec.c.
//todo É uma função auxiliar central à biblioteca que
//todo deverá ser implementado.
//todo É aqui referenciado para o efeito da Ficha Prática
//todo static void dynvec_resize (dynvec *, int);

#endif
