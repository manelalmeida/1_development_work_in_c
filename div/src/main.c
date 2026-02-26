#include <stdio.h>
#include <errno.h>
#include <string.h>
// Para strerror()
#include "div.h"

int main() {
    int a = 10, b = 2;

    #ifdef DEBUG_ON
    printf("[DEBUG] Testar div!\n");
    #endif

    // Tentativa de divisão normal
    int result = div(a, b);

    if (errno == EDOM)
        printf("Erro: Divisão por zero! (%s)\n",
        strerror(errno));
    else printf("%d / %d = %d\n", a, b, result);

    // Tentativa de divisão por zero

    b = 0;
    result = div(a, b);

    if (errno == EDOM)
        printf("Erro: Divisão por zero! (%s)\n",
        strerror(errno));
    else printf("%d / %d = %d\n", a, b, result);

    return 0;
}
