CXX = clang++
FLAGS = -Wall -Wextra -g3 -pedantic -c
RM = rm -f


all: battleship

main.o: main.cpp
	${CXX} ${FLAGS} main.cpp -o $@

Ship.o: Ship.h Ship.cpp
	${CXX} ${FLAGS} Ship.cpp -o $@

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

rebuild: print_clean clean battleship print_done

print_clean:
	${info Updating build...}	

print_done:
	${info Done rebuilding...}
