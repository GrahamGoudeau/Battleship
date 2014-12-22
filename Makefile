CXX = clang++
FLAGS = -Wall -Wextra -g3 -pedantic -c
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

Setup.o: Player.h Player_Setup.cpp 
	${CXX} ${FLAGS} Player_Setup.cpp -o $@ 

Logic.o: Player.h Player_Logic.cpp
	${CXX} ${FLAGS} Player_Logic.cpp -o $@

Game.o: Game.h Game.cpp
	${CXX} ${FLAGS} Game.cpp -o $@

battleship: main.o Ship.o Setup.o Logic.o Game.o
	${CXX} $^ -o $@

clean: 
	${RM} battleship *.o

rebuild: clean all
