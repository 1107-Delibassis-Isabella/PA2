Project2: arraylist.o linkedlist.o snakegame.o tests.o main.o
	g++ arraylist.o linkedlist.o snakegame.o main.o

main.o: main.cpp snakegame.h
	g++ -c main.cpp

arraylist.o: arraylist.h arraylist.cpp
	g++ -c arraylist.cpp

linkedlist.o: Node.h linkedlist.h linkedlist.cpp
	g++ -c linkedlist.cpp

snakegame.o: position.h snakegame.h snakegame.cpp
	g++ -c snakegame.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

clean: 
	rm *.o Project2
