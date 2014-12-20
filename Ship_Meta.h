#ifndef SHIP_META_H
#define SHIP_META_H

#include <iostream>

class Ship {

public:
	Ship();
	Ship(bool is_vert, int length);
	void place_ship(int new_row, int new_col);

	int get_row() {return row;}
	int get_col() {return col;}
	int get_len() {return len;}
	bool is_sunk() {return sunk;}
	void set_sunk() {sunk = true;}
	bool is_vert() {return vert;}
private:
	int row;
	int col;
	int len;

	// true if the ship runs vertically
	bool vert;
	bool sunk;
};

#endif
