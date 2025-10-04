/*2351495 ������ ��ҵ��*/
#include"hanoi.h"
#include"cmd_console_tools.h"
#include"cmd_hdc_tools.h"
using namespace std;
// ȫ�ֱ���
int totalstep = 0;
int stackA[MAX_LAYER] = { 0 }, stackB[MAX_LAYER] = { 0 }, stackC[MAX_LAYER] = { 0 };
int topA = 0, topB = 0, topC = 0;
int speed = 0;
void move_disk_animation(int disk_num, char src_col, char dst_col, bool show_text_display = false);
// ��������������ջ��ָ��
void updateStackTop(char col, int newTop)
{
    switch (col)
    {
    case 'A':
        topA = newTop;
        break;
    case 'B':
        topB = newTop;
        break;
    case 'C':
        topC = newTop;
        break;
    }
}
// ������������ȡջ��ָ��
int getStackTop(char col)
{
    switch (col)
    {
    case 'A':
        return topA;
    case 'B':
        return topB;
    case 'C':
        return topC;
    default:
        return 0;
    }
}
// ������������ȡջ��������
int getStackValue(char col, int index)
{
    switch (col)
    {
    case 'A':
        return stackA[index];
    case 'B':
        return stackB[index];
    case 'C':
        return stackC[index];
    default:
        return 0;
    }
}
// ��������������ջ����ֵ
void setStackValue(char col, int index, int value)
{
    switch (col)
    {
    case 'A':
        stackA[index] = value;
        break;
    case 'B':
        stackB[index] = value;
        break;
    case 'C':
        stackC[index] = value;
        break;
    }
}
// ������������ȡ���ӵ�����X����
int getColumnCenterX(char col)
{
    switch (col)
    {
    case 'A':
        return center1_x;
    case 'B':
        return center2_x;
    case 'C':
        return center3_x;
    default:
        return center1_x;
    }
}
// ������������ȡ�������ַ������X����
int getColumnCharX(char col, int baseX)
{
    switch (col)
    {
    case 'A':
        return baseX + Underpan_A_X_OFFSET;
    case 'B':
        return baseX + Underpan_A_X_OFFSET + Underpan_Distance;
    case 'C':
        return baseX + Underpan_A_X_OFFSET + 2 * Underpan_Distance;
    default:
        return baseX + Underpan_A_X_OFFSET;
    }
}
//��ʼ��
void init(int number, char src)
{
    topA = topB = topC = 0;
    for (int i = 0; i < MAX_LAYER; i++)
        stackA[i] = stackB[i] = stackC[i] = 0;
    switch (src)
    {
    case 'A':
        for (int i = number; i >= 1; i--)
            stackA[topA++] = i;
        break;
    case 'B':
        for (int i = number; i >= 1; i--)
            stackB[topB++] = i;
        break;
    case 'C':
        for (int i = number; i >= 1; i--)
            stackC[topC++] = i;
        break;
    }
}
// ���Ƶ���
void showdizuo(int baseX, int baseY)
{
    int columnA_X = baseX + Underpan_A_X_OFFSET;
    int columnB_X = columnA_X + Underpan_Distance;
    int columnC_X = columnB_X + Underpan_Distance;
    int lineStartX = columnA_X - 2;
    int lineLength = (columnC_X - columnA_X) + 5;
    cct_gotoxy(lineStartX, baseY);
    for (int i = 0; i < lineLength; i++)
        cout << "=";
    cct_gotoxy(columnA_X, baseY + 1);
    cout << "A";
    cct_gotoxy(columnB_X, baseY + 1);
    cout << "B";
    cct_gotoxy(columnC_X, baseY + 1);
    cout << "C";
}
// ������ʾ����
void showshuiping(int x, int y, bool simple = false, int format_type = 0)
{
    if (format_type == 3) // �˵���3
    {
        const int fieldWidth = Underpan_Distance;
        cout << " A:";
        for (int i = 0; i < topA; i++)
            cout << setw(2) << stackA[i];
        for (int i = 1; i < fieldWidth - topA * 2; i++)
            cout << " ";
        cout << "B:";
        for (int i = 0; i < topB; i++)
            cout << setw(2) << stackB[i];
        for (int i = 1; i < fieldWidth - topB * 2; i++)
            cout << " ";
        cout << "C:";
        for (int i = 0; i < topC; i++)
            cout << setw(2) << stackC[i];
        cout << endl;

    }
    else if (!simple) // �˵���4
    {
        cct_gotoxy(x, y);
        cout << "                                                                                ";
        cct_gotoxy(x, y);
        cout << setw(-Underpan_A_Y_OFFSET) << " ";
        cout << " A:";
        for (int i = 0; i < MAX_LAYER; i++)
        {
            if (i < topA) 
                cout << setw(2) << stackA[i];
            else 
                cout << "  ";
        }
        cout << " B:";
        for (int i = 0; i < MAX_LAYER; i++)
        {
            if (i < topB) 
                cout << setw(2) << stackB[i];
            else 
                cout << "  ";
        }
        cout << " C:";
        for (int i = 0; i < MAX_LAYER; i++)
        {
            if (i < topC) 
                cout << setw(2) << stackC[i];
            else 
                cout << "  ";
        }
    }
    else // �˵���8
    {
        cout << "A: ";
        for (int i = 0; i < topA; i++)
            cout << stackA[i] << " ";
        cout << "   B: ";
        for (int i = 0; i < topB; i++)
            cout << stackB[i] << " ";
        cout << "   C: ";
        for (int i = 0; i < topC; i++)
            cout << stackC[i] << " ";
    }
}
// ������ʾ����
void showshuzhi(int baseX, int baseY, char src, char dst, int speed, int init,
    int colA_offset = 0, int colB_offset = 0, int colC_offset = 0)
{
    int columnA_X, columnB_X, columnC_X;
    columnA_X = baseX + Underpan_A_X_OFFSET + colA_offset;
    columnB_X = columnA_X + Underpan_Distance + colB_offset;
    columnC_X = columnB_X + Underpan_Distance + colC_offset;
    if (init == 1) //�˵���4
    {
        showdizuo(baseX, baseY);
    }
    else if (init == 2) //�˵���8/9
    {
        showdizuo(baseX, baseY);
    }
    if (init >= 1)
    {
        for (int i = 0; i < MAX_LAYER; i++)
        {
            cct_gotoxy(columnA_X - 1, baseY - 1 - i);
            cout << "  ";
            cct_gotoxy(columnB_X - 1, baseY - 1 - i);
            cout << "  ";
            cct_gotoxy(columnC_X - 1, baseY - 1 - i);
            cout << "  ";
        }
        if (init == 2)
        {
            // �˵���8/9
            for (int i = 0; i < topA; i++)
            {
                cct_gotoxy(columnA_X, baseY - 1 - i);
                cout << stackA[i] << " ";
            }
            for (int i = 0; i < topB; i++)
            {
                cct_gotoxy(columnB_X, baseY - 1 - i);
                cout << stackB[i] << " ";
            }
            for (int i = 0; i < topC; i++)
            {
                cct_gotoxy(columnC_X, baseY - 1 - i);
                cout << stackC[i] << " ";
            }
        }
        else
        {
            // �˵���4
            for (int i = 0; i < topA; i++)
            {
                cct_gotoxy(columnA_X - 1, baseY - 1 - i);
                cout << setw(2) << stackA[i];
            }
            for (int i = 0; i < topB; i++)
            {
                cct_gotoxy(columnB_X - 1, baseY - 1 - i);
                cout << setw(2) << stackB[i];
            }
            for (int i = 0; i < topC; i++)
            {
                cct_gotoxy(columnC_X - 1, baseY - 1 - i);
                cout << setw(2) << stackC[i];
            }
        }
    }
    else
    {
        // ��ʼ��Դ����Ŀ������X����
        int srcX = 0, dstX = 0;
        switch (src)
        {
        case 'A':
            srcX = columnA_X;
            break;
        case 'B':
            srcX = columnB_X;
            break;
        case 'C':
            srcX = columnC_X;
            break;
        }
        switch (dst)
        {
        case 'A':
            dstX = columnA_X;
            break;
        case 'B':
            dstX = columnB_X;
            break;
        case 'C':
            dstX = columnC_X;
            break;
        }
        // ��ȡԴ����Ŀ������ջ��
        int srcTop = getStackTop(src);
        int dstTop = getStackTop(dst);
        cct_gotoxy(srcX - 1, baseY - 1 - srcTop);
        cout << "  ";
        // ��ȡĿ��ջ��Ԫ��
        int dstStackTopValue = 0;
        switch (dst)
        {
        case 'A':
            dstStackTopValue = stackA[dstTop - 1];
            break;
        case 'B':
            dstStackTopValue = stackB[dstTop - 1];
            break;
        case 'C':
            dstStackTopValue = stackC[dstTop - 1];
            break;
        }
        cct_gotoxy(dstX - 1, baseY - 1 - (dstTop - 1));
        cout << setw(2) << dstStackTopValue;
    }
    if (speed)
        Sleep(speed);
    else if (!init)
        cin.ignore();
}
// move_disk����
void move_disk(int number, char src, char dst,
    int format_type, int show_horizontal, int show_vertical,
    int show_graphical, int automatic)
{
    // ��ȡԴջ��Ϣ
    int srcTop = getStackTop(src);
    int dstTop = getStackTop(dst);
    int disk = getStackValue(src, srcTop - 1);
    if (!show_graphical && format_type != 7 && format_type != 8)
    {
        // ��Դջ�Ƴ�Ԫ��
        setStackValue(src, srcTop - 1, 0);
        updateStackTop(src, srcTop - 1);
        // ��ӵ�Ŀ��ջ
        setStackValue(dst, dstTop, disk);
        updateStackTop(dst, dstTop + 1);
    }
    // ������7��ֻ�ƶ�����������ʾ�ı�
    if (format_type == 7)
    {
        move_disk_animation(disk, src, dst, false);
        return;
    }
    // ������8����ʾ�������ı�
    if (format_type == 8)
    {
        move_disk_animation(disk, src, dst, true);
        return;
    }
    // ����format_type
    if (format_type == 1)
        cout << number << "# " << src << "---->" << dst << endl;
    else if (format_type == 2)
        cout << "�� " << setw(3) << totalstep << " ��(" << setw(2) << number << "#: " << src << "-->" << dst << ")" << endl;
    else if (format_type == 3)
    {
        cout << "��" << setw(4) << totalstep << " ��(" << setw(2) << number << "#: " << src << "-->" << dst << ") ";
        showshuiping(0, 0, false, 3);
    }
    else if (format_type == 0)
    {
        int baseY = (show_graphical) ? MenuItem8_Start_Y : MenuItem4_Start_Y;
        if (show_horizontal)
        {
            cct_gotoxy(MenuItem4_Start_X, baseY + 1);
            cout << "��" << setw(4) << totalstep << " ��(" << setw(2) << number << "#: " << src << "-->" << dst << ")";
            showshuiping(MenuItem4_Start_X + 30, baseY + 1, false, 0);
        }
        if (show_vertical)
            showshuzhi(MenuItem4_Start_X, baseY + Underpan_A_Y_OFFSET, src, dst, speed, 0);
        if (show_graphical)
        {
            move_disk_animation(disk, src, dst, automatic);
        }
    }
}
// �ݹ麺ŵ������
void hanoi(int number, char src, char tmp, char dst,
    int format_type, int show_horizontal, int show_vertical,
    int show_graphical, int automatic)
{
    if (number == 0)
        return;
    hanoi(number - 1, src, dst, tmp, format_type, show_horizontal, show_vertical, show_graphical, automatic);
    if (format_type == 7 && number > 1)
        return;
    totalstep++;
    move_disk(number, src, dst, format_type, show_horizontal, show_vertical, show_graphical, automatic);
    hanoi(number - 1, tmp, src, dst, format_type, show_horizontal, show_vertical, show_graphical, automatic);
}
//���뺯��
void input(char* src, char* tmp, char* dst, int* number, bool need_delay, int menu_option = 0)
{
    while (true)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        if (!(cin >> *number) || *number < 1 || *number > 10)
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(2048, '\n');
        break;
    }
    while (true)
    {
        cout << "��������ʼ��(A-C)" << endl;
        if (!(cin >> *src))
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        if (*src >= 'a' && *src <= 'c')
            *src -= 32;
        if (*src < 'A' || *src > 'C')
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(2048, '\n');
        break;
    }
    while (true)
    {
        cout << "������Ŀ����(A-C)" << endl;
        if (!(cin >> *dst))
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        if (*dst >= 'a' && *dst <= 'c')
            *dst -= 32;
        if (*dst < 'A' || *dst > 'C')
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        if (*dst == *src)
        {
            cout << "Ŀ����(" << *dst << ")��������ʼ��(" << *src << ")��ͬ" << endl;
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(2048, '\n');
        break;
    }
    *tmp = 'A' + 'B' + 'C' - *src - *dst;
    if (need_delay)
    {
        while (true)
        {
            if (menu_option == 7 || menu_option == 8 || menu_option == 9)
            {
                cout << "�������ƶ��ٶ�(0-20: 0-���س�������ʾ 1-20:��ʾ�ٶ�) ";
                cin >> speed;
                if (cin.good() == 0 || speed > 20 || speed < 0)
                {
                    cin.clear();
                    cin.ignore(2048, '\n');
                    continue;
                }
            }
            else
            {
                cout << "�������ƶ���ʱ(0-200��0-���س�������ʾ 1-200:��ʱ1-200ms) ";
                cin >> speed;
                if (cin.good() == 0 || speed > 200 || speed < 0)
                {
                    cin.clear();
                    cin.ignore(2048, '\n');
                    continue;
                }
            }
            cin.clear();
            cin.ignore(2048, '\n');
            break;
        }
    }
}
// ��������
void show_pillars()
{
    hdc_init(HDC_COLOR[0], HDC_COLOR[11], win_width, win_high);
    hdc_set_pencolor(HDC_COLOR[11]);
    // ������������
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center1_x - base_width / 2, base_y, base_width, base_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center2_x - base_width / 2, base_y, base_width, base_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center3_x - base_width / 2, base_y, base_width, base_height, HDC_COLOR[11]);
    // ������������
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center1_x - pillar_width / 2, base_y - pillar_height, pillar_width, pillar_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center2_x - pillar_width / 2, base_y - pillar_height, pillar_width, pillar_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center3_x - pillar_width / 2, base_y - pillar_height, pillar_width, pillar_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
}
// ����Բ��
void draw_disk(int center_x, int base_y, int disk_num, int position)
{
    int disk_width = (3 + 2 * (disk_num - 1)) * pillar_width;
    int disk_height = base_height;
    int disk_x = center_x - disk_width / 2;
    int disk_y = base_y - disk_height * (position + 1);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(disk_x, disk_y, disk_width, disk_height, HDC_COLOR[disk_num]);
    Sleep(HDC_Init_Delay);
}
//�ƶ����Ӷ���
void move_disk_animation(int disk_num, char src_col, char dst_col, bool show_text_display)
{
    int src_x = getColumnCenterX(src_col);
    int dst_x = getColumnCenterX(dst_col);
    int disk_width = (3 + 2 * (disk_num - 1)) * pillar_width;
    int disk_height = base_height;
    int srcTop = getStackTop(src_col);
    int dstTop = getStackTop(dst_col);
    int current_y = base_y - srcTop * disk_height;
    int target_y = base_y - (dstTop + 1) * disk_height;
    updateStackTop(src_col, srcTop - 1);
    //��������
    int y;
    for (y = current_y; y >= HDC_Top_Y; y -= HDC_Step_Y) 
    {
        hdc_rectangle(src_x - disk_width / 2, y + disk_height - HDC_Step_Y, disk_width, HDC_Step_Y, HDC_COLOR[0]);
        if (y + disk_height > base_y - pillar_height) 
            hdc_rectangle(src_x - pillar_width / 2, y + disk_height - HDC_Step_Y, pillar_width, HDC_Step_Y, HDC_COLOR[11]);
        if (y > HDC_Top_Y)
            hdc_rectangle(src_x - disk_width / 2, y - HDC_Step_Y, disk_width, disk_height, HDC_COLOR[disk_num]);
        else 
            hdc_rectangle(src_x - disk_width / 2, HDC_Top_Y, disk_width, disk_height, HDC_COLOR[disk_num]);
        if (speed == 0)
        {
            Sleep(5);
            cct_gotoxy(0, Status_Line_Y + 2);
            Sleep(5);
            cout << "���س�������...";
            char ch = _getch();
            while (ch != '\r')
                ch = _getch();
            cout << "\r                  \r";
        }
        else 
            Sleep(speed);
    }
    y += HDC_Step_Y;
    if (src_x < dst_x) 
    {
        // �����ƶ�
        for (int x = src_x; x <= dst_x; x += HDC_Step_X) 
        {
            // ����ԭ�����ӵ�λ��
            hdc_rectangle(x - disk_width / 2, y, HDC_Step_X, disk_height, HDC_COLOR[0]);
            // �����ӵ���λ��
            if (x < dst_x)
                hdc_rectangle(x - disk_width / 2 + HDC_Step_X, y, disk_width, disk_height, HDC_COLOR[disk_num]);
            else
                hdc_rectangle(dst_x - disk_width / 2, y, disk_width, disk_height, HDC_COLOR[disk_num]);
            // ��ʱ����
            if (speed == 0) 
            {
                Sleep(5);
                cct_gotoxy(0, Status_Line_Y + 2);
                Sleep(5);
                cout << "���س�������...";
                char ch = _getch();
                while (ch != '\r')
                    ch = _getch();
                cout << "\r                  \r";
            }
            else 
                Sleep(speed);
        }
    }
    else 
    {
        // �����ƶ�
        for (int x = src_x; x >= dst_x; x -= HDC_Step_X) 
        {
            // ����ԭ�����ӵ�λ��
            hdc_rectangle(x + disk_width / 2 - HDC_Step_X, y, HDC_Step_X, disk_height, HDC_COLOR[0]);
            // �����ӵ���λ��
            if (x > dst_x)
                hdc_rectangle(x - disk_width / 2 - HDC_Step_X, y, disk_width, disk_height, HDC_COLOR[disk_num]);
            else
                hdc_rectangle(dst_x - disk_width / 2, y, disk_width, disk_height, HDC_COLOR[disk_num]);
            // ��ʱ����
            if (speed == 0)
            {
                Sleep(5);
                cct_gotoxy(0, Status_Line_Y + 2);
                Sleep(5);
                cout << "���س�������...";
                char ch = _getch();
                while (ch != '\r')
                    ch = _getch();
                cout << "\r                  \r";
            }
            else
                Sleep(speed);
        }
    }
    //�½�����
    current_y = y;
    for (y = current_y; y <= target_y; y += HDC_Step_Y) 
    {
        // ����ԭ�����ӵ�λ��
        hdc_rectangle(dst_x - disk_width / 2, y, disk_width, HDC_Step_Y, HDC_COLOR[0]);
        // ���ϱ����������Ӳ���
        if (y > base_y - pillar_height)
            hdc_rectangle(dst_x - pillar_width / 2, y, pillar_width, HDC_Step_Y, HDC_COLOR[11]);
        // �����ӵ���λ��
        if (y < target_y)
            hdc_rectangle(dst_x - disk_width / 2, y + HDC_Step_Y, disk_width, disk_height, HDC_COLOR[disk_num]);
        else
            hdc_rectangle(dst_x - disk_width / 2, target_y, disk_width, disk_height, HDC_COLOR[disk_num]);
        // ��ʱ����
        if (speed == 0) 
        {
            Sleep(5);
            cct_gotoxy(0, Status_Line_Y + 2);
            Sleep(5);
            cout << "���س�������...";
            char ch = _getch();
            while (ch != '\r')
                ch = _getch();
            cout << "\r                  \r";
        }
        else
            Sleep(speed);
    }
    // ����Ŀ��ջ��Ϣ
    setStackValue(dst_col, dstTop, disk_num);
    updateStackTop(dst_col, dstTop + 1);
    // �����ı���ʾ������ӳٱ����ͻ
    if (show_text_display)
    {
        Sleep(15);
        int textBaseY = MenuItem8_Start_Y;
        // ������ı�
        cct_gotoxy(MenuItem8_Start_X, textBaseY + 1);
        cout << "                                                                                ";
        Sleep(5);
        // ��ʾ�ƶ���Ϣ
        cct_gotoxy(MenuItem8_Start_X, textBaseY + 1);
        cout << "��" << setw(4) << totalstep << " ��(" << setw(2) << disk_num << "#: " << src_col << "-->" << dst_col << ")";
        showshuiping(MenuItem8_Start_X + 30, textBaseY + 1, false, 0);
        Sleep(5);
        // ��ʾ��״ͼ
        showshuzhi(MenuItem8_Start_X, textBaseY + Underpan_A_Y_OFFSET, 0, 0, 0, 1);
        Sleep(5);
    }
}
// �ȴ��س���
void waitForEnter()
{
    cout << endl << "���س�������";
    char ch = _getch();
    while (ch != '\r')
        ch = _getch();
}
//�ⷨ1
void solve_basic_hanoi()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, false);
    totalstep = 0;
    hanoi(number, src, tmp, dst, 1, 0, 0, 0, 0);
    waitForEnter();
}
//�ⷨ2
void solve_with_step_count()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, false);
    totalstep = 0;
    hanoi(number, src, tmp, dst, 2, 0, 0, 0, 0);
    waitForEnter();
}
//�ⷨ3
void solve_shuiping()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, false);
    init(number, src);
    totalstep = 0;
    hanoi(number, src, tmp, dst, 3, 0, 0, 0, 0);
    waitForEnter();
}
//�ⷨ4
void solve_both_arrays()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, true);
    init(number, src);
    totalstep = 0;
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << number << " �㣬��ʱ�趨Ϊ " << speed << "ms" << endl;
    cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y + 1);
    cout << "��ʼ:";
    showshuiping(MenuItem4_Start_X + 30, MenuItem4_Start_Y + 1, false, 0);
    showshuzhi(MenuItem4_Start_X, MenuItem4_Start_Y + Underpan_A_Y_OFFSET, 0, 0, 0, 1);
    if (speed == 0)
    {
        cct_gotoxy(Status_Line_X, MenuItem4_Start_Y + 21);
        char c = getchar();
        cout << "                                ";
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
        cout << "      ";
        hanoi(number, src, tmp, dst, 0, 1, 1, 0, 0);
        cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
        cout << "�ƶ���ɣ���" << totalstep << "��";
        cct_gotoxy(Status_Line_X, Status_Line_Y + 2);
        waitForEnter();
    }
    else
    {
        Sleep(speed);
        cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
        cout << "      ";
        hanoi(number, src, tmp, dst, 0, 1, 1, 0, 0);
        cct_gotoxy(Status_Line_X, MenuItem4_Start_Y + 21);
        cout << "�ƶ���ɣ���" << totalstep << "��";
        cct_gotoxy(Status_Line_X, MenuItem4_Start_Y + 22);
        waitForEnter();
    }
}
// �ⷨ5
void prepare_graphical_pillars()
{
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    show_pillars();
    hdc_release();
    waitForEnter();
}
// �ⷨ6
void prepare_graphical_disks()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, false);
    init(number, src);
    totalstep = 0;
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "�� " << src << " �ƶ��� " << dst << ", �� " << number << " ��" << endl;
    hdc_init(HDC_COLOR[0], HDC_COLOR[11], win_width, win_high);
    show_pillars();
    int center_x = getColumnCenterX(src);
    for (int i = number; i >= 1; i--)
    {
        int position = number - i;
        draw_disk(center_x, base_y, i, position);
    }
    waitForEnter();
}
// �ⷨ7
void first_disk_move()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, true, 7);
    init(number, src);
    totalstep = 0;
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "�� " << src << " �ƶ��� " << dst << ", �� " << number << " ��, ��ʱ�趨Ϊ " << speed << "ms";
    hdc_init(HDC_COLOR[0], HDC_COLOR[11], win_width, win_high);
    show_pillars();
    int center_x = getColumnCenterX(src);
    for (int i = number; i >= 1; i--)
    {
        int position = number - i;
        draw_disk(center_x, base_y, i, position);
    }
    Sleep(15);
    hanoi(number, src, tmp, dst, 7, 0, 0, 1, 0);
    hdc_release();
    cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    waitForEnter();
}

