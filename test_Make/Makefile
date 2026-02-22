#? que compilador usar?
CC = gcc
#? com que opções?
CFLAGS = -Wall -Wextra
#? com que nome de executável?
OUT = magia
#? quais são os ficheiros fontes?
SRCS = main.c utils.c
#? ficheiros objetos
OBJS = $(SRCS:.c=.o)
#? Diretiva por omissão: construir o executável
all: $(OUT)					
#? Diretiva para criar o executável
$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJS)
#? Compilar os ficheiros .c para ficheiros objetos .o
%.o: %.c utils.h
	$(CC) $(CFLAGS) -c $< -o $@
#? Limpar os ficheiros caso se pretenda reuniciar acompilação do projeto.
#? Apaga-se os ficheiros objectos e o executável
clean:
	rm -f $(OBJS) $(OUT)
