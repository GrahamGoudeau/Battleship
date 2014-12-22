CXX = clang++
FLAGS = -Wall -g3 -pedantic -c
RM = rm -f

all: battleship

#battleship: main.cpp Ship_Meta.h Game.h Player.h \
		Ship_Meta.cpp Game.cpp Player_Setup.cpp
#	${CXX} ${FLAGS} -o battleship main.cpp Game.cpp Player_Setup.cpp \
				Ship_Meta.cpp 

main.o: main.cpp
	${CXX} ${FLAGS} main.cpp -o $@

Ship.o: Ship_Meta.h Ship_Meta.cpp
	${CXX} ${FLAGS} Ship_Meta.cpp -o $@

Player.o: Player.h Player_Setup.cpp
	${CXX} ${FLAGS} Player_Setup.cpp -o $@

Game.o: Game.h Game.cpp
	${CXX} ${FLAGS} Game.cpp -o $@

battleship: main.o Ship.o Player.o Game.o
	${CXX} $^ -o $@

clean: 
	${RM} battleship *.o
