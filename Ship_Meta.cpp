#include <iostream>
#include "Ship_Meta.h"

using namespace std;

Ship::Ship() {
	sunk = false;
	vert = false;
	len = 0;
}

Ship::Ship(bool is_vert, int length) {
	sunk = false;
	vert = is_vert;
	len = length;
}


void Ship::place_ship(int new_row, int new_col) {
	row = new_row;
	col = new_col;
}


