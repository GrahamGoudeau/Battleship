#include <iostream>
#include <unistd.h>
#include "Player.h"

using namespace std;

bool Player::is_hit(int row, int col) {
	return board[row][col] != EMPTY_POS && 
	       board[row][col] != HIT;
}

void Player::take_turn(Player &player2) {
	print_boards();
	if (!comp_player) cout << "Guessing:\n";

	int row, col;
	row = get_ship_row();
	col = get_ship_col();
	bool hit = player2.is_hit(row, col);

	if (hit) {
		if (!comp_player) cout << "Hit!\n";

		bool sunk = successful_hit(player2, row, col);
		if (sunk) {
			char marker = player2.board[row][col];
			int index = get_ship(marker);
			string name = get_ship_name(index);
			if (!comp_player) {
				cout << "You sunk the " << name << "!\n";
				sleep(1);
			}
		}
		player2.update_own_hit(row, col);
	}
	else if (!comp_player) 
		cout << "Miss!\n";

	update_guess(hit, row, col);
	player2.update_defeated();
}

bool Player::successful_hit(Player &player2, int row, int col) {
	char marker = player2.board[row][col];
	int index = get_ship(marker);
	
	player2.ship_list[index].hit();
	return player2.ship_list[index].is_sunk();
}

void Player::update_own_hit(int row, int col) {
	board[row][col] = HIT;
}

void Player::update_guess(bool hit, int row, int col) {
	if (hit)
		guess_board[row][col] = HIT;
	else
		guess_board[row][col] = MISS;
}

void Player::update_defeated() {
	for (int i=0; i<NUM_SHIPS; i++) {
		if (!ship_list[i].is_sunk()) {
			is_defeated = false;
			return;
		}
	}
	
	is_defeated = true;
}
