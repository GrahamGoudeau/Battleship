#include <iostream>
#include "Player.h"

using namespace std;

bool Player::is_hit(int row, int col) {
	return board[row][col] != EMPTY_POS;
}

void Player::take_turn(Player player2) {
	int row, col;
	row = get_ship_row();
	col = get_ship_col();

	if (player2.is_hit(row, col)) {
		cout << "Hit!\n";
		char marker = player2.board[row][col];
		bool sunk = successful_hit(player2, row, col);
		if (sunk) {
			string name = get_ship_name(marker);
			cout << "You sunk the " << name << endl;
		}
	}
	else cout << "Miss!\n";
}

bool Player::successful_hit(Player player2, int row, int col) {
	char marker = player2.board[row][col];
	int index = get_ship(marker);
	/*Ship *hit_ship = &player2.ship_list[index];
	hit_ship->hit();
	
	return hit_ship->is_sunk();
	*/
	player2.ship_list[index].hit();
	return player2.ship_list[index].is_sunk();
}
