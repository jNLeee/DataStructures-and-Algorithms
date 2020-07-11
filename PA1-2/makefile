all: test

test: Collection.o collection_test.o Stress_ball.o
	c++ -std=c++11 Collection.o collection_test.o Stress_ball.o -o test

Collection.o: Collection.cpp Collection.h
	c++ -std=c++11 -c Collection.cpp

collection_test.o: collection_test.cpp Collection.h
	c++ -std=c++11 -c collection_test.cpp

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp

clean:
	rm -f *.o test