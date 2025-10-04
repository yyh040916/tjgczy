/*2351495 ������ ��ҵ��*/
#include"pullze.h"
void my_sleep(bool with_hints)
{
    if (!with_hints)
        Sleep(10);
}
void set_console(int game_data[][MAX_SIZE], int size, bool with_separator, bool with_hints,bool game_mode = false)
{
    int start_x = 0, start_y = 0;
    int hint_width = 0, hint_height = 0;
    if (!with_hints)
    {
        start_x = 2;
        start_y = 1;
    }
    else
    {
        int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
        int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
        calculate_all_hints(size, game_data, row_hints, col_hints);
        calculate_hint_dimensions(size, row_hints, col_hints, &hint_width, &hint_height);
        start_x = hint_width * 2 + 6;
        start_y = hint_height + 3;
    }
    int data_x = start_x + 2;
    int data_y = start_y + 2;
    int cell_size = with_separator ? 8 : 2;
    int row_height = with_separator ? 4 : 1;
    int data_right = data_x + size * cell_size - 1;
    int data_bottom = data_y + size * row_height - 1;
    int font_size;
    if (!with_separator)
    {
        font_size = 36;
    }
    else
    {
        if (size <= 5)
        {
            font_size = 24;
        }
        else if (size <= 10)
        {
            font_size = 16;
        }
        else
        {
            font_size = 12;
        }
    }
    cct_setfontsize("������", font_size);
    int frame_right = start_x + 2 + size * cell_size + 1;
    int frame_bottom = start_y + 2 + size * row_height + 1;
    int info_area_height = 8;
    int total_width = 0;
    if(game_mode)
        total_width = frame_right + 20;
    else
        total_width = frame_right + 2;
    int total_height = frame_bottom + info_area_height;

    cct_setconsoleborder(total_width, total_height, total_width, total_height);
}
// ����Ϸ��ܵ�ͳһ����
void draw_game_frame(int game_data[][MAX_SIZE],int size,bool with_separator, bool with_hints)
{
    cct_cls();
    cct_setcursor(CURSOR_INVISIBLE);
    int start_x=0, start_y=0;
    if (!with_hints)
    {
        start_x = 2;
        start_y = 1;
    }
    else
    {
        int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
        int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
        calculate_all_hints(size, game_data, row_hints, col_hints);
        int hint_width = 0, hint_height = 0;
        calculate_hint_dimensions(size, row_hints, col_hints, &hint_width, &hint_height);
        int col_sx = hint_width * 2 + 6, col_sy = 1;
        int row_sx = 0, row_sy = hint_height + 4;
        start_x = hint_width * 2 + 6;
        start_y = hint_height + 3;
    }
    cct_gotoxy(start_x, start_y);
    int st = (with_separator) ? 8 : 2;
    int label_sx = start_x + 2 * (with_separator ? 2 : 1);
    cct_showstr(start_x, start_y, " ", COLOR_BLACK, COLOR_BLACK, 2 * (with_separator ? 2 : 1));
    cct_showstr(start_x, start_y+1, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
    if (!with_separator)
    {
        for (int i = 0; i < size; i++)
        {
            if (!with_hints)
            {
                cct_showch(label_sx + i * st, start_y, (char)('a' + i), COLOR_BLACK, COLOR_HWHITE, 1);
                cct_showch(label_sx + i * st + 1, start_y, ' ', COLOR_BLACK, COLOR_HWHITE, st - 1);
            }
            else
            {
                cct_showch(label_sx + i * st, start_y, ' ', COLOR_HWHITE, COLOR_HWHITE, 1);
                cct_showch(label_sx + i * st + 1, start_y, (char)('a' + i), COLOR_HWHITE, COLOR_BLACK, 1);
                cct_showch(label_sx + i * st + 2, start_y, ' ', COLOR_HWHITE, COLOR_HWHITE, st - 1);
            }
        }
        cct_showstr(start_x+2, start_y + 1, "�T", COLOR_HWHITE, COLOR_BLACK, size);
        cct_showstr(start_x +2+ size * st, start_y + 1, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
        for (int i = 0; i < size; i++)
        {
            if (!with_hints)
                cct_showch(start_x-2,start_y+2+i,(char)('A'+i),COLOR_BLACK, COLOR_HWHITE, 1);
            else
            {
                cct_showstr(start_x-2, start_y + 2 + i, " ", COLOR_HWHITE, COLOR_HWHITE, 1);
                cct_showch(start_x - 1, start_y + 2 + i, (char)('A' + i), COLOR_HWHITE, COLOR_BLACK, 1);
            }
            if (!with_hints)
                cct_showstr(start_x , start_y + 2 + i, " ", COLOR_BLACK, COLOR_BLACK, 1);
            else
                cct_showstr(start_x , start_y + 2 + i, " ", COLOR_HWHITE, COLOR_HWHITE, 1);
            cct_showstr(start_x , start_y + 2 + i, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(start_x + 1, start_y + 2 + i, " ", COLOR_HWHITE, COLOR_BLACK, 2 * size+1);
            cct_showstr(start_x+2*size+2, start_y + 2 + i, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
            my_sleep(with_hints);
        }
        cct_showstr(start_x, start_y + 2+size, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
        cct_showstr(start_x + 2, start_y + 2+size, "�T", COLOR_HWHITE, COLOR_BLACK, size);
        cct_showstr(start_x + 2 + size * st, start_y + 2+size, "�a", COLOR_HWHITE, COLOR_BLACK, 1);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (!with_hints)
            {
                cct_showch(label_sx + i * st, start_y, (char)('a' + i), COLOR_BLACK, COLOR_HWHITE, 1);
                cct_showch(label_sx + i * st + 1, start_y, ' ', COLOR_BLACK, COLOR_HWHITE, st - 1);
            }
            else
            {
                cct_showch(label_sx + i * st-2, start_y, ' ', COLOR_HWHITE, COLOR_HWHITE, 3);
                cct_showch(label_sx + i * st , start_y, (char)('a' + i), COLOR_HWHITE, COLOR_BLACK, 1);
                cct_showch(label_sx + i * st + 1, start_y, ' ', COLOR_HWHITE, COLOR_HWHITE, 5);
            }
        }
        cct_showstr(start_x + 2 , start_y + 1, "�T�T�T�j", COLOR_HWHITE, COLOR_BLACK,size-1);
        cct_showstr(start_x + 2+ (size - 1) * st, start_y + 1, "�T�T�T�[", COLOR_HWHITE, COLOR_BLACK, 1);
        for (int i = 0; i < size; i++)
        {
            for (int sub_row = 0; sub_row < 4; sub_row++)
            {
                if (sub_row == 1)
                    if (!with_hints)
                        cct_showch(start_x - 2, start_y + 2 + i * 4 + 1, (char)('A' + i), COLOR_BLACK, COLOR_HWHITE, 1);
               if (sub_row == 3 && i < size - 1)
               {
                   cct_showstr(start_x, start_y + 2 + i * 4 + sub_row, "�d", COLOR_HWHITE, COLOR_BLACK, 1);
                   cct_showstr(start_x + 2, start_y + 2 + i * 4 + sub_row, "�T�T�T�p", COLOR_HWHITE, COLOR_BLACK, size - 1);
                   cct_showstr(start_x +size *st-6, start_y + 2 + i * 4 + sub_row,"�T�T�T�g", COLOR_HWHITE, COLOR_BLACK, 1);
                   my_sleep(with_hints);
               }
               else if (sub_row == 3 && i == size - 1)
               {
                   cct_showstr(start_x, start_y + 2 + i * 4 + sub_row, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
                   cct_showstr(start_x + 2, start_y + 2 + i * 4 + sub_row, "�T�T�T�m", COLOR_HWHITE, COLOR_BLACK, size - 1);
                   cct_showstr(start_x + size * st - 6, start_y + 2 + i * 4 + sub_row, "�T�T�T�a", COLOR_HWHITE, COLOR_BLACK, 1);
                   my_sleep(with_hints);
               }
               else
               {
                   cct_showstr(start_x, start_y + 2 + i * 4 + sub_row, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
                   cct_showstr(start_x+2, start_y + 2 + i * 4 + sub_row, "      �U", COLOR_HWHITE, COLOR_BLACK, size);
                   my_sleep(with_hints);
               }
            }
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
}
// ����ʾ����ͳһ����
void draw_hints_area(int game_data[][MAX_SIZE], int size,bool with_separator)
{
    cct_setcursor(CURSOR_INVISIBLE);
    int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
    int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
    calculate_all_hints(size, game_data, row_hints, col_hints);
    int hint_width = 0, hint_height = 0;
    calculate_hint_dimensions(size, row_hints, col_hints, &hint_width, &hint_height);
    int col_sx = hint_width * 2 + 6, col_sy = 1;
    int row_sx = 0, row_sy = hint_height + 4;
    int st = (with_separator) ? 8 : 2;
    cct_showstr(col_sx, col_sy, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
    cct_showstr(row_sx, row_sy, "�X", COLOR_HWHITE, COLOR_BLACK, 1);
    cct_showstr(row_sx + 2, row_sy, "�T", COLOR_HWHITE, COLOR_BLACK, hint_width);
    cct_showstr(row_sx + 2 + 2 * hint_width, row_sy, "�j�T�p", COLOR_HWHITE, COLOR_BLACK, 1);
    if (!with_separator)
    {
        //��
        cct_showstr(col_sx + 2, col_sy, "�T", COLOR_HWHITE, COLOR_BLACK, size);
        cct_showstr(col_sx + size * st + 2, col_sy, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
        for (int i = 0; i < hint_height; i++)
        {
            cct_showstr(col_sx, col_sy + 1 + i, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(col_sx + 2, col_sy + 1 + i, " ", COLOR_HWHITE, COLOR_HWHITE, size * st);
            cct_showstr(col_sx + 2 + size * st, col_sy + 1 + i, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
        }
        for (int j = 0; j < size; j++)
        {
            int col_len = 0;
            for (int i = 0; i < MAX_HINTS && col_hints[i][j] != 0; i++)
                col_len++;
            for (int i = 0; i < col_len; i++)
                cct_showch(col_sx + 2 + j * st + 1, col_sy + hint_height - col_len + i + 1, '0' + col_hints[i][j], COLOR_HWHITE, COLOR_BLACK, 1);
        }
         cct_showstr(col_sx, col_sy+hint_height+1, "�d", COLOR_HWHITE, COLOR_BLACK, 1);
         cct_showstr(col_sx + 2, col_sy + hint_height + 1, "�T", COLOR_HWHITE, COLOR_BLACK, size);
         cct_showstr(col_sx + size * st + 2, col_sy + hint_height + 1, "�g", COLOR_HWHITE, COLOR_BLACK, 1);
         cct_showstr(col_sx, col_sy + hint_height + 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
         cct_showstr(col_sx + size * st + 2, col_sy + hint_height + 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
         cct_showstr(col_sx + size * st + 2, col_sy + hint_height + 3, "�g", COLOR_HWHITE, COLOR_BLACK, 1);
        //��
        for (int i = 0; i < size; i++)
        {
            cct_showstr(row_sx, row_sy + i + 1, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(row_sx + 2, row_sy + i + 1, " ", COLOR_HWHITE, COLOR_HWHITE, 2 * hint_width);
            cct_showstr(row_sx + 2 + 2 * hint_width, row_sy + i + 1, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
        }
        for (int i = 0; i < size; i++)
        {
            int row_len = 0;
            for (int j = 0; j < MAX_HINTS && row_hints[i][j] != 0; j++)
                row_len++;
            for (int j = 0; j < row_len; j++)
                cct_showch(row_sx + 2 + 2 * hint_width - 2 - 2 * (row_len - 1 - j), row_sy + i + 1, '0' + row_hints[i][j], COLOR_HWHITE, COLOR_BLACK, 1);
        }
        cct_showstr(row_sx, row_sy + size + 1, "�^", COLOR_HWHITE, COLOR_BLACK, 1);
        cct_showstr(row_sx + 2, row_sy + size + 1, "�T", COLOR_HWHITE, COLOR_BLACK, hint_width);
        cct_showstr(row_sx + 2 + 2 * hint_width, row_sy + size + 1, "�m�T�m", COLOR_HWHITE, COLOR_BLACK, 1);
    }
    else
    {
        cct_showstr(col_sx + 2, col_sy, "�T", COLOR_HWHITE, COLOR_BLACK, size*st/2-1);
        cct_showstr(col_sx + size * st , col_sy, "�[", COLOR_HWHITE, COLOR_BLACK, 1);
        for (int i = 0; i < hint_height; i++)
        {
            cct_showstr(col_sx, col_sy + 1 + i, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(col_sx + 2, col_sy + 1 + i, " ", COLOR_HWHITE, COLOR_HWHITE, size * st-2);
            cct_showstr(col_sx  + size * st, col_sy + 1 + i, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
        }
        for (int j = 0; j < size; j++)
        {
            int col_len = 0;
            for (int i = 0; i < MAX_HINTS && col_hints[i][j] != 0; i++)
                col_len++;
            for (int i = 0; i < col_len; i++)
                cct_showch(col_sx  + j * st +st/2, col_sy + hint_height - col_len + i + 1, '0' + col_hints[i][j], COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(col_sx, col_sy + hint_height + 1, "�d", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(col_sx + 2, col_sy + hint_height + 1, "�T", COLOR_HWHITE, COLOR_BLACK, size * st / 2 - 1);
            cct_showstr(col_sx + size * st, col_sy + hint_height + 1, "�g", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(col_sx, col_sy + hint_height + 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(col_sx + size * st, col_sy + hint_height + 2, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(col_sx + size * st, col_sy + hint_height + 3, "�g", COLOR_HWHITE, COLOR_BLACK, 1);
            for (int i = 0; i < size; i++)
            {
                for (int k = 0; k < 4; k++)
                {
                    cct_showstr(row_sx, row_sy + 4 * i + k + 1, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
                    cct_showstr(row_sx + 2, row_sy + 4 * i + k + 1, " ", COLOR_HWHITE, COLOR_HWHITE, 2 * hint_width);
                    cct_showstr(row_sx + 2 + 2 * hint_width, row_sy + 4 * i + k + 1, "�U", COLOR_HWHITE, COLOR_BLACK, 1);
                    cct_showstr(row_sx + 4 + 2 * hint_width, row_sy + 4 * i + k + 1, " ", COLOR_HWHITE, COLOR_HWHITE, 2);
                }
                cct_showch(row_sx + 5 + 2 * hint_width, row_sy + 4 * i + 2, (char)('A' + i), COLOR_HWHITE, COLOR_BLACK, 1);
            }
            for (int i = 0; i < size; i++)
            {
                int row_len = 0;
                for (int j = 0; j < MAX_HINTS && row_hints[i][j] != 0; j++)
                    row_len++;
                for (int j = 0; j < row_len; j++)
                    cct_showch(row_sx + 2 + 2 * hint_width - 2 - 2 * (row_len - 1 - j), row_sy + 4 * i + 2, '0' + row_hints[i][j], COLOR_HWHITE, COLOR_BLACK, 1);
            }
            cct_showstr(row_sx, row_sy + 4 * size , "�^", COLOR_HWHITE, COLOR_BLACK, 1);
            cct_showstr(row_sx + 2, row_sy + 4 * size , "�T", COLOR_HWHITE, COLOR_BLACK, hint_width);
            cct_showstr(row_sx + 2 + 2 * hint_width, row_sy + 4 * size , "�m�T�m", COLOR_HWHITE, COLOR_BLACK, 1);
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
}
// �����ͳһ����
void draw_game_ball(int game_data[][MAX_SIZE], int size, bool with_separator, bool with_hints)
{
    cct_setcursor(CURSOR_INVISIBLE);
    int ball_startx = 0, ball_starty = 0;
    if (!with_hints)
    {
        ball_startx = 4;
        ball_starty = 3;
    }
    else
    {
        int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
        int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
        calculate_all_hints(size, game_data, row_hints, col_hints);
        int hint_width = 0, hint_height = 0;
        calculate_hint_dimensions(size, row_hints, col_hints, &hint_width, &hint_height);
        int col_sx = hint_width * 2 + 6, col_sy = 1;
        int row_sx = 0, row_sy = hint_height + 4;
        ball_startx = hint_width * 2 + 8;
        ball_starty = hint_height + 5;
    }
    if (!with_separator)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (game_data[i][j])
                {
                    cct_showstr(ball_startx+j*2,ball_starty+i,"��", COLOR_HBLUE, COLOR_BLACK, 1);
                }
                my_sleep(with_hints);
            }
        }
    }
    else
    {
        const char* patterns[] = { "�X�T�[", "�U���U", "�^�T�a" };
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (game_data[i][j])
                {
                    for (int k = 0; k < 3; k++)
                    {
                        cct_showstr(ball_startx+8*j,ball_starty+4*i+k,patterns[k], COLOR_HBLUE, COLOR_BLACK, 1);
                    }
                    my_sleep(with_hints);
                }
            }
        }
    }
    int curr_x, curr_y;
    cct_getxy(curr_x, curr_y);
    cct_gotoxy(0, curr_y + 3);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
}
//���ͼ���
void handle_mouse_keyboard(int size, bool with_separator, bool with_hints, int game_data[][MAX_SIZE])
{
    int start_x = 0, start_y = 0;
    int hint_width = 0, hint_height = 0;
    if (!with_hints)
    {
        start_x = 2;
        start_y = 1;
    }
    else
    {
        int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
        int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
        calculate_all_hints(size, game_data, row_hints, col_hints);
        calculate_hint_dimensions(size, row_hints, col_hints, &hint_width, &hint_height);
        start_x = hint_width * 2 + 6;
        start_y = hint_height + 3;
    }
    int data_x = start_x + 2;
    int data_y = start_y + 2;
    int cell_size = with_separator ? 8 : 2;
    int row_height = with_separator ? 4 : 1;
    int data_right = data_x + size * cell_size - 1;
    int data_bottom = data_y + size * row_height - 1;
    int info_x = start_x;
    int info_y = data_bottom + 2;
    cct_showstr(0, 0, "���Լ���/������/�Ҽ������س��˳�", COLOR_BLACK, COLOR_HWHITE, 1);
    cct_enable_mouse();
    cct_setcursor(CURSOR_INVISIBLE);
    int loop = 1;
    while (loop)
    {
        int X, Y, maction, keycode1, keycode2;
        int ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_MOUSE_EVENT)
        {
            cct_gotoxy(info_x, info_y);
            cout << "[��ǰ���] ";
            bool valid_position = false;
            int row = -1, col = -1;
            if (X >= data_x && X <= data_right && Y >= data_y && Y <= data_bottom) 
            {
                col = (X - data_x) / cell_size;
                row = (Y - data_y) / row_height;
                if (with_separator && (((X - data_x - 6) % 8 == 0) ||((X - data_x - 7) % 8 == 0) ||((Y - data_y - 3) % 4 == 0))) 
                    valid_position = false;
                else if (row >= 0 && row < size && col >= 0 && col < size)
                    valid_position = true;
            }
            if (valid_position) 
            {
                cct_gotoxy(info_x + 11, info_y);
                cout << (char)('A' + row) << "��" << (char)('a' + col) << "��       ";
            }
            else 
            {
                cct_gotoxy(info_x + 11, info_y);
                cout << "λ�÷Ƿ�         ";
            }
            switch (maction) 
            {
            case MOUSE_ONLY_MOVED:
                break;
            case MOUSE_LEFT_BUTTON_CLICK:
                cct_gotoxy(info_x, info_y);
                if (valid_position)
                    cout << "[�������] " << (char)('A' + row) << "��" << (char)('a' + col) << "��          ";
                else
                    cout << "[�������] λ�÷Ƿ�                              ";
                break;
            case MOUSE_RIGHT_BUTTON_CLICK:
                cct_gotoxy(info_x, info_y);
                if (valid_position)
                    cout << "[�����Ҽ�] " << (char)('A' + row) << "��" << (char)('a' + col) << "��           ";
                else
                    cout << "[�����Ҽ�] λ�÷Ƿ�                ";
                break;
            }
        }
        else if (ret == CCT_KEYBOARD_EVENT)
        {
            cct_gotoxy(info_x, info_y);
            cout << "[��������]              ";
            switch (keycode1) 
            {
            case 13: // �س���
                cct_gotoxy(info_x, info_y);
                cout << "[�����س���]            ";
                loop = 0;
                cct_gotoxy(info_x, info_y + 1);
                break;
            case 224: // �����
                switch (keycode2) 
                {
                case 72:
                    cct_gotoxy(info_x, info_y);
                    cout << "[�����ϼ�ͷ]              ";
                    break;
                case 80:
                    cct_gotoxy(info_x, info_y);
                    cout << "[�����¼�ͷ]        ";
                    break;
                case 75:
                    cct_gotoxy(info_x, info_y);
                    cout << "[�������ͷ]           ";
                    break;
                case 77:
                    cct_gotoxy(info_x, info_y);
                    cout << "[�����Ҽ�ͷ]           ";
                    break;
                }
                break;
            default: // ������
                cct_gotoxy(info_x + 11, info_y);
                if (keycode2)
                    cout << keycode1 << '/' << keycode2 << "                       ";
                else
                    cout << keycode1 << "/0                        ";
                break;
            }
        }
    }
    cct_disable_mouse();
}
//D����
void D_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    generate_balls(game_data, size);
    set_console(game_data, size, false, false);
    draw_game_frame(game_data,size,false,false);
    draw_game_ball(game_data, size, false,false);
    wait_for_end();
}
//E����
void E_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    generate_balls(game_data, size);
    set_console(game_data, size, false, true);
    draw_game_frame(game_data, size, false, true);
    draw_hints_area(game_data, size, false);
    draw_game_ball(game_data, size, false, true);
    wait_for_end();
}
//F����
void F_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    generate_balls(game_data, size);
    set_console(game_data, size, false, true);
    draw_game_frame(game_data, size, false, true);
    draw_hints_area(game_data, size, false);
    draw_game_ball(game_data, size, false, true);
    handle_mouse_keyboard(size, false, true, game_data);
    wait_for_end();
}
//H����
void H_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    generate_balls(game_data, size);
    set_console(game_data, size, true, false);
    draw_game_frame(game_data,size, true, false);
    draw_game_ball(game_data, size, true, false);
    wait_for_end();
}
//I����
void I_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    generate_balls(game_data, size);
    set_console(game_data, size, true, true);
    draw_game_frame(game_data, size, true, true);
    draw_hints_area(game_data, size, true);
    draw_game_ball(game_data, size, true, true);
    wait_for_end();
}
//J����
void J_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    generate_balls(game_data, size);
    set_console(game_data, size, true, true);
    draw_game_frame(game_data, size, true, true);
    draw_hints_area(game_data, size, true);
    draw_game_ball(game_data, size, true, true);
    handle_mouse_keyboard(size, true, true, game_data);
    wait_for_end();
}
// ���״̬����
const int MARK_NONE = 0;
const int MARK_LEFT = 1;
const int MARK_RIGHT = 2;
// ��Ϸ��ʾ����
void display(int size, int game_data[][MAX_SIZE], int user_marks[][MAX_SIZE],bool with_separator, bool with_hints, bool cheat_mode)
{
    int ball_startx = 0, ball_starty = 0;
    if (!with_hints) 
    {
        ball_startx = 4;
        ball_starty = 3;
    }
    else 
    {
        int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
        int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
        calculate_all_hints(size, game_data, row_hints, col_hints);
        int hint_width = 0, hint_height = 0;
        calculate_hint_dimensions(size, row_hints, col_hints, &hint_width, &hint_height);
        ball_startx = hint_width * 2 + 8;
        ball_starty = hint_height + 5;
    }
    if (!with_separator) 
    {
        for (int i = 0; i < size; i++) 
        {
            for (int j = 0; j < size; j++) 
            {
                int x = ball_startx + j * 2;
                int y = ball_starty + i;
                if (cheat_mode)
                {
                    if (user_marks[i][j] == MARK_NONE) 
                    {
                        if (game_data[i][j] == 1)
                            cct_showstr(x, y, "��", COLOR_WHITE, COLOR_BLACK, 1);
                        else 
                            cct_showstr(x, y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
                    }
                    else if (user_marks[i][j] == MARK_LEFT) 
                    {
                        if (game_data[i][j] == 1)
                            cct_showstr(x, y, "��", COLOR_HBLUE, COLOR_BLACK, 1);
                        else
                            cct_showstr(x, y, "��", COLOR_HRED, COLOR_BLACK, 1);
                    }
                    else if (user_marks[i][j] == MARK_RIGHT)
                    {
                        if (game_data[i][j] == 0)
                            cct_showstr(x, y, "��", COLOR_HRED, COLOR_BLACK, 1);
                        else
                            cct_showstr(x, y, "��", COLOR_HBLUE, COLOR_BLACK, 1);
                    }
                }
                else 
                {
                    if (user_marks[i][j] == MARK_LEFT)
                        cct_showstr(x, y, "��", COLOR_HBLUE, COLOR_BLACK, 1);
                    else if (user_marks[i][j] == MARK_RIGHT)
                        cct_showstr(x, y, "��", COLOR_HRED, COLOR_BLACK, 1);
                    else
                        cct_showstr(x, y, "  ", COLOR_HWHITE, COLOR_BLACK, 1);
                }
            }
        }
    }
    else 
    {
        const char* ball_patterns[] = { "�X�T�[", "�U��U", "�^�T�a" };
        const char* cross_patterns[] = { "�X�T�[", "�U���U", "�^�T�a" };
        const char* empty_patterns[] = { "      ", "      ", "      " };

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int x = ball_startx + 8 * j;
                int y = ball_starty + 4 * i;
                if (cheat_mode)
                {
                    if (user_marks[i][j] == MARK_NONE && game_data[i][j] == 1)
                    {
                        for (int k = 0; k < 3; k++)
                            cct_showstr(x, y + k, ball_patterns[k], COLOR_WHITE, COLOR_BLACK, 1);
                    }
                    else if (user_marks[i][j] == MARK_LEFT)
                    {
                        int color = (game_data[i][j] == 1) ? COLOR_HBLUE : COLOR_HRED;
                        for (int k = 0; k < 3; k++)
                            cct_showstr(x, y + k, ball_patterns[k], color, COLOR_BLACK, 1);
                    }
                    else if (user_marks[i][j] == MARK_RIGHT)
                    {
                        int color = (game_data[i][j] == 0) ? COLOR_HRED : COLOR_HBLUE;
                        for (int k = 0; k < 3; k++)
                            cct_showstr(x, y + k, cross_patterns[k], color, COLOR_BLACK, 1);
                    }
                    else
                    {
                        for (int k = 0; k < 3; k++)
                            cct_showstr(x, y + k, empty_patterns[k], COLOR_HWHITE, COLOR_BLACK, 1);
                    }
                }
                else
                {
                    if (user_marks[i][j] == MARK_LEFT)
                    {
                        for (int k = 0; k < 3; k++)
                            cct_showstr(x, y + k, ball_patterns[k], COLOR_HBLUE, COLOR_BLACK, 1);
                    }
                    else if (user_marks[i][j] == MARK_RIGHT)
                    {
                        for (int k = 0; k < 3; k++)
                            cct_showstr(x, y + k, cross_patterns[k], COLOR_HRED, COLOR_BLACK, 1);
                    }
                    else
                    {
                        for (int k = 0; k < 3; k++)
                            cct_showstr(x, y + k, empty_patterns[k], COLOR_HWHITE, COLOR_BLACK, 1);
                    }
                }
            }
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
}
// ��Ϸ�߼�������
void handle_game_logic(int size, bool with_separator, bool with_hints,int game_data[][MAX_SIZE], int user_marks[][MAX_SIZE],bool* cheat_mode)
{
    int start_x = 0, start_y = 0;
    int hint_width = 0, hint_height = 0;
    if (!with_hints)
    {
        start_x = 2;
        start_y = 1;
    }
    else
    {
        int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
        int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
        calculate_all_hints(size, game_data, row_hints, col_hints);
        calculate_hint_dimensions(size, row_hints, col_hints, &hint_width, &hint_height);
        start_x = hint_width * 2 + 6;
        start_y = hint_height + 3;
    }
    int data_x = start_x + 2;
    int data_y = start_y + 2;
    int cell_size = with_separator ? 8 : 2;
    int row_height = with_separator ? 4 : 1;
    int data_right = data_x + size * cell_size - 1;
    int data_bottom = data_y + size * row_height - 1;
    int info_x = start_x;
    int info_y = data_bottom + 2;
    cct_showstr(0, 0, "���ѡ��/�Ҽ�ѡ��,Y/y�ύ,Z/z����,Q/q����", COLOR_BLACK, COLOR_HWHITE, 1);
    cct_enable_mouse();
    cct_setcursor(CURSOR_INVISIBLE);
    int loop = 1;
    while (loop)
    {
        int X, Y, maction, keycode1, keycode2;
        int ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_MOUSE_EVENT)
        {
            cct_gotoxy(info_x, info_y);
            cout << "[��ǰ���] ";
            bool valid_position = false;
            int row = -1, col = -1;
            if (X >= data_x && X <= data_right && Y >= data_y && Y <= data_bottom)
            {
                col = (X - data_x) / cell_size;
                row = (Y - data_y) / row_height;
                if (with_separator && (((X - data_x - 6) % 8 == 0) || ((X - data_x - 7) % 8 == 0) || ((Y - data_y - 3) % 4 == 0)))
                    valid_position = false;
                else if (row >= 0 && row < size && col >= 0 && col < size)
                    valid_position = true;
            }
            if (valid_position)
            {
                cct_gotoxy(info_x + 11, info_y);
                cout << (char)('A' + row) << "��" << (char)('a' + col) << "��                                                                ";
            }
            else
            {
                cct_gotoxy(info_x + 11, info_y);
                cout << "λ�÷Ƿ�                                                                  ";
            }
            switch (maction)
            {
            case MOUSE_ONLY_MOVED:
                break;
            case MOUSE_LEFT_BUTTON_CLICK:
                if (valid_position) 
                {
                    if (user_marks[row][col] == MARK_LEFT)
                        user_marks[row][col] = MARK_NONE;  // ����Ѿ��������ǣ����
                    else
                        user_marks[row][col] = MARK_LEFT;  // ������Ϊ������
                    display(size, game_data, user_marks, with_separator, with_hints, *cheat_mode);
                    cct_gotoxy(info_x, info_y);
                    cout << "[�������] " << (char)('A' + row) << "��" << (char)('a' + col) << "��                                                                   ";
                }
                else 
                {
                    cct_gotoxy(info_x, info_y);
                    cout << "[�������] λ�÷Ƿ�                                                                                       ";
                }
                break;
            case MOUSE_RIGHT_BUTTON_CLICK:
                if (valid_position) 
                {
                    if (user_marks[row][col] == MARK_RIGHT)
                        user_marks[row][col] = MARK_NONE;  // ����Ѿ����Ҽ���ǣ����
                    else
                        user_marks[row][col] = MARK_RIGHT; // ������Ϊ�Ҽ����
                    display(size, game_data, user_marks, with_separator, with_hints, *cheat_mode);
                    cct_gotoxy(info_x, info_y);
                    cout << "[�����Ҽ�] " << (char)('A' + row) << "��" << (char)('a' + col) << "��                                                                    ";
                }
                else 
                {
                    cct_gotoxy(info_x, info_y);
                    cout << "[�����Ҽ�] λ�÷Ƿ�                                                                         ";
                }
                break;
            }
        }
        else if (ret == CCT_KEYBOARD_EVENT)
        {
            if (keycode1 == 'Y' || keycode1 == 'y') 
            { // Y���ύ
                // ʹ�û�����ʾ����ȷ�Լ��
                if (check_solution_by_hints(game_data, user_marks, size, MARK_LEFT))
                {
                    cct_gotoxy(info_x, info_y );
                    cout << "[�ύ�ɹ�]                                         ";
                    cct_setcolor();
                    wait_for_end();
                    loop = 0;
                }
                else 
                {
                    int error_row, error_col;
                    if (find_first_error_position(game_data, user_marks, size, MARK_LEFT, &error_row, &error_col)) 
                    {
                        cct_gotoxy(info_x, info_y);
                        cout << "�ύʧ�ܣ�����[" << (char)('A' + error_row) << "]��[" << (char)('a' + error_col) << "]�в�����Ҫ��";
                        cct_setcolor();
                    }
                    else 
                    {
                        cct_gotoxy(info_x, info_y );
                        cout << "�ύ���󣬿�������ģʽ�鿴     ";
                    }
                    cct_setcolor();
                }
            }
            else if (keycode1 == 'Q' || keycode1 == 'q') // �˳�
            {
                loop = 0;
                cct_gotoxy(info_x, info_y);
                cout << "����Q/q����Ϸ����                           ";
                wait_for_end();
            }
            else if (keycode1 == 'Z' || keycode1 == 'z') 
            { // �л�����ģʽ
                *cheat_mode = !(*cheat_mode);
                display(size, game_data, user_marks, with_separator, with_hints, *cheat_mode);
                cct_gotoxy(info_x, info_y);
                if (*cheat_mode)
                    cout << "[����ģʽ��]                                                                       ";
                else
                    cout << "[����ģʽ��]                                                                  ";
                cct_setcolor();
            }
            else 
            {
                cct_gotoxy(info_x, info_y);
                cout << "[��������]                                                                       ";
                cct_gotoxy(info_x + 11, info_y);
                if (keycode2)
                    cout << keycode1 << '/' << keycode2 << "          ";
                else
                    cout << keycode1 << "/0         ";
            }
        }
    }
    cct_disable_mouse();
}
// G����
void G_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    int user_marks[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    init_2d_array(user_marks, size);
    generate_balls(game_data, size);
    set_console(game_data, size, false, true, true);
    bool cheat_mode = false;
    draw_game_frame(game_data, size, false, true);
    draw_hints_area(game_data, size, false);
    display(size, game_data, user_marks, false, true, cheat_mode);
    handle_game_logic(size, false, true, game_data, user_marks, &cheat_mode);
}
// K����
void K_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    int user_marks[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    init_2d_array(user_marks, size);
    generate_balls(game_data, size);
    set_console(game_data, size, true, true, true);
    bool cheat_mode = false;
    draw_game_frame(game_data, size, true, true);
    draw_hints_area(game_data, size, true);
    display(size, game_data, user_marks, true, true, cheat_mode);
    handle_game_logic(size, true, true, game_data, user_marks, &cheat_mode);
}