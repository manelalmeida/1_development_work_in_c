CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/counter.c
OBJ = counter.o
OUT = libcounter
all: test
static: $(OBJ)
	ar rcs libcounter.a $(OBJ)
# o utilitário ar ajuda a criar uma biblioteca estática
shared: $(OBJ)
	$(CC) -shared -o libcounter.so $(OBJ)
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
test: static
	$(CC) $(CFLAGS) test/main.c -L. -lcounter -o test_counter
clean:
	rm -f $(OBJ) libcounter.a libcounter.so test_counter
	