TARGET = a.out
CC = gcc
CFLAGS = -Wall -Wextra

all: src/main.c
	$(CC) -o $(TARGET) src/main.c  $(CFLAGS)