# all: test

# test: Stress_ball.o Jeans.o collection_test.o
# 	c++ -std=c++11 Stress_ball.o Jeans.o collection_test.o -o test

# Stress_ball.o: Stress_ball.cpp Stress_ball.h
# 	c++ -std=c++11 -c Stress_ball.cpp

# Jeans.o: Jeans.cpp Jeans.h 
# 	c++ -std=c++11 -c Jeans.cpp

# collection_test.o: collection_test.cpp
# 	c++ -std=c++11 -c collection_test.cpp

# clean:
# 	rm -f *.0 test

all: collection_test Stress_ball_test jeans_test 

collection_test: collection_test.o Stress_ball.o Jeans.o
    c++ -std=c++11 Stress_ball.o Jeans.o collection_test.o -o collection_test.exe

Stress_ball_test: Stress_ball_test.o Stress_ball.o
    c++ -std=c++11 Stress_ball.o Stress_ball_test.o -o Stress_ball_test.exe

jeans_test: jeans_test.o Jeans.o
	c++ -std=c++11 jeans_test.o Jeans.o -o jeans_test.exe

Stress_ball.o: Stress_ball.cpp Stress_ball.h
	c++ -std=c++11 -c Stress_ball.cpp

Jeans.o: Jeans.cpp Jeans.h
	c++ -std=c++11 -c Jeans.cpp

collection_test.o: collection_test.cpp
	c++ -std=c++11 -c collection_test.cpp

Stress_ball_test.o: Stress_ball_test.cpp
	c++ -std=c++11 -c Stress_ball_test.cpp

jeans_test.o: jeans_test.cpp
	c++ -std=c++11 -c jeans_test.cpp

clean:
	rm -f *.o collection_test Stress_ball_test jeans_test
