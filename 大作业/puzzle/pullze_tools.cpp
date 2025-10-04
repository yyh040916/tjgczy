/*2351495 大数据 闫业豪*/
#include"pullze.h"

char main_menu()
{
	cct_cls();
	cout << "---------------------------------------------------------" << endl;
	cout << " A.内部数组，原样输出" << endl;
	cout << " B.内部数组，生成提示行列并输出" << endl;
	cout << " C.内部数组，游戏版" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << " D.n*n的框架(无分隔线)，原样输出" << endl;
	cout << " E.n*n的框架(无分隔线)，含提示行列" << endl;
	cout << " F.n*n的框架(无分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << " G.cmd图形界面完整版(无分隔线)" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << " H.n*n的框架(有分隔线)，原样输出" << endl;
	cout << " I.n*n的框架(有分隔线)，含提示行列" << endl;
	cout << " J.n*n的框架(有分隔线)，显示初始状态，鼠标移动可显示坐标" << endl;
	cout << " K.cmd图形界面完整版(有分隔线)" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << " Q.退出" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "[请选择:] ";
	while (1)
	{
		char choice1 = _getch();
		if ((choice1 >= 'A' && choice1 <= 'Z') || (choice1 >= 'a' && choice1 <= 'z'))
		{
			return choice1;
		}
		else
		{
			continue;
		}
	}
}
int sizechoice()
{
	cct_cls();
	while (1)
	{
		int size;
		cout << "请输入区域大小(5/10/15) ：";
		cin >> size;
		if (cin.fail()) 
		{
			cin.clear();
			cin.ignore(2048, '\n');
			continue;
		}
		if (size == 5 || size == 10|| size == 15)
		{
			cin.ignore(2048, '\n');
			return size;
		}
		else
		{
			cin.clear();
			cin.ignore(2048, '\n');
			continue;
		}
	}
}
void to_be_continued(const char* prompt, const int X, const int Y)
{
	cct_setcolor(); //恢复缺省颜色
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "，按回车键继续...";
	else
		cout << "按回车键继续...";

	/* 忽略除回车键外的所有输入（注意：_getch的回车是\r，而getchar是\n）*/
	while (_getch() != '\r')
		;

	cct_cls();
	return;
}
void wait_for_end()
{
	int cur_x, cur_y;
	cct_getxy(cur_x, cur_y);
	while (true)
	{
		cct_gotoxy(cur_x, cur_y);
		cout << "本小题结束，请输入End继续...";
		char input_chars[3] = { 0 };
		int char_count = 0;
		while (true) 
		{
			char ch = _getch();
			if (ch == '\r') 
			{ 
				break;
			}
			putchar(ch);
			if (char_count < 3) 
			{
				input_chars[char_count] = ch;
				char_count++;
			}
		}
		bool is_valid = (char_count >= 3) &&
			(input_chars[0] == 'e' || input_chars[0] == 'E') &&
			(input_chars[1] == 'n' || input_chars[1] == 'N') &&
			(input_chars[2] == 'd' || input_chars[2] == 'D');
		if (is_valid) 
		{
			break;
		}
		cct_gotoxy(cur_x + 28, cur_y);
		cout << "                    "; 
		cct_gotoxy(cur_x, cur_y + 1);
		cout << "输入错误，请重新输入" << endl;
	}
}
// 检查某一行/列的用户标记是否满足提示
bool check_line_hints(int user_marks[][MAX_SIZE], int line_index, int size, int hints[], int hint_count, bool is_row, int ball_mark_value)
{
	int user_hints[MAX_HINTS] = { 0 };
	int user_hint_count = 0;
	int consecutive_count = 0;
	for (int i = 0; i < size; i++)
	{
		int cell_value;
		if (is_row)
			cell_value = user_marks[line_index][i];
		else
			cell_value = user_marks[i][line_index];
		if (cell_value == ball_mark_value)
			consecutive_count++;
		else
		{
			if (consecutive_count > 0)
			{
				user_hints[user_hint_count++] = consecutive_count;
				consecutive_count = 0;
			}
		}
	}
	if (consecutive_count > 0)
		user_hints[user_hint_count++] = consecutive_count;
	if (hint_count == 1 && hints[0] == 0) 
	{
		return user_hint_count == 0;
	}
	if (user_hint_count != hint_count)
		return false;
	for (int i = 0; i < hint_count; i++)
	{
		if (user_hints[i] != hints[i])
			return false;
	}
	return true;
}

// 检查整个游戏是否正确（基于提示而非原始位置）
bool check_solution_by_hints(int game_data[][MAX_SIZE], int user_marks[][MAX_SIZE], int size, int ball_mark_value)
{
	int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
	int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
	calculate_all_hints(size, game_data, row_hints, col_hints);
	for (int i = 0; i < size; i++)
	{
		int hints[MAX_HINTS];
		int hint_count = 0;
		for (int j = 0; j < MAX_HINTS && row_hints[i][j] != 0; j++)
		{
			hints[hint_count++] = row_hints[i][j];
		}
		if (hint_count == 0)
		{
			hints[0] = 0;
			hint_count = 1;
		}
		if (!check_line_hints(user_marks, i, size, hints, hint_count, true, ball_mark_value))
			return false;
	}
	for (int j = 0; j < size; j++)
	{
		int hints[MAX_HINTS];
		int hint_count = 0;
		for (int i = 0; i < MAX_HINTS && col_hints[i][j] != 0; i++)
		{
			hints[hint_count++] = col_hints[i][j];
		}
		if (hint_count == 0) 
		{
			hints[0] = 0;
			hint_count = 1;
		}
		if (!check_line_hints(user_marks, j, size, hints, hint_count, false, ball_mark_value))
			return false;
	}
	return true;
}
// 找第一个错误位置（按从上到下，从左到右的顺序，与原始解比较）
bool find_first_error_position(int game_data[][MAX_SIZE], int user_marks[][MAX_SIZE], int size, int ball_mark_value, int* error_row, int* error_col)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			bool is_error = false;
			if (game_data[i][j] == 1 && user_marks[i][j] != ball_mark_value) 
			{
				is_error = true;  // 应该有球但没标记
			}
			else if (game_data[i][j] == 0 && user_marks[i][j] == ball_mark_value)
			{
				is_error = true;  // 不应该有球但标记了
			}
			if (is_error)
			{
				*error_row = i;
				*error_col = j;
				return true;
			}
		}
	}
	return false;  // 没找到错误
}