CC=g++

build: main.cpp task1/problema1.cpp task2/problema2.cpp task3/problema3.cpp
	$(CC) -c main.cpp task1/problema1.cpp task2/problema2.cpp task3/problema3.cpp -Wall
	$(CC) -o main main.o problema1.o problema2.o problema3.o

problema1:
	./main 1

problema2:
	./main 2

problema3:
	./main 3

run: main
	./main
	
clean:
	rm -f *.o main
