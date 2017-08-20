#include <time.h>
#include <stdlib.h>
#include "Game.h"
using namespace std;

void init_game() {
	srand(unsigned(time(NULL)));
	rand();
}
bool exist_number(int board[ROW][CELL], int n) {
	for (size_t i = 0; i < ROW; i++) {
		for (size_t j = 0; j < CELL; j++) {
			if (n == board[i][j]) {
				return true;
			}
		}
	}
	return false;
}
void init_board(int board[ROW][CELL]) {
	for (size_t i = 0; i < ROW; i++) {
		for (size_t j = 0; j < CELL; j++) {
			int n;
			do {
				n = rand() % 16;
			} while (exist_number(board, n));
			board[i][j] = n;
		}
	}


	/*int z = 0;
	for (size_t i = 0; i < ROW; i++) {
		for (size_t j = 0; j < CELL; j++) {
			board[i][j] = ++z;
		}
	}
	board[3][2] = 0;
	board[3][3] = 15;*/
}
void clear_board(int board[ROW][CELL]) {
	for (size_t i = 0; i < ROW; i++) {
		for (size_t j = 0; j < CELL; j++) {
			board[i][j] = -1;
		}
	}
}
void validate_coord(int& row, int& cell) {
	if (row < 0) row = 0;
	else if (cell < 0) cell = 0;
	else if (row >= ROW) row = ROW - 1;
	else if (cell >= CELL) cell = CELL - 1;
}
bool validate_game(int board[ROW][CELL]) {
	int n = 1;
	for (size_t i = 0; i < ROW; i++) {
		for (size_t j = 0; j < CELL; j++) {
			if (i == ROW - 1 && j == CELL - 1) break;
			if (board[i][j] != n++) return false;
		}
	}
	if (board[ROW - 1][CELL - 1] != 0) return false;
	return true;
}