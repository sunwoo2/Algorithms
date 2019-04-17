
OBJS = car.o car_dijkstra.o
TARGET = $(OBJS:.o=)
CC = gcc
CCFLAGS = -W -Wall -O2

print-%: ; @echo $*=$($*)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o car car.o
	$(CC) $(CCFLAGS) -o car_dijkstra car_dijkstra.o

assem: $(OBJS:.o=.c)
	@echo "Compiling Assembly"
	$(CC) $(CCFLAGS) -S $^

clean:
	@echo "Deleting"
	rm -rf $(TARGET) $(OBJS) $(OBJS:.o=.s)

run:
	@echo "Executing"
	./car

run1:
	@echo "Executing"
	./car_dijkstra

.c.o:
	$(CC) $(CCFLAGS) -c $<

help:
	@echo "make all"
	@echo "make assem"
	@echo "make clean"
	@echo "make run"
