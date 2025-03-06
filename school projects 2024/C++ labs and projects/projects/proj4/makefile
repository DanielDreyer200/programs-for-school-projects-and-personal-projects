CXX = g++
CXXFLAGS = -Wall

proj4: Game.o Area.o Enemy.o Creeper.o Mandarin.o Mannequin.o Weapon.o Plank.o Shotgun.o Chainsaw.o Hero.o proj4.cpp
	$(CXX) $(CXXFLAGS)   Enemy.o Creeper.o Mandarin.o Mannequin.o Weapon.o Plank.o Shotgun.o Chainsaw.o Hero.o Area.o Game.o proj4.cpp -o proj4

Game.o: Game.h Game.cpp
	$(CXX) $(CXXFLAGS) -c Game.cpp

Area.o: Area.h Area.cpp
	$(CXX) $(CXXFLAGS) -c Area.cpp

Hero.o: Hero.h Hero.cpp 
	$(CXX) $(CXXFLAGS) -c Hero.cpp

Enemy.o: Enemy.h Enemy.cpp
	$(CXX) $(CXXFLAGS) -c Enemy.cpp

Creeper.o: Creeper.h Creeper.cpp Enemy.o
	$(CXX) $(CXXFLAGS) -c Creeper.cpp

Mandarin.o: Mandarin.h Mandarin.cpp Enemy.o
	$(CXX) $(CXXFLAGS) -c Mandarin.cpp

Mannequin.o: Mannequin.h Mannequin.cpp Enemy.o
	$(CXX) $(CXXFLAGS) -c Mannequin.cpp

Weapon.o: Weapon.h Weapon.cpp
	$(CXX) $(CXXFLAGS) -c Weapon.cpp

Plank.o: Plank.h Plank.cpp Weapon.o
	$(CXX) $(CXXFLAGS) -c Plank.cpp

Shotgun.o: Shotgun.h Shotgun.cpp Weapon.o
	$(CXX) $(CXXFLAGS) -c Shotgun.cpp

Chainsaw.o: Chainsaw.h Chainsaw.cpp Weapon.o
	$(CXX) $(CXXFLAGS) -c Chainsaw.cpp


run0:
	./proj4 proj4_map1.txt

run1:
	./proj4 proj4_map2.txt

clean:
	rm *~
	rm *.o
