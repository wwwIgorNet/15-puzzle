#include <Windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include "Game.h"
#include "ViewGame.h"
using namespace std;

const int WIDTH_CELL = 5;
const int HEIGHT_CELL = 4;

void init_line(char* line, char start, char c, char cellDelimeter, char end) {
	for (size_t i = 0; i < WIDTH; i++) {
		switch (i)
		{
		case 0:
			line[i] = start;
			break;
		case WIDTH_CELL:
		case WIDTH_CELL * 2:
		case WIDTH_CELL * 3:
			line[i] = cellDelimeter;
			break;
		case WIDTH - 3:
			line[i] = end;
			break;
		case WIDTH - 2:
			line[i] = '\n';
			break;
		case WIDTH - 1:
			line[i] = '\0';
			break;
		default:
			line[i] = c;
			break;
		}
	}
}
void init_screen_buffer(char screen_buffer[HEIGHT][WIDTH]) {
	for (size_t i = 0; i < HEIGHT; i++)
	{
		switch (i)
		{
		case 0:
			// ╔════╤════╤════╤════╗
			init_line(screen_buffer[i], c[0], c[1], c[2], c[3]);
			break;
		case HEIGHT_CELL:
		case HEIGHT_CELL * 2:
		case HEIGHT_CELL * 3:
			// ╟────┼────┼────┼────╢
			init_line(screen_buffer[i], c[6], c[7], c[8], c[9]);
			break;
		case HEIGHT - 1:
			// ╚════╧════╧════╧════╝
			init_line(screen_buffer[i], c[10], c[11], c[12], c[13]);
			break;
		default:
			// ║    │    │    │    ║
			init_line(screen_buffer[i], c[4], ' ', c[5], c[4]);
			break;
		}
	}
}
void set_data(char* line, int data[]) {
	for (size_t i = 0; i < ROW; i++) {
		char c = line[4 + i * WIDTH_CELL];
		if (data[i] == 0) {
			*(line + 2 + i * WIDTH_CELL) = c;
			*(line + 3 + i * WIDTH_CELL) = c;
			continue;
		}
		_itoa_s(data[i] / 10, &line[2 + i * WIDTH_CELL], 2, 10);
		_itoa_s(data[i] % 10, &line[3 + i * WIDTH_CELL], 2, 10);
		line[4 + i * WIDTH_CELL] = c;
	}
}
void add_number_to_screen_buffer(char screen_buffer[HEIGHT][WIDTH], int board[][CELL]) {
	for (size_t i = 0; i < ROW; i++) {
		set_data(screen_buffer[i * ROW + 2], board[i]);
	}
}
void draw_screen_buffer(char screen_buffer[HEIGHT][WIDTH]) {
	for (size_t i = 0; i < HEIGHT; i++) {
		cout << screen_buffer[i];
	}
}
void exclusion_cell(char screen_buffer[HEIGHT][WIDTH], size_t row, size_t cell, char c) {
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 4; j++) {
			screen_buffer[i + row * HEIGHT_CELL + 1][j + cell * WIDTH_CELL + 1] = c;
		}
	}
}
bool show_menu(HANDLE h, int x, int y) {
	int menuIndex = 0;
	bool exit = false;
	bool enter = false;
	COORD c = { x, y };
	while (!enter) {
		SetConsoleCursorPosition(h, c);
		CONSOLE_SCREEN_BUFFER_INFO csbf;
		GetConsoleScreenBufferInfo(h, &csbf);

		if (menuIndex == 0) {
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		}
		cout << "New Game" << endl;
		SetConsoleTextAttribute(h, csbf.wAttributes);
		if (menuIndex == 1) {
			SetConsoleTextAttribute(h, FOREGROUND_GREEN);
		}
		cout << "Exit" << endl;
		SetConsoleTextAttribute(h, csbf.wAttributes);
		switch (_getch())
		{
		case UP: menuIndex = 0;
			break;
		case DOWN: menuIndex = 1;
			break;
		case ENTER:
		case ESC:
			enter = true;
			exit = menuIndex == 0 ? false : true;
			break;
		}
	}
	SetConsoleCursorPosition(h, c);
	cout << "        " << endl;
	cout << "        " << endl;
	return exit;
}
void show_help(HANDLE h, int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(h, coord);
	cout << "HELP" << endl;
	cout << "Move: arrow to left, right, up and down." << endl;
	cout << "Select a tiles: press enter." << endl;
	cout << "Unselect the tiles: press ENTER twice." << endl;
	cout << "Finish the game: press ESC" << endl;
}

