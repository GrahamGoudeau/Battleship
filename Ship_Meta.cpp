#include <iostream>
#include "Ship_Meta.h"

using namespace std;


Ship::Ship(bool is_vert) {
	sunk = false;
	vert = is_vert;
}


void Ship::place_ship(int new_row, int new_col) {
	row = new_row;
	col = new_col;
}


