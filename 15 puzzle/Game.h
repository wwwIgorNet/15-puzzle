#pragma once
using namespace std; 

const size_t ROW = 4;
const size_t CELL = 4;

void init_game();
bool exist_number(int board[ROW][CELL], int n);
void init_board(int board[ROW][CELL]);
void clear_board(int board[ROW][CELL]);
void validate_coord(int& row, int& cell);
bool validate_game(int board[ROW][CELL]);