CXX = g++
CXXFLAGS = -Wall -g

lab7: Alien.o lab7.cpp
	$(CXX) $(CXXFLAGS) Alien.o lab7.cpp -o lab7

Alien.o: Alien.h Alien.cpp
	$(CXX) $(CXXFLAGS) -c Alien.cpp

run:
	valgrind ./lab7

clean:
	rm *.o
	rm *~