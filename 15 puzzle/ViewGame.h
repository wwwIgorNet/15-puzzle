#pragma once
#include <Windows.h>
#include "Game.h"
using namespace std;

unsigned const char c[] = {
	'\xC9', // ╔ 0
	'\xCD', // ═ 1
	'\xD1', // ╤ 2
	'\xBB', // ╗ 3
	'\xBA', // ║ 4
	'\xB3', // │ 5
	'\xC7', // ╟ 6
	'\xC4', // ─ 7
	'\xC5', // ┼ 8
	'\xB6', // ╢ 9
	'\xC8', // ╚ 10
	'\xCD', // ═ 11
	'\xCF', // ╧ 12
	'\xBC', // ╝ 13
	'\xB0', // ░ 14
	'\xB1'  // ▒ 15
};
const size_t WIDTH = 23;
const size_t HEIGHT = 17;
enum keys { ENTER = 13, ESC = 27, UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };

void init_line(char* line, char start, char c, char cellDelimeter, char end);
void init_screen_buffer(char screen_buffer[HEIGHT][WIDTH]);
void set_data(char* line, int data[]);
void add_number_to_screen_buffer(char screen_buffer[HEIGHT][WIDTH], int board[][CELL]);
void draw_screen_buffer(char screen_buffer[HEIGHT][WIDTH]);
void exclusion_cell(char screen_buffer[HEIGHT][WIDTH], size_t row, size_t cell, char c);
bool show_menu(HANDLE h, int x, int y);
void show_help(HANDLE h, int x, int y);