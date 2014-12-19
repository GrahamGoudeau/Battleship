#include <iostream>
#include "Game.h"
//#include "Player.h"

using namespace std;

Game::Game() {
 	human = new Player(false);
 	AI = new Player(true);
}

Game::~Game() {
	delete human;
	delete AI;
}

void Game::play() {
	bool playing = true;

	while (playing) {
		//while (!human->defeated() && !AI->defeated()) {
			// STUFF AND THINGS
		//}
		if (human->defeated()) {
			cout << "You have lost...\n";
		}
		else if (AI->defeated()){
			cout << "You have won!...\n";
		}

		playing = play_again();
	}
}

bool Game::play_again() {
	string play;
	do {
		cout << "Play again? (y/n) ";
		cin >> play;
	} while (play != "y" && play != "n" && play != "Y" && play != "N");

	return play == "y" || play == "Y";
}

