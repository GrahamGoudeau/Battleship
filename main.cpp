#include <iostream>
#include <unistd.h>
#include "Game.h"

using namespace std;

/* BATTLESHIP 
 * GRAHAM GOUDEAU
 * ALGORITHM REFERENCE: http://www.datagenetics.com/blog/december32011/
 */


void cls();

int main() {
	cls();
	cout << "BATTLESHIP" << endl;
	sleep(1);
 	Game game;
	game.play();
	
	return 0;
}

void cls() {
	for (int i=0;i<100;i++) cout << "\n";
}
