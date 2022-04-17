
TARGET = tetris
SOURCES = pieces.c screen.c game.c main.c
HEADERS = pieces.h screen.h game.h

CC = gcc
CFLAGS = -I -Wall
LDFLAGS = -lncurses

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $@ $(LDFLAGS)
