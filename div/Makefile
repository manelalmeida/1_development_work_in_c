CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS =
SRC = src/div.c src/main.c
OBJ = $(SRC:.c=.o)
OUT = div_program
all: build
build: $(OUT)
$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) -o $(OUT) $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
debug: CFLAGS += -DDEBUG_ON
debug: clean build
clean:
	rm -f $(OBJ) $(OUT)
