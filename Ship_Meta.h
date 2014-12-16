#ifndef SHIP_META_H
#define SHIP_META_H

#include <iostream>

class Ship {

public:
	Ship();
	bool is_sunk() {return sunk;};
	void place_ship(int new_row, int new_col);

private:
	int row;
	int col;

	// true if the ship runs vertically
	bool vert;
	bool sunk;
};

#endif
