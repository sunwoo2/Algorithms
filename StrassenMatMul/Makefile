.SUFFIXES: .c .o

OBJS = strassen.o
TARGET = $(OBJS:.o=)
CC = gcc
CFLAGS = -W -Wall -O2

all: $(TARGET)

$(TARGET): $(OBJS)
		 $(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJS)

run:
	./$(TARGET)
