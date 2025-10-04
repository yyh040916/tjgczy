/*2351495 大数据 闫业豪*/
#pragma once

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include<Windows.h>
#include "cmd_console_tools.h"
using namespace std;

const int MAX_SIZE = 20;  
const int MAX_HINTS =8;

char main_menu();
int sizechoice();
void to_be_continued(const char* prompt = nullptr, const int X = 0, const int Y = 22);
void wait_for_end();
void init_2d_array(int arr[][MAX_SIZE], int size);
void generate_balls(int game_data[][MAX_SIZE], int size);
void calculate_hint_dimensions(int size, int row_hints[][MAX_HINTS], int col_hints[][MAX_SIZE], int* width, int* height);
void calculate_all_hints(int size, int game_data[][MAX_SIZE], int row_hints[][MAX_HINTS], int col_hints[][MAX_SIZE]);
bool check_line_hints(int user_marks[][MAX_SIZE], int line_index, int size, int hints[], int hint_count, bool is_row, int ball_mark_value);
bool check_solution_by_hints(int game_data[][MAX_SIZE], int user_marks[][MAX_SIZE], int size, int ball_mark_value);
bool find_first_error_position(int game_data[][MAX_SIZE], int user_marks[][MAX_SIZE], int size, int ball_mark_value, int* error_row, int* error_col);
void A_function();
void B_function();
void C_function();
void D_function();
void E_function();
void F_function();
void G_function();
void H_function();
void I_function();
void J_function();
void K_function();