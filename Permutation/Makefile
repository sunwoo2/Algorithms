.SUFFIXES: .c .o

OBJS = permu.o sort.o
TARGET = permu
CC = gcc
CFLAGS = -W -Wall -O2

all: $(TARGET)

$(TARGET): $(OBJS)
		 $(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(TARGET) $(OBJS)

run:
	./$(TARGET)
