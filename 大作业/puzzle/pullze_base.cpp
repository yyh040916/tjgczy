/*2351495 大数据 闫业豪*/
#include"pullze.h"
const int MODE_BASIC = 0;          // A
const int MODE_WITH_HINTS = 1;     // B
const int MODE_GAME = 2;           // C
// 游戏状态结构体
struct GameState {
    int game_data[MAX_SIZE][MAX_SIZE];
    int user_marks[MAX_SIZE][MAX_SIZE];
    int size;
    bool cheat_mode;
};
//初始化二维数组
void init_2d_array(int arr[][MAX_SIZE], int size) 
{
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++) 
            arr[i][j] = 0;

}
// 生成随机球位置
void generate_balls(int game_data[][MAX_SIZE], int size) 
{
    srand((unsigned int)time(0));
    int total_cells = size * size;
    int ball_count = (total_cells + 1) / 2;
    int placed = 0;
    while (placed < ball_count) 
    {
        int row = rand() % size;
        int col = rand() % size;
        if (game_data[row][col] == 0) 
        {
            game_data[row][col] = 1;
            placed++;
        }
    }
}
//分析线性连续球的个数（可用于行或列）
int analyze_line_hints(int game_data[][MAX_SIZE], int line_index, int size,int hints[], bool is_row) 
{
    int hint_count = 0;
    int consecutive_count = 0;
    for (int i = 0; i < size; i++)
    {
        int cell_value;
        if (is_row)
            cell_value = game_data[line_index][i];
        else
            cell_value = game_data[i][line_index];
        if (cell_value != 0)
            consecutive_count++;
        else
            if (consecutive_count > 0) 
            {
                hints[hint_count++] = consecutive_count;
                consecutive_count = 0;
            }
    }
    if (consecutive_count > 0)
        hints[hint_count++] = consecutive_count;
    if (hint_count == 0) 
    {
        hints[0] = 0;
        hint_count = 1;
    }
    return hint_count;
}
// 计算提示的显示宽度
int calculate_hint_display_width(int hints[], int hint_count)
{
    int width = 0;
    for (int i = 0; i < hint_count; i++)
    {
        width += (hints[i] >= 10) ? 2 : 1;
        if (i < hint_count - 1) 
            width += 1;
    }
    return width;
}
//计算所有行或列的最大提示尺寸
int calculate_max_hint_dimension(int game_data[][MAX_SIZE], int size, bool is_row) 
{
    int max_dimension = 0;
    for (int i = 0; i < size; i++) 
    {
        int hints[MAX_HINTS];
        int hint_count = analyze_line_hints(game_data, i, size, hints, is_row);
        int dimension = is_row ? calculate_hint_display_width(hints, hint_count) : hint_count;
        if (dimension > max_dimension)
            max_dimension = dimension;
    }
    return max_dimension;
}
// 统一的提示计算函数
void calculate_all_hints(int size, int game_data[][MAX_SIZE],int row_hints[][MAX_HINTS], int col_hints[][MAX_SIZE]) 
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < MAX_HINTS; j++)
            row_hints[i][j] = 0;
    for (int i = 0; i < MAX_HINTS; i++)
        for (int j = 0; j < size; j++)
            col_hints[i][j] = 0;
    for (int i = 0; i < size; i++) 
    {
        int hints[MAX_HINTS];
        int hint_count = analyze_line_hints(game_data, i, size, hints, true);
        for (int j = 0; j < hint_count; j++)
            row_hints[i][j] = hints[j];
    }
    for (int j = 0; j < size; j++) 
    {
        int hints[MAX_HINTS];
        int hint_count = analyze_line_hints(game_data, j, size, hints, false);
        for (int i = 0; i < hint_count; i++)
            col_hints[i][j] = hints[i];
    }
}
// 计算提示区域的宽度和高度
void calculate_hint_dimensions(int size, int row_hints[][MAX_HINTS],int col_hints[][MAX_SIZE], int* width, int* height) 
{
    *width = 0;
    *height = 0;
    for (int i = 0; i < size; i++) 
    {
        int hint_counter = 0;
        for (int j = 0; j < MAX_HINTS && row_hints[i][j] != 0; j++)
            hint_counter++;
        *width = max(*width, hint_counter);
    }
    for (int j = 0; j < size; j++)
    {
        int hint_counter = 0;
        for (int i = 0; i < MAX_HINTS && col_hints[i][j] != 0; i++)
            hint_counter++;
        *height = max(*height, hint_counter);
    }
}
// 打印分隔线
void print_separator(int x, int y, int width, char ch = '-') 
{
    cct_gotoxy(x, y);
    for (int i = 0; i < width; i++)
        cout << ch;

}
//计算分组边框
void print_grouped_border(int x, int y, int size, const char* prefix = "", const char* suffix = "")
{
    cct_gotoxy(x, y);
    cout << prefix;
    int groups = (size + 4) / 5;
    for (int i = 0; i < groups; i++)
    {
        int cols_in_group = (i == groups - 1) ? (size - i * 5) : 5;
        for (int j = 0; j < cols_in_group * 2 + 1; j++)
            cout << "-";
        cout << "+";
    }
    cout << suffix;
}
// 打印基础数织框架
void print_basic_frame(int game_data[][MAX_SIZE], int size, int x, int y, bool show_corner = true) 
{
    int groups = (size + 4) / 5;
    if (show_corner) 
    {
        print_grouped_border(x - 2, y, size, "+-+");
        cct_gotoxy(x - 2, y + 1);
        cout << "| | ";
        for (int i = 0; i < size; i++) 
        {
            cout << (char)('a' + i) << " ";
            if ((i + 1) % 5 == 0 && i != size - 1) cout << "| ";
        }
        cout << "|";
        print_grouped_border(x - 2, y + 2, size, "+-+");
    }
    else 
    {
        print_grouped_border(x, y, size, "+");
        cct_gotoxy(x, y + 1);
        cout << "| ";
        for (int i = 0; i < size; i++) 
        {
            cout << (char)('a' + i) << " ";
            if ((i + 1) % 5 == 0 && i != size - 1) cout << "| ";
        }
        cout << "|";
        print_grouped_border(x - 2, y + 2, size, "+-+");
    }
    for (int i = 0; i < size; i++) 
    {
        if (i > 0 && i % 5 == 0)
            print_grouped_border(x - 2, y + 3 + i + (i - 1) / 5, size, "+-+");
        cct_gotoxy(x - 2, y + 3 + i + i / 5);
        cout << "|" << (char)('A' + i) << "| ";
        for (int j = 0; j < size; j++) 
        {
            cout << (game_data[i][j] != 0 ? "O " : "  ");
            if ((j + 1) % 5 == 0 && j != size - 1) cout << "| ";
        }
        cout << "|";
    }
    int final_row = y + 3 + size + (size - 1) / 5;
    print_grouped_border(x - 2, final_row, size, "+-+");
}
// 打印行提示栏
void print_row_hints(int row_hints[][MAX_HINTS], int size, int width, int x, int y) 
{
    print_separator(x, y, 2 * width + 1);
    for (int i = 0; i < size; i++)
    {
        if (i > 0 && i % 5 == 0)
            print_separator(x, y + 1 + i + (i - 1) / 5, 2 * width + 1);
        int hints_count = 0;
        for (int j = 0; j < MAX_HINTS && row_hints[i][j] != 0; j++)
            hints_count++;
        cct_gotoxy(x, y + 1 + i + i / 5);
        for (int k = 0; k < 2 * (width - hints_count) + 1; k++)
            cout << " ";
        for (int j = 0; j < hints_count; j++) 
        {
            cout << row_hints[i][j];
            if (j < hints_count - 1) 
                cout << " ";
        }
    }
    int final_row = y + 1 + size + (size - 1) / 5;
    print_separator(x, final_row, 2 * width + 3);
}
// 打印列提示栏
void print_col_hints(int col_hints[][MAX_SIZE], int size, int height, int x, int y) 
{
    for (int j = 0; j < size; j++)
    {
        int non_zero_hints[MAX_HINTS];
        int count = 0;
        for (int i = 0; i < height; i++)
            if (col_hints[i][j] != 0) 
                non_zero_hints[count++] = col_hints[i][j];
        for (int i = 0; i < height; i++) 
        {
            if (i < height - count) 
                col_hints[i][j] = 0;
            else 
                col_hints[i][j] = non_zero_hints[i - (height - count)];
        }
    }
    print_grouped_border(x, y, size, "+");
    for (int i = 0; i < height; i++)
    {
        cct_gotoxy(x, y + 1 + i);
        cout << "| ";
        for (int j = 0; j < size; j++) 
        {
            if (col_hints[i][j] == 0) 
                cout << "  ";
            else
                cout << col_hints[i][j] << " ";
            if ((j + 1) % 5 == 0 && j != size - 1) 
                cout << "| ";
        }
        cout << "|";
    }
}
// 绘制完整游戏布局
void draw_game_with_hints(int game_data[][MAX_SIZE], int size, int x, int y) 
{
    int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
    int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
    calculate_all_hints(size, game_data, row_hints, col_hints);
    int width, height;
    calculate_hint_dimensions(size, row_hints, col_hints, &width, &height);
    print_separator(x, y, 2 * width + 3);
    print_separator(x, y + height + 1, 2 * width + 3);
    print_row_hints(row_hints, size, width, x, y + height + 3);
    print_col_hints(col_hints, size, height, x + 2 * width + 3, y);
    print_basic_frame(game_data, size, x + 2 * width + 3, y + height + 1, false);
}
int judge_game_input(int size, char input[], int user_marks[][MAX_SIZE]) 
{
    int len = 0;
    while (input[len] != '\0')
    {
        len++;
    }
    if (len == 0) 
        return 0;
    if (len == 1)
    {
        char cmd = input[0];
        if (cmd >= 'A' && cmd <= 'Z')
            cmd = cmd + 32;

        switch (cmd) 
        {
        case 'x':
            return 3; // 退出
        case 'y':
            return 4; // 提交
        case 'z': 
            return 5; // 作弊
        default: 
            return 0;
        }
    }
    else if (len == 2) 
    {
        int row_offset = input[0] - 'A';
        int col_offset = input[1] - 'a';
        if (row_offset < 0 || row_offset >= size ||col_offset < 0 || col_offset >= size) 
        {
            return 0;
        }
        return (user_marks[row_offset][col_offset] == 0) ? 1 : 3;
    }
    return 0;
}
// 打印游戏操作说明
void print_game_prompt() 
{
    cout << endl;
    cout << "命令形式：Aa=点击此位置标记球存在（请分大小写）" << endl;
    cout << "          不需要支持标记为不存在的操作（等价于右键），再次输入相" << endl;
    cout << "          同坐标则取消标记" << endl;
    cout << "          X/x=退出（新行输入X/x，不分大小写）" << endl;
    cout << "          Y/y=提交（新行输入Y/y，不分大小写）" << endl;
    cout << "          Z/z=作弊（新行输入Z/z，不分大小写）" << endl;
    cout << "          Ctrl+c 强制退出" << endl;
    cout << "请输入 : ";
}
// 更新游戏显示状态
void update_game_display(GameState* game, int x, int y, int width, int height) 
{
    for (int i = 0; i < game->size; i++) 
    {
        for (int j = 0; j < game->size; j++) 
        {
            int sx = x + 5 + 2 * width + 2 * j + 2 * (j / 5),sy = y + 4 + height + i + i / 5;
            if (game->cheat_mode) 
            {
                if (game->game_data[i][j] == 1 && game->user_marks[i][j] == 1) 
                {
                    cct_showch(sx, sy, 'O', COLOR_HYELLOW, COLOR_HBLUE, 1);
                }
                else if (game->game_data[i][j] == 1 && game->user_marks[i][j] == 0) 
                {
                    cct_showch(sx, sy, 'O', COLOR_BLACK, COLOR_HWHITE, 1);
                }
                else if (game->game_data[i][j] == 0 && game->user_marks[i][j] == 1) 
                {
                    cct_showch(sx, sy, 'X', COLOR_HYELLOW, COLOR_HBLUE, 1);
                }
                else 
                {
                    cct_showch(sx, sy, ' ', COLOR_BLACK, COLOR_HWHITE, 1);
                }
            }
            else 
            {
                if (game->user_marks[i][j] == 1) 
                {
                    cct_showch(sx, sy, 'O', COLOR_HYELLOW, COLOR_HBLUE, 1);
                }
                else 
                {
                    cct_showch(sx, sy, ' ', COLOR_BLACK, COLOR_WHITE, 1);
                }
            }
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
// A功能
void A_function() 
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    generate_balls(game_data, size);
    cout << "初始数组：" << endl;
    int x, y;
    cct_getxy(x, y);
    print_basic_frame(game_data, size, x + 2, y, true);
    cout << endl << endl;
    wait_for_end();
}
// B功能
void B_function()
{
    int size = sizechoice();
    int game_data[MAX_SIZE][MAX_SIZE];
    init_2d_array(game_data, size);
    generate_balls(game_data, size);
    cout << "初始数组：" << endl;
    int x, y;
    cct_getxy(x, y);
    draw_game_with_hints(game_data, size, x, y);
    cout << endl << endl;
    wait_for_end();
}
// C功能
void C_function() 
{
    int size = sizechoice();
    GameState game;
    game.size = size;
    game.cheat_mode = false;
    init_2d_array(game.game_data, size);
    init_2d_array(game.user_marks, size);
    generate_balls(game.game_data, size);
    char input[200];
    int row_hints[MAX_SIZE][MAX_HINTS] = { 0 };
    int col_hints[MAX_HINTS][MAX_SIZE] = { 0 };
    calculate_all_hints(game.size, game.game_data, row_hints, col_hints);
    int width, height;
    calculate_hint_dimensions(game.size, row_hints, col_hints, &width, &height);
    cout << "初始数组：" << endl;
    int x, y;
    cct_getxy(x, y);
    draw_game_with_hints(game.game_data, size, x, y);
    update_game_display(&game, x, y, width, height);
    cout << endl << endl << endl;
    while (true) 
    {
        print_game_prompt();
        cin.getline(input, sizeof(input));
        int result = judge_game_input(size, input, game.user_marks);
        if (result == 0)
        {
            cout << "输入错误" << endl;
            continue;
        }
        switch (result) 
        {
        case 1: // 标记
        case 2: // 取消标记
        {
            if (strlen(input) >= 2) 
            {
                int row_idx = input[0] - 'A';
                int col_idx = input[1] - 'a';
                if (row_idx >= 0 && row_idx < size && row_idx < MAX_SIZE &&
                    col_idx >= 0 && col_idx < size && col_idx < MAX_SIZE)
                {
                    game.user_marks[row_idx][col_idx] = (result == 1) ? 1 : 0;
                    cout << "输入" << input[0] << input[1] << "后：" << endl;
                    cct_getxy(x, y);
                    draw_game_with_hints(game.game_data, size, x, y);
                    update_game_display(&game, x, y, width, height);
                    cout << endl << endl << endl;
                }
                else 
                {
                    cout << "输入错误" << endl;
                    continue;
                }
            }
            break;
        }
        case 4: // 提交
        {
            char cmd = input[0];
            if (cmd >= 'A' && cmd <= 'Z') 
            {
                cmd = cmd + 32; // 转换为小写
            }
            if (cmd == 'x') 
            {
                wait_for_end();
                return;
            }
            else if (cmd == 'y') 
            {
                if (check_solution_by_hints(game.game_data, game.user_marks, size, 1)) 
                {
                    cout << "提交成功，游戏结束" << endl;
                    wait_for_end();
                    return;
                }
                else 
                {
                    int error_row, error_col;
                    if (find_first_error_position(game.game_data, game.user_marks, size, 1, &error_row, &error_col)) 
                    {
                        cout << "提交错误, [" << (char)('A' + error_row) << "]行[" << (char)('a' + error_col) << "]列不符合要求" << endl;
                    }
                    else 
                    {
                        cout << "提交错误, 可用作弊模式查看" << endl;
                    }
                    continue;
                }
            }
            break;
        }
        case 3: // 退出
            wait_for_end();
            return;
        case 5: // 作弊模式
            game.cheat_mode = !game.cheat_mode;
            cout << "输入Z/z后：" << endl;
            cct_getxy(x, y);
            draw_game_with_hints(game.game_data, size, x, y);
            update_game_display(&game, x, y, width, height);
            cout << endl << endl << endl;
            break;
        }
    }
}
