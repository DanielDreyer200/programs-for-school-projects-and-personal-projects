CXX = g++
CXXFLAGS = -Wall

lab10: Cosmetic.o Lipstick.o Eyeshadow.o lab10.cpp
	$(CXX) $(CXXFLAGS)  Cosmetic.o Lipstick.o Eyeshadow.o lab10.cpp -o lab10

Cosmetic.o: Cosmetic.h Cosmetic.cpp
	$(CXX) $(CXXFLAGS) -c Cosmetic.cpp

Lipstick.o: Lipstick.h Lipstick.cpp Cosmetic.o
	$(CXX) $(CXXFLAGS) -c Lipstick.cpp

Eyeshadow.o: Eyeshadow.h Eyeshadow.cpp Cosmetic.o
	$(CXX) $(CXXFLAGS) -c Eyeshadow.cpp

run:
	./lab10
clean:
	rm *~
	rm *.o
