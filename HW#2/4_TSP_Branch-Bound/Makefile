
CC = gcc
CCFLAGS = -W -Wall -O2
OBJS = tsp.o
TARGET = $(OBJS:.o=)

print-%: ; @echo $*=$($*)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

clean:
	@echo "Deleting"
	rm -rf $(TARGET) $(OBJS) output.txt

run:
	@echo "Executing"
	./$(TARGET)

.c.o:
	$(CC) $(CCFLAGS) -c $<

help:
	@echo "make all"
	@echo "make clean"
	@echo "make run"
