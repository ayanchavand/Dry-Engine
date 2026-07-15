CC = gcc

CFLAGS = -Wall -Wextra -std=c23 \
          -Iengine \
          -Icore \
          -Imath

LDFLAGS = -L/usr/lib -lSDL3

SRC = \
	main.c \
	engine/renderer.c

OBJ = $(SRC:.c=.o)

TARGET = dry

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all run clean
