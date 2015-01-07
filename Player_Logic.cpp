#include <iostream>
#include <unistd.h>
#include "Player.h"

using namespace std;

bool Player::is_hit(int row, int col) {
	return board[row][col] != EMPTY_POS && 
	       board[row][col] != HIT;
}

void Player::take_turn(Player &player2) {
	if (!comp_player)
		human_turn(player2);
	else
		AI_turn(player2, AI_WAIT);

	player2.update_defeated();
}

void Player::human_turn(Player &player2) {
	print_boards();
	cout << "Guessing:\n";

	int row, col;
	row = get_ship_row();
	col = get_ship_col();
	bool hit = player2.is_hit(row, col);

	if (hit) {
		cout << "Hit!\n";

		bool sunk = successful_hit(player2, row, col);
		if (sunk) {
			char marker = player2.get_marker(row, col);
			int index = get_ship(marker);
			string name = get_ship_name(index);
			 
			cout << "You sunk the " << name << "!\n";
		}
		player2.update_own_hit(row, col);
	}
	else cout << "Miss!\n";
	sleep(2);		

	update_guess(hit, row, col);
}

void Player::AI_turn(Player &player2, bool wait) {
	for (int i=0; i<100; i++) cout << "\n";
	cout << "Computer taking turn:\n";
	if (wait) sleep(1);
	cout << "Computer building probability:\n";
	build_probability();
	if(wait) sleep(1);
	cout << "Computer selecting most probable row/column:\n";
	// select row/col
	if (wait) sleep(1);
}

void Player::build_probability() {
	init_prob_board();
	bool vert = true;
	bool horiz = false;
	for (int ship=0; ship<NUM_SHIPS; ship++) {
		Ship new_ship = ship_list[ship];
		superposition(new_ship,vert);
		superposition(new_ship,horiz);
	}
	for (int i=0;i<BOARD_DIM;i++) {
		for (int q=0; q<BOARD_DIM; q++)
			cout << prob_board[i][q];
		cout << endl;
	}
}


void Player::superposition(Ship ship, bool orientation) {
	bool vert = orientation;
	for (int row=0; row<BOARD_DIM; row++) {
		for (int col=0; col<BOARD_DIM; col++) {
			if (check_possible(ship, vert, row, col)) 
				update_prob(ship, vert, row, col);
				
		}
	}
}

bool Player::check_possible(Ship ship, bool vert, int row, int col) {
	int length = ship.get_len();
	if (guess_board[row][col] != EMPTY_POS) return false;
	if (vert && (row + length >= BOARD_DIM)) return false;
	if (!vert && (col + length >= BOARD_DIM)) return false;

	for (int i=0; i<BOARD_DIM; i++) {
		for (int q=0; q<BOARD_DIM; q++) {
			if (guess_board[row][col] == MISS)
				return false;
			else if (guess_board[row][col] == HIT) {
				for (int adj = -1; adj <= 1; adj++) {}
			}
		}
	}
}

void Player::update_prob(Ship ship, bool vert, int row, int col) {
	cerr << "UPDATE PROB\n";
}

void Player::init_prob_board() {
	for (int i=0; i<BOARD_DIM; i++) 
		for (int q=0; q<BOARD_DIM; q++)
			prob_board[i][q] = 0;
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

	else if (guess_board[row][col] == EMPTY_POS)
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
