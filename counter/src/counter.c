#include "counter.h"

static unsigned int counter;

void incr(void){
    counter++;
}
int get(void){
    return counter;
}
void reset(void){
    counter = 0;
}
