/*2351495 大数据 闫业豪*/
#include"hanoi.h"
#include"cmd_console_tools.h"
#include"cmd_hdc_tools.h"
using namespace std;
// 全局变量
int totalstep = 0;
int stackA[MAX_LAYER] = { 0 }, stackB[MAX_LAYER] = { 0 }, stackC[MAX_LAYER] = { 0 };
int topA = 0, topB = 0, topC = 0;
int speed = 0;
void move_disk_animation(int disk_num, char src_col, char dst_col, bool show_text_display = false);
// 辅助函数：更新栈顶指针
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
// 辅助函数：获取栈顶指针
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
// 辅助函数：获取栈数组引用
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
// 辅助函数：设置栈数组值
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
// 辅助函数：获取柱子的中心X坐标
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
// 辅助函数：获取柱子在字符界面的X坐标
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
//初始化
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
// 绘制底座
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
// 横向显示函数
void showshuiping(int x, int y, bool simple = false, int format_type = 0)
{
    if (format_type == 3) // 菜单项3
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
    else if (!simple) // 菜单项4
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
    else // 菜单项8
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
// 纵向显示函数
void showshuzhi(int baseX, int baseY, char src, char dst, int speed, int init,
    int colA_offset = 0, int colB_offset = 0, int colC_offset = 0)
{
    int columnA_X, columnB_X, columnC_X;
    columnA_X = baseX + Underpan_A_X_OFFSET + colA_offset;
    columnB_X = columnA_X + Underpan_Distance + colB_offset;
    columnC_X = columnB_X + Underpan_Distance + colC_offset;
    if (init == 1) //菜单项4
    {
        showdizuo(baseX, baseY);
    }
    else if (init == 2) //菜单项8/9
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
            // 菜单项8/9
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
            // 菜单项4
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
        // 初始化源柱和目标柱的X坐标
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
        // 获取源柱和目标柱的栈顶
        int srcTop = getStackTop(src);
        int dstTop = getStackTop(dst);
        cct_gotoxy(srcX - 1, baseY - 1 - srcTop);
        cout << "  ";
        // 获取目标栈顶元素
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
// move_disk函数
void move_disk(int number, char src, char dst,
    int format_type, int show_horizontal, int show_vertical,
    int show_graphical, int automatic)
{
    // 获取源栈信息
    int srcTop = getStackTop(src);
    int dstTop = getStackTop(dst);
    int disk = getStackValue(src, srcTop - 1);
    if (!show_graphical && format_type != 7 && format_type != 8)
    {
        // 从源栈移除元素
        setStackValue(src, srcTop - 1, 0);
        updateStackTop(src, srcTop - 1);
        // 添加到目标栈
        setStackValue(dst, dstTop, disk);
        updateStackTop(dst, dstTop + 1);
    }
    // 处理功能7：只移动动画，不显示文本
    if (format_type == 7)
    {
        move_disk_animation(disk, src, dst, false);
        return;
    }
    // 处理功能8：显示动画和文本
    if (format_type == 8)
    {
        move_disk_animation(disk, src, dst, true);
        return;
    }
    // 其他format_type
    if (format_type == 1)
        cout << number << "# " << src << "---->" << dst << endl;
    else if (format_type == 2)
        cout << "第 " << setw(3) << totalstep << " 步(" << setw(2) << number << "#: " << src << "-->" << dst << ")" << endl;
    else if (format_type == 3)
    {
        cout << "第" << setw(4) << totalstep << " 步(" << setw(2) << number << "#: " << src << "-->" << dst << ") ";
        showshuiping(0, 0, false, 3);
    }
    else if (format_type == 0)
    {
        int baseY = (show_graphical) ? MenuItem8_Start_Y : MenuItem4_Start_Y;
        if (show_horizontal)
        {
            cct_gotoxy(MenuItem4_Start_X, baseY + 1);
            cout << "第" << setw(4) << totalstep << " 步(" << setw(2) << number << "#: " << src << "-->" << dst << ")";
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
// 递归汉诺塔函数
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
//输入函数
void input(char* src, char* tmp, char* dst, int* number, bool need_delay, int menu_option = 0)
{
    while (true)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
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
        cout << "请输入起始柱(A-C)" << endl;
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
        cout << "请输入目标柱(A-C)" << endl;
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
            cout << "目标柱(" << *dst << ")不能与起始柱(" << *src << ")相同" << endl;
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
                cout << "请输入移动速度(0-20: 0-按回车键逐步演示 1-20:演示速度) ";
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
                cout << "请输入移动延时(0-200，0-按回车键逐步演示 1-200:延时1-200ms) ";
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
// 绘制柱子
void show_pillars()
{
    hdc_init(HDC_COLOR[0], HDC_COLOR[11], win_width, win_high);
    hdc_set_pencolor(HDC_COLOR[11]);
    // 绘制三个底座
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center1_x - base_width / 2, base_y, base_width, base_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center2_x - base_width / 2, base_y, base_width, base_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center3_x - base_width / 2, base_y, base_width, base_height, HDC_COLOR[11]);
    // 绘制三个柱子
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center1_x - pillar_width / 2, base_y - pillar_height, pillar_width, pillar_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center2_x - pillar_width / 2, base_y - pillar_height, pillar_width, pillar_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
    hdc_rectangle(center3_x - pillar_width / 2, base_y - pillar_height, pillar_width, pillar_height, HDC_COLOR[11]);
    Sleep(HDC_Init_Delay);
}
// 绘制圆盘
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
//移动盘子动画
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
    //上升动画
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
            cout << "按回车键继续...";
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
        // 向右移动
        for (int x = src_x; x <= dst_x; x += HDC_Step_X) 
        {
            // 擦除原来盘子的位置
            hdc_rectangle(x - disk_width / 2, y, HDC_Step_X, disk_height, HDC_COLOR[0]);
            // 画盘子的新位置
            if (x < dst_x)
                hdc_rectangle(x - disk_width / 2 + HDC_Step_X, y, disk_width, disk_height, HDC_COLOR[disk_num]);
            else
                hdc_rectangle(dst_x - disk_width / 2, y, disk_width, disk_height, HDC_COLOR[disk_num]);
            // 延时处理
            if (speed == 0) 
            {
                Sleep(5);
                cct_gotoxy(0, Status_Line_Y + 2);
                Sleep(5);
                cout << "按回车键继续...";
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
        // 向左移动
        for (int x = src_x; x >= dst_x; x -= HDC_Step_X) 
        {
            // 擦除原来盘子的位置
            hdc_rectangle(x + disk_width / 2 - HDC_Step_X, y, HDC_Step_X, disk_height, HDC_COLOR[0]);
            // 画盘子的新位置
            if (x > dst_x)
                hdc_rectangle(x - disk_width / 2 - HDC_Step_X, y, disk_width, disk_height, HDC_COLOR[disk_num]);
            else
                hdc_rectangle(dst_x - disk_width / 2, y, disk_width, disk_height, HDC_COLOR[disk_num]);
            // 延时处理
            if (speed == 0)
            {
                Sleep(5);
                cct_gotoxy(0, Status_Line_Y + 2);
                Sleep(5);
                cout << "按回车键继续...";
                char ch = _getch();
                while (ch != '\r')
                    ch = _getch();
                cout << "\r                  \r";
            }
            else
                Sleep(speed);
        }
    }
    //下降动画
    current_y = y;
    for (y = current_y; y <= target_y; y += HDC_Step_Y) 
    {
        // 擦除原来盘子的位置
        hdc_rectangle(dst_x - disk_width / 2, y, disk_width, HDC_Step_Y, HDC_COLOR[0]);
        // 补上被擦掉的柱子部分
        if (y > base_y - pillar_height)
            hdc_rectangle(dst_x - pillar_width / 2, y, pillar_width, HDC_Step_Y, HDC_COLOR[11]);
        // 画盘子的新位置
        if (y < target_y)
            hdc_rectangle(dst_x - disk_width / 2, y + HDC_Step_Y, disk_width, disk_height, HDC_COLOR[disk_num]);
        else
            hdc_rectangle(dst_x - disk_width / 2, target_y, disk_width, disk_height, HDC_COLOR[disk_num]);
        // 延时处理
        if (speed == 0) 
        {
            Sleep(5);
            cct_gotoxy(0, Status_Line_Y + 2);
            Sleep(5);
            cout << "按回车键继续...";
            char ch = _getch();
            while (ch != '\r')
                ch = _getch();
            cout << "\r                  \r";
        }
        else
            Sleep(speed);
    }
    // 更新目标栈信息
    setStackValue(dst_col, dstTop, disk_num);
    updateStackTop(dst_col, dstTop + 1);
    // 处理文本显示，添加延迟避免冲突
    if (show_text_display)
    {
        Sleep(15);
        int textBaseY = MenuItem8_Start_Y;
        // 清除旧文本
        cct_gotoxy(MenuItem8_Start_X, textBaseY + 1);
        cout << "                                                                                ";
        Sleep(5);
        // 显示移动信息
        cct_gotoxy(MenuItem8_Start_X, textBaseY + 1);
        cout << "第" << setw(4) << totalstep << " 步(" << setw(2) << disk_num << "#: " << src_col << "-->" << dst_col << ")";
        showshuiping(MenuItem8_Start_X + 30, textBaseY + 1, false, 0);
        Sleep(5);
        // 显示柱状图
        showshuzhi(MenuItem8_Start_X, textBaseY + Underpan_A_Y_OFFSET, 0, 0, 0, 1);
        Sleep(5);
    }
}
// 等待回车键
void waitForEnter()
{
    cout << endl << "按回车键继续";
    char ch = _getch();
    while (ch != '\r')
        ch = _getch();
}
//解法1
void solve_basic_hanoi()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, false);
    totalstep = 0;
    hanoi(number, src, tmp, dst, 1, 0, 0, 0, 0);
    waitForEnter();
}
//解法2
void solve_with_step_count()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, false);
    totalstep = 0;
    hanoi(number, src, tmp, dst, 2, 0, 0, 0, 0);
    waitForEnter();
}
//解法3
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
//解法4
void solve_both_arrays()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, true);
    init(number, src);
    totalstep = 0;
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "从 " << src << " 移动到 " << dst << "，共 " << number << " 层，延时设定为 " << speed << "ms" << endl;
    cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y + 1);
    cout << "初始:";
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
        cout << "移动完成，共" << totalstep << "步";
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
        cout << "移动完成，共" << totalstep << "步";
        cct_gotoxy(Status_Line_X, MenuItem4_Start_Y + 22);
        waitForEnter();
    }
}
// 解法5
void prepare_graphical_pillars()
{
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    show_pillars();
    hdc_release();
    waitForEnter();
}
// 解法6
void prepare_graphical_disks()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, false);
    init(number, src);
    totalstep = 0;
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "从 " << src << " 移动到 " << dst << ", 共 " << number << " 层" << endl;
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
// 解法7
void first_disk_move()
{
    int number;
    char src, tmp, dst;
    input(&src, &tmp, &dst, &number, true, 7);
    init(number, src);
    totalstep = 0;
    cct_cls();
    cct_gotoxy(Status_Line_X, Status_Line_Y);
    cout << "从 " << src << " 移动到 " << dst << ", 共 " << number << " 层, 延时设定为 " << speed << "ms";
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

//解法8
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
    cout << "从 " << src << " 移动到 " << dst << "，共 " << number << " 层，延时设定为 " << speed << "ms" << endl;
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
    cout << "初始:";
    showshuiping(MenuItem8_Start_X + 30, MenuItem8_Start_Y + 1, false, 0);
    Sleep(10);
    hanoi(number, src, tmp, dst, 8, 1, 1, 1, 1);
    cct_gotoxy(Status_Line_X, Status_Line_Y + 1);
    cout << "移动完成，共" << totalstep << "步          ";
    cct_gotoxy(Status_Line_X, Status_Line_Y + 2);
    waitForEnter();
}
// 解法9
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
    cout << "从 " << src << " 移动到 " << dst << "，共 " << number << " 层，延时设定为 " << speed << "ms" << endl;
    show_pillars();
    int center_x = getColumnCenterX(src);
    for (int i = number; i >= 1; i--)
    {
        int position = number - i;
        draw_disk(center_x, base_y, i, position);
    }
    cct_gotoxy(MenuItem8_Start_X, textBaseY + 1);
    cout << "初状:  ";
    showshuiping(MenuItem8_Start_X + 30, textBaseY + 1, true, 0);
    char move_src, move_dst;
    char command[3];
    while (true)
    {
        cct_gotoxy(0, textBaseY + 4);
        cout << "请输入移动的柱号(命令形式: AC=A顶上的圆盘移动到C, Q=退出): ";
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
            cout << "命令错误，请重新输入!" << endl;
            continue;
        }
        move_src = (command[0] >= 'a' && command[0] <= 'c') ? command[0] - 32 : command[0];
        move_dst = (command[1] >= 'a' && command[1] <= 'c') ? command[1] - 32 : command[1];
        if (move_src == move_dst)
        {
            cct_gotoxy(Status_Line_X, textBaseY + 5);
            cout << "源柱(" << move_src << ")和目标柱(" << move_dst << ")相同，请重新输入!" << endl;
            continue;
        }
        // 检查源柱是否为空
        int srcTop = getStackTop(move_src);
        bool source_empty = (srcTop == 0);
        if (source_empty)
        {
            cct_gotoxy(Status_Line_X, textBaseY + 5);
            cout << "源柱(" << move_src << ")上没有圆盘，请重新输入!" << endl;
            continue;
        }
        // 获取源盘和目标顶部盘子
        int source_disk = getStackValue(move_src, srcTop - 1);
        int dstTop = getStackTop(move_dst);
        int target_top_disk = (dstTop > 0) ? getStackValue(move_dst, dstTop - 1) : 100;
        if (source_disk > target_top_disk && target_top_disk != 100)
        {
            cct_gotoxy(Status_Line_X, textBaseY + 5);
            cout << "非法移动: 不能将大圆盘(" << source_disk << ")放在小圆盘(" << target_top_disk << ")上!" << endl;
            continue;
        }
        cct_gotoxy(Status_Line_X, textBaseY + 5);
        cout << "                                                                      " << endl;
        totalstep++;
        move_disk_animation(source_disk, move_src, move_dst, true);
        cct_gotoxy(MenuItem8_Start_X, textBaseY + 1);
        cout << "第" << setw(4) << totalstep << " 步(" << setw(2) << source_disk << "#: " << move_src << "-->" << move_dst << ")      ";
        cct_gotoxy(0, textBaseY + 2);
        cout << "                                                                                ";
        if (speed > 0)
            Sleep(speed);
        if ((dst == 'A' && topA == number) ||
            (dst == 'B' && topB == number) ||
            (dst == 'C' && topC == number))
        {
            cct_gotoxy(Status_Line_X, textBaseY + 6);
            cout << "恭喜！您已经成功地将所有圆盘从 " << src << " 柱移动到了 " << dst << " 柱，共 " << totalstep << " 步!" << endl;
            break;
        }
    }
    cct_gotoxy(Status_Line_X, textBaseY + 7);
    waitForEnter();
}
