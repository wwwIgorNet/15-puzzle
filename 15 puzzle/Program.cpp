#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Game.h"
#include "ViewGame.h"
using namespace std;

void main() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false };
	SetConsoleCursorInfo(h, &cci);
	system("mode con cols=40 lines=27");//установка размеров окна консоли
	COORD coord = { 0, 0 };
	
	int board[ROW][CELL];
	char screen_buffer[HEIGHT][WIDTH];
	init_game();
	SetConsoleTitleA("Barley break");
	show_help(h, 0, HEIGHT + 5);
	init_screen_buffer(screen_buffer);

	do {
		SetConsoleCursorPosition(h, COORD{ 0, HEIGHT });
		cout << "        " << endl;

		clear_board(board);
		init_board(board);

		int row = 0, prev_row = row;
		int cell = 0, prev_cell = cell;
		bool move = false;
		int key;
		do {
			char exc;
			if (move) {
				if (board[row][cell] == 0) {
					swap(board[row][cell], board[prev_row][prev_cell]);
				}
				exc = c[15];
			}
			else exc = c[14];
			exclusion_cell(screen_buffer, row, cell, exc);

			add_number_to_screen_buffer(screen_buffer, board);

			SetConsoleCursorPosition(h, coord);
			draw_screen_buffer(screen_buffer);
			exclusion_cell(screen_buffer, row, cell, ' ');

			if (validate_game(board)) break;

			prev_row = row;
			prev_cell = cell;
			key = _getch();
			switch (key)
			{
			case UP: row--;
				break;
			case DOWN: row++;
				break;
			case LEFT: cell--;
				break;
			case RIGHT: cell++;
				break;
			case ENTER: move = !move;
				break;
			case ESC: return;
			}
			validate_coord(row, cell);
		} while (true);
		cout << "You win!" << endl;
	} while (!show_menu(h, 0, HEIGHT + 2));
}