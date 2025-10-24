CC = gcc
CFLAGS = -Wall -std=c99
LIBS = -lraylib -lm -lpthread -ldl -lGL -lX11

SRC = main.c button.c textbutton.c texturebutton.c
OBJ = $(SRC:.c=.o)

all: game clean

game: $(OBJ)
	$(CC) $(OBJ) -o main.out $(LIBS)

clean:
	rm -f $(OBJ)