//�ⷨ8
void auto_move_hanoi()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, true, 8);
    init(number, src);
    totalstep = 0;
    cct_cls();
    int textBaseY = MenuItem8_Start_Y;
    for (int i = 0; i < 15; i++)
    {
        cct_gotoxy(0, textBaseY - i - 1);
        cout << "                                                                                ";
    }
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << number << " �㣬��ʱ�趨Ϊ " << speed << "ms" << endl;
    hdc_init(HDC_COLOR[0], HDC_COLOR[11], win_width, win_high);
    show_pillars();
    int center_x = getColumnCenterX(src);
    for (int i = number; i >= 1; i--)
    {
        int position = number - i;
        draw_disk(center_x, base_y, i, position);
    }
    showshuzhi(MenuItem8_Start_X, MenuItem8_Start_Y + Underpan_A_Y_OFFSET, 0, 0, 0, 1);
    cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y + 1);
    cout << "��ʼ:";
    showshuiping(MenuItem8_Start_X + 30, MenuItem8_Start_Y + 1, false, 0);
    Sleep(10);
    hanoi(number, src, tmp, dst, 8, 1, 1, 1, 1);
    cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    cout << "�ƶ���ɣ���" << totalstep << "��          ";
    cct_gotoxy(Status_Line_X, Status_Line_Y + 2);
    waitForEnter();
}
// �ⷨ9
void interactive_move_hanoi()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, true, 9);
    init(number, src);
    totalstep = 0;
    cct_cls();
    int textBaseY = MenuItem8_Start_Y;
    for (int i = 0; i < 15; i++)
    {
        cct_gotoxy(0, textBaseY - i - 1);
        cout << "                                                                                ";
    }
    showshuzhi(MenuItem8_Start_X, textBaseY + Underpan_A_Y_OFFSET, 0, 0, 0, 1);
    cct_gotoxy(0, Status_Line_Y);
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << number << " �㣬��ʱ�趨Ϊ " << speed << "ms" << endl;
    show_pillars();
    int center_x = getColumnCenterX(src);
    for (int i = number; i >= 1; i--)
    {
        int position = number - i;
        draw_disk(center_x, base_y, i, position);
    }
    cct_gotoxy(MenuItem8_Start_X, textBaseY + 1);
    cout << "��״:  ";
    showshuiping(MenuItem8_Start_X + 30, textBaseY + 1, true, 0);
    char move_src, move_dst;
    char command[3];
    while (true)
    {
        cct_gotoxy(0, textBaseY + 4);
        cout << "�������ƶ�������(������ʽ: AC=A���ϵ�Բ���ƶ���C, Q=�˳�): ";
        cin >> command;
        cin.clear();
        cin.ignore(2048, '\n');
        if (command[0] == 'Q' || command[0] == 'q')
            break;
        if (command[0] == '\0' || command[1] == '\0' || command[2] != '\0' ||
            (command[0] != 'A' && command[0] != 'B' && command[0] != 'C' &&
                command[0] != 'a' && command[0] != 'b' && command[0] != 'c') ||
            (command[1] != 'A' && command[1] != 'B' && command[1] != 'C' &&
                command[1] != 'a' && command[1] != 'b' && command[1] != 'c'))
        {
            cct_gotoxy(0, textBaseY + 5);
            cout << "�����������������!" << endl;
            continue;
        }
        move_src = (command[0] >= 'a' && command[0] <= 'c') ? command[0] - 32 : command[0];
        move_dst = (command[1] >= 'a' && command[1] <= 'c') ? command[1] - 32 : command[1];
        if (move_src == move_dst)
        {
            cct_gotoxy(Status_Line_X, textBaseY + 5);
            cout << "Դ��(" << move_src << ")��Ŀ����(" << move_dst << ")��ͬ������������!" << endl;
            continue;
        }
        // ���Դ���Ƿ�Ϊ��
        int srcTop = getStackTop(move_src);
        bool source_empty = (srcTop == 0);
        if (source_empty)
        {
            cct_gotoxy(Status_Line_X, textBaseY + 5);
            cout << "Դ��(" << move_src << ")��û��Բ�̣�����������!" << endl;
            continue;
        }
        // ��ȡԴ�̺�Ŀ�궥������
        int source_disk = getStackValue(move_src, srcTop - 1);
        int dstTop = getStackTop(move_dst);
        int target_top_disk = (dstTop > 0) ? getStackValue(move_dst, dstTop - 1) : 100;
        if (source_disk > target_top_disk && target_top_disk != 100)
        {
            cct_gotoxy(Status_Line_X, textBaseY + 5);
            cout << "�Ƿ��ƶ�: ���ܽ���Բ��(" << source_disk << ")����СԲ��(" << target_top_disk << ")��!" << endl;
            continue;
        }
        cct_gotoxy(Status_Line_X, textBaseY + 5);
        cout << "                                                                      " << endl;
        totalstep++;
        move_disk_animation(source_disk, move_src, move_dst, true);
        cct_gotoxy(MenuItem8_Start_X, textBaseY + 1);
        cout << "��" << setw(4) << totalstep << " ��(" << setw(2) << source_disk << "#: " << move_src << "-->" << move_dst << ")      ";
        cct_gotoxy(0, textBaseY + 2);
        cout << "                                                                                ";
        if (speed > 0)
            Sleep(speed);
        if ((dst == 'A' && topA == number) ||
            (dst == 'B' && topB == number) ||
            (dst == 'C' && topC == number))
        {
            cct_gotoxy(Status_Line_X, textBaseY + 6);
            cout << "��ϲ�����Ѿ��ɹ��ؽ�����Բ�̴� " << src << " ���ƶ����� " << dst << " ������ " << totalstep << " ��!" << endl;
            break;
        }
    }
    cct_gotoxy(Status_Line_X, textBaseY + 7);
    waitForEnter();
}
