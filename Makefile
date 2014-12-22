CXX = clang++
FLAGS = -Wall -g3 -pedantic

battleship: main.cpp Ship_Meta.h Game.h Player.h \
		Ship_Meta.cpp Game.cpp Player_Setup.cpp
	${CXX} ${FLAGS} -o battleship main.cpp Game.cpp Player_Setup.cpp \
				Ship_Meta.cpp 

clean: 
	rm -f battleship *.o
