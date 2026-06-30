CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
TARGET = raylibTest

# Nota: Sin barra invertida en el último archivo
OBJ = main.o \
      buttons/button.o \
      buttons/textbutton.o \
      buttons/texturebutton.o \
      utils/rng.o \
      utils/text.o \
      utils/timer.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
