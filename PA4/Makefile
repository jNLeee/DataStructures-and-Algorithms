all: test

test: main.o CSVEditor.o
	g++-8.2.0 -std=c++17 main.o CSVEditor.o -o test

main.o: main.cpp HashTable.hpp
	g++-8.2.0 -std=c++17 -c main.cpp

CSVEditor.o: CSVEditor.cpp CSVEditor.hpp
	g++-8.2.0 -std=c++17 -c CSVEditor.cpp

clean: 
	rm *.o 
