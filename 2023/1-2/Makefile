CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = bin
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

run:
	@./bin

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean

