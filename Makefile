CXX = clang++
FLAGS = -Wall -g3 -pedantic

battleship: main.cpp Ship_Meta.h Game.h Player.h \
		Ship_Meta.cpp Game.cpp Player.cpp
	${CXX} ${FLAGS} -o battleship main.cpp Game.cpp Player.cpp \
				Ship_Meta.cpp 

clean: 
	rm -f battleship *.o
#songsearch: main.cpp hashfunc.cpp hashfunc.h WordList.cpp WordList.h\
		WordHashTable.h WordHashTable.cpp \
		SongHashTable.h SongHashTable.cpp 
#	${CXX} ${FLAGS} -o songsearch main.cpp hashfunc.cpp WordList.cpp\
				WordHashTable.cpp SongHashTable.cpp 
	
#clean:
#	rm -f songsearch

#provide_design:
#	provide comp15 hw6_design songsearch_design.txt

#provide:
#	provide comp15 hw5 <all your files go here>

