#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(bool is_AI) {
	comp_player = is_AI;
	is_defeated = false;
	populate_board();
}

void Player::populate_board() {
	init_board();
	if (!comp_player) {
		for (int ship = 0; ship < NUM_SHIPS; ship++) {
			
		}
	}
	print_boards();
}

void Player::init_board() {
	for (int i=0; i<BOARD_DIM; i++) {
		for (int q=0; q<BOARD_DIM; q++) {
			board[i][q] = EMPTY_POS;
			guess_board[i][q] = EMPTY_POS;
		}
	}
}

void Player::print_boards() {

}
