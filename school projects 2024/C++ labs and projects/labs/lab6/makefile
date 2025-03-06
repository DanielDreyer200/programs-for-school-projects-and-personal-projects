CXX = g++
CXXFLAGS = -Wall

lab6: lab6.cpp task.o
	$(CXX) $(CXXFLAGS) lab6.cpp task.o -o lab6

task.o: task.cpp task.h
	$(CXX) $(CXXFLAGS) -c task.cpp

run:
	./lab6

clean:
	rm *~ *.o
