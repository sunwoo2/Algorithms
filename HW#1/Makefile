.SUFFIXES: .c .o

OBJS = streetlamp.o
TARGET = $(OBJS:.o=)
CC = gcc
CCFLAGS = -W -Wall -O2

print-%: ; @echo $*=$($*)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

assem: $(OBJS:.o=.c)
	@echo "Compiling Assembly"
	$(CC) $(CCFLAGS) -S $^

clean:
	@echo "Deleting"
	rm -rf $(TARGET) $(OBJS) $(OBJS:.o=.s)

run:
	@echo "Executing"
	./$(TARGET)

help:
	@echo "make all"
	@echo "make assem"
	@echo "make clean"
	@echo "make run"
