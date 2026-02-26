// Ficheiro main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "intdynvec.h"
#define MAX_LINE 100
int main(int argc, char *argv[]) {
if (argc < 2) {
fprintf(stderr, "Uso: %s <arquivo_de_teste>\n",
argv[0]);
return 1;
}
FILE *file = fopen(argv[1], "r");
int value, index;
if (!file) {
perror("Erro ao abrir arquivo");
return 1;
}
dynvec *vec = NULL;
char line[MAX_LINE];
while (fgets(line, sizeof(line), file)) {
line[strcspn(line, "\n")] = 0;
// Remove newline
printf("--->%s\n",line);
if (!strcmp(line, "create")) {
vec = dynvec_create();
if (!vec) {
printf("Erro ao criar dynvec\n");
exit(EXIT_FAILURE);
}
}
else if (!strcmp(line, "capacity"))
printf("Capacidade: %zu\n", dynvec_capacity(vec));
else if (!strcmp(line, "length"))
printf("Comprimento: %zu\n", dynvec_length(vec));
else if (sscanf(line, " push %d", &value) == 1)
dynvec_push(vec, value);
else if (!strcmp(line, "pop"))
printf("Popped: %d\n", dynvec_pop(vec));
else if (!strcmp(line, "top"))
printf("Top: %d\n", dynvec_top(vec));
else if (sscanf(line, " set %d %d", &index, &value) ==
2)
dynvec_set(vec, index, value);
else if (sscanf(line, " insert %d %d", &index, &value)
== 2)
dynvec_insert(vec, index, value);
else if (sscanf(line, " delete %d", &index) == 1)
dynvec_delete(vec, index);
else if (sscanf(line, " contains %d", &value) == 1)
printf("Contém %d? %s\n", value, dynvec_contains(vec,
value) ? "Sim" : "Não");
else if (sscanf(line, " index %d", &value) == 1)
printf("Índice de %d: %zu\n", value, dynvec_index(vec,
value));
else if (!strcmp(line, "print"))
dynvec_print(vec);
else if (!strcmp(line, "free"))
dynvec_free(vec);
else if (strcmp(line, ""))
printf("Comando desconhecido: %s\n", line);
}
fclose(file);
return 0;
}
