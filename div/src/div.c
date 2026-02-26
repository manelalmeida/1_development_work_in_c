#include <stdio.h>
#include <errno.h>
#include "div.h"

int div(int a,  int b){
    
    #ifdef DEBUG_ON

    printf("[DEBUG] Chamando div(%d, %d)\n", a, b);

    #endif
    
    if(b == 0){
        
        errno = EDOM;
        
        #ifdef DEBUG_ON
        
           
        printf("[DEBUG] Erro: Divisão por zero!\n");
        
        #endif

        return 0;  
    }

    int x = a / b; 

    

    return x;
}
