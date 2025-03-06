CXX = g++
CXXFLAGS = -Wall

lab9: Organism.o Raven.o Sunflower.o lab9.cpp
	$(CXX) $(CXXFLAGS) Organism.o Raven.o Sunflower.o lab9.cpp -o lab9

Organism.o: Organism.h Organism.cpp
	$(CXX) $(CXXFLAGS) -c Organism.cpp

Raven.o: Raven.h Raven.cpp Organism.o
	$(CXX) $(CXXFLAGS) -c Raven.cpp

Sunflower.o: Sunflower.h Sunflower.cpp Organism.o
	$(CXX) $(CXXFLAGS) -c Sunflower.cpp

run:
	./lab9
clean:
	rm *~
	rm *.o
