CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = chunk.c main.c memory.c debug.c value.c vm.c
OBJ = $(SRC:.c=.o)
DEPS = chunk.h common.h memory.h debug.h value.h vm.h

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
