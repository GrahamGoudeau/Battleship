#include <iostream>
#include <unistd.h>
#include "Game.h"

using namespace std;

/* BATTLESHIP 
 * GRAHAM GOUDEAU
 * ALGORITHM REFERENCE: http://www.datagenetics.com/blog/december32011/
 */


void cls();
void begin_msg();


int main() {
	cls();
	cout << "BATTLESHIP" << endl;
	sleep(2);
	cls();
	begin_msg();
	cls();
 	Game game;
	game.play();
	
	return 0;
}

void cls() {
	for (int i=0;i<100;i++) cout << "\n";
}

void begin_msg() {
	cout << "1 human player/1 computer player\n\n";
	cout << "When placing ships, the row/column that you indicate will\n";
	cout << "become the uppermost square occupied by the ship (if you\n";
	cout << "placed it vertically), or the leftmost square (if you\n";
	cout << "placed it horizontally.)\n\n\n";
	cout << "Press enter to continue\n";
	string wait;
	getline(cin, wait);
}
