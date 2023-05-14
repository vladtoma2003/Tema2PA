CC=g++

build: main.cpp task1/task1.cpp task2/task2.cpp
	$(CC) -c main.cpp task1/task1.cpp task2/task2.cpp -Wall
	$(CC) -o main main.o task1.o task2.o

run: main
	./main

clean:
	rm -f *.o main