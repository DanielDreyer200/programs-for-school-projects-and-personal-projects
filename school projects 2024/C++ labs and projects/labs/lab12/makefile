CXX = g++
CXXFLAGS = -Wall

lab12: Books.o lab12.cpp
	$(CXX) $(CXXFLAGS) Books.o lab12.cpp -o lab12

Books.o: Books.h Books.cpp
	$(CXX) $(CXXFLAGS) -c Books.cpp

run:
	./lab12

clean:
	rm -f *~ *.o

val:
	valgrind ./lab12
