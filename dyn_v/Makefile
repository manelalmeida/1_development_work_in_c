CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS =
SRC = src/dynvec.c 
#tests/main.c
OBJ = $(SRC:.c=.o)
OUT = dynvec
all: build
build: $(OUT)
$(OUT): $(OBJ)
	$(CC) -o $(OUT) $(OBJ) $(LDFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
debug: CFLAGS += -DDEBUG_ON -g
debug: clean build
clean:
	rm -f $(OBJ) $(OUT)
