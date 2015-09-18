#compiler: gcc for C program, define as g++ for C
CC = gcc
# compiler flags:

#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -lncurses -liw
VPATH = src
# the build target executable:

all: main.o y5list.o main.o
	$(CC) $(CFLAGS) -o nsy5 gui.o y5list.o main.o
main.o: src/main.c
	$(CC) $(CFLAGS) -o main.o -c src/main.c
gui.o: src/gui.c
	$(CC) $(CFLAGS) -o gui.o -c src/gui.c
#$(TARGET): $(TARGET).c
#$(CC) $(CFLAGS) -o $(TARGET).o -c ./src$(TARGET).c
y5list.o: src/y5list.c
	$(CC) $(CFLAGS) -o y5list.o -c src/y5list.c

clean:
	rm -f *.o
