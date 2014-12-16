#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Ships.h"

const int BOARD_DIM = 10;
const int NUM_SHIPS = 5;
const char EMPTY_POS = ' ';


enum ship_t {
	DESTROYER,
	BATTLESHIP,
	SUBMARINE,
	AIRCRAFT_CAR,
	PATROL_BOAT
};

class Player {

public:
	Player(bool is_AI);
	
	void take_turn();
	bool is_hit(int x, int y);
	bool defeated() {return is_defeated;}

private:
	void populate_board();
	void init_board();
	void print_boards();

	bool comp_player;
	bool is_defeated;

	char board[BOARD_DIM][BOARD_DIM];
	char guess_board[BOARD_DIM][BOARD_DIM];
};

#endif
