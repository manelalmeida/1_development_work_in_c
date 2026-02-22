#include <stdio.h>

int div(int a,  int b){

int x = a / b; 

#ifdef DEBUG_ON

printf("[DEBUG] Chamando div(%d, %d)\n",a ,b);

#endif

return x;
}