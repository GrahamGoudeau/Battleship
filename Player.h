#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Ship_Meta.h"

const int BOARD_DIM 	= 10;
const int NUM_SHIPS 	= 5;
const char EMPTY_POS 	= '_';

const int DESTROYER_LEN 	= 3;
const int BATTLESHIP_LEN 	= 4;
const int SUBMARINE_LEN 	= 3;
const int AIRCRAFT_CAR_LEN 	= 5;
const int PATROL_BOAT_LEN 	= 2;

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
	void populate_ships();
	void set_ship(int cur_ship);
	void init_board();
	void print_boards();
	std::string get_ship_name(int ship);
	int get_ship_row();
	int get_ship_col();
	bool ship_vertical();
	bool is_valid_placement(int ship, bool vert, int row, int col);
	bool in_bounds(int row, int col);

	bool comp_player;
	bool is_defeated;

	std::vector<Ship> ship_list;	
	char board[BOARD_DIM][BOARD_DIM];
	char guess_board[BOARD_DIM][BOARD_DIM];
};

#endif
