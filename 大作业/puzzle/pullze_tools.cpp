/*2351495 ������ ��ҵ��*/
#include"pullze.h"

char main_menu()
{
	cct_cls();
	cout << "---------------------------------------------------------" << endl;
	cout << " A.�ڲ����飬ԭ�����" << endl;
	cout << " B.�ڲ����飬������ʾ���в����" << endl;
	cout << " C.�ڲ����飬��Ϸ��" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << " D.n*n�Ŀ��(�޷ָ���)��ԭ�����" << endl;
	cout << " E.n*n�Ŀ��(�޷ָ���)������ʾ����" << endl;
	cout << " F.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬������ƶ�����ʾ����" << endl;
	cout << " G.cmdͼ�ν���������(�޷ָ���)" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << " H.n*n�Ŀ��(�зָ���)��ԭ�����" << endl;
	cout << " I.n*n�Ŀ��(�зָ���)������ʾ����" << endl;
	cout << " J.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬������ƶ�����ʾ����" << endl;
	cout << " K.cmdͼ�ν���������(�зָ���)" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << " Q.�˳�" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "[��ѡ��:] ";
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
		cout << "�����������С(5/10/15) ��";
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
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "�����س�������...";
	else
		cout << "���س�������...";

	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
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
		cout << "��С�������������End����...";
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
		cout << "�����������������" << endl;
	}
}
// ���ĳһ��/�е��û�����Ƿ�������ʾ
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

// ���������Ϸ�Ƿ���ȷ��������ʾ����ԭʼλ�ã�
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
// �ҵ�һ������λ�ã������ϵ��£������ҵ�˳����ԭʼ��Ƚϣ�
bool find_first_error_position(int game_data[][MAX_SIZE], int user_marks[][MAX_SIZE], int size, int ball_mark_value, int* error_row, int* error_col)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			bool is_error = false;
			if (game_data[i][j] == 1 && user_marks[i][j] != ball_mark_value) 
			{
				is_error = true;  // Ӧ������û���
			}
			else if (game_data[i][j] == 0 && user_marks[i][j] == ball_mark_value)
			{
				is_error = true;  // ��Ӧ�����򵫱����
			}
			if (is_error)
			{
				*error_row = i;
				*error_col = j;
				return true;
			}
		}
	}
	return false;  // û�ҵ�����
}