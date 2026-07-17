CC = gcc

CFLAGS = -Wall -Wextra -std=c23 \
	-Iengine \
	-Icore \
	-Imath

LDFLAGS = -lSDL3 -lSDL3_image -lm

SRC = \
	main.c \
	engine/renderer.c \
	engine/texture.c \
	core/transform.c \
	core/time.c \
	math/vec2.c

OBJ = $(SRC:.c=.o)

TARGET = dry

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean all

.PHONY: all run clean rebuild
