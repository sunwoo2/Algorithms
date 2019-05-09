
CC = gcc
CCFLAGS = -W -Wall -O2
OBJS = 01ks.o
TARGET = $(OBJS:.o=)

print-%: ; @echo $*=$($*)

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

.c.o:
	$(CC) $(CCFLAGS) -c $<

help:
	@echo "make all"
	@echo "make assem"
	@echo "make clean"
	@echo "make run"
