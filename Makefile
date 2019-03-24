.SUFFIXES: .c .o

OBJS = test.o
TARGET = test
CC = gcc
CCFLAGS = -W -Wall -O2

print-%: ; @echo $*=$($*)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $^

#.c.o:
#	$(CC) $(CCFLAGS) -c -o $@ $<

assem: $(OBJS:.o=.c)
	@echo "Compiling Assembly"
	$(CC) $(CCFLAGS) -S $^

clean:
	@echo "Deleting"
	rm -rf $(TARGET) $(OBJS) $(OBJS:.o=.s)

run:
	@echo "Executing"
	./$(TARGET) file.bin 4

push:
	git add .
	git commit -m "Update"
	git push origin master	#얘는 로컬저장소를 원격저장소랑 연결한거여서 이렇게

help:
	@echo "make all"
	@echo "make assem"
	@echo "make clean"
	@echo "make run"
	@echo "make push - simplified push to github"
