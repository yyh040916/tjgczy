/*2351495 大数据 闫业豪*/
#include <iostream>
#include <conio.h>
using namespace std;
#include "cmd_console_tools.h"
#include "7-b2.h"
static bool is_chinese_char(unsigned char ch)
{
    return (ch >= 0xA1 && ch <= 0xFE);
}

static int get_display_length(const char* str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (is_chinese_char((unsigned char)str[i]) && str[i + 1] != '\0' &&
            is_chinese_char((unsigned char)str[i + 1]))
        {
            len += 2;
            i++;
        }
        else
        {
            len += 1;
        }
    }
    return len;
}
//避免截断中文字符
static int safe_truncate_length(const char* str, int max_display_width)
{
    int display_len = 0;
    int byte_len = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int char_width = 1;
        if (is_chinese_char((unsigned char)str[i]) && str[i + 1] != '\0' &&
            is_chinese_char((unsigned char)str[i + 1]))
        {
            char_width = 2;
            if (display_len + char_width > max_display_width)
            {
                break;
            }
            display_len += char_width;
            byte_len += 2;
            i++;
        }
        else
        {
            if (display_len + char_width > max_display_width)
            {
                break;
            }
            display_len += char_width;
            byte_len += 1;
        }
    }
    return byte_len;
}
static int get_menu_count(const char menu[][MAX_ITEM_LEN])
{
    int count = 0;
    while (menu[count] != NULL && menu[count][0] != '\0')
    {
        count++;
    }
    return count;
}
static int get_max_item_length(const char menu[][MAX_ITEM_LEN])
{
    int max_len = 0;
    int count = get_menu_count(menu);
    for (int i = 0; i < count; i++)
    {
        int len = get_display_length(menu[i]);
        if (len > max_len)
        {
            max_len = len;
        }
    }
    return max_len;
}
static int calculate_actual_height(const struct PopMenu* para, int menu_count)
{
    // 框架高度 = min(菜单项数量, 设置的最大高度) + 上下边框
    int actual_display_rows = (menu_count < para->high) ? menu_count : para->high;
    return actual_display_rows + 2;
}
static int calculate_actual_width(const struct PopMenu* para)
{
    int title_len = para->title ? get_display_length(para->title) : 0;
    int content_width = para->width;
    int min_content_width = title_len;
    if (content_width < min_content_width)
    {
        content_width = min_content_width;
    }
    int actual_width = content_width + 4;
    if (actual_width % 2 == 1)
    {
        actual_width++;
    }
    return actual_width;
}
// 换行后的实际位置
static void get_wrapped_position(int original_x, int original_y, int* wrapped_x, int* wrapped_y)
{
    int console_cols, console_lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(console_cols, console_lines, buffer_cols, buffer_lines);
    // 只有当缓冲区大小等于窗口大小时才进行折行处理
    // 如果缓冲区比窗口大，则不折行，让用户通过滚动条查看
    if (buffer_cols == console_cols && original_x >= console_cols)
    {
        *wrapped_y = original_y + (original_x / console_cols);
        *wrapped_x = original_x % console_cols;
    }
    else
    {
        *wrapped_x = original_x;
        *wrapped_y = original_y;
    }
}

// 安全显示字符，处理换行情况
static void safe_showch_wrapped(int x, int y, char ch, int bg_color, int fg_color)
{
    int wrapped_x, wrapped_y;
    get_wrapped_position(x, y, &wrapped_x, &wrapped_y);
    cct_showch(wrapped_x, wrapped_y, ch, bg_color, fg_color);
}

//安全显示字符串，处理换行情况
static void safe_showstr_wrapped(int x, int y, const char* str, int bg_color, int fg_color)
{
    int wrapped_x, wrapped_y;
    get_wrapped_position(x, y, &wrapped_x, &wrapped_y);
    cct_showstr(wrapped_x, wrapped_y, str, bg_color, fg_color);
}
static void clear_menu_content(const struct PopMenu* para, int actual_width, int actual_height)
{
    for (int row = 1; row < actual_height - 1; row++)
    {
        for (int col = 2; col < actual_width - 2; col++)
        {
            safe_showch_wrapped(para->start_x + col, para->start_y + row, ' ', para->bg_color, para->fg_color);
        }
    }
}

// 绘制菜单边框和标题（仅绘制一次）- 处理换行情况
static void draw_menu_frame(const struct PopMenu* para, int actual_width, int actual_height)
{
    safe_showstr_wrapped(para->start_x, para->start_y, "┏", para->bg_color, para->fg_color);
    if (para->title && para->title[0] != '\0')
    {
        int title_len = get_display_length(para->title);
        int border_content_width = actual_width - 4; 
        int remaining_width = border_content_width - title_len;
        int left_padding = remaining_width / 2;
        if (left_padding % 2 == 1)
        {
            left_padding--;
        }
        int right_padding = remaining_width - left_padding;
        for (int i = 0; i < left_padding; i += 2)
        {
            safe_showstr_wrapped(para->start_x + 2 + i, para->start_y, "━", para->bg_color, para->fg_color);
        }
        safe_showstr_wrapped(para->start_x + 2 + left_padding, para->start_y, para->title, para->bg_color, para->fg_color);
        for (int i = 0; i < right_padding; i += 2)
        {
            safe_showstr_wrapped(para->start_x + 2 + left_padding + title_len + i, para->start_y, "━", para->bg_color, para->fg_color);
        }
    }
    else
    {
        for (int i = 2; i < actual_width - 2; i += 2)
        {
            safe_showstr_wrapped(para->start_x + i, para->start_y, "━", para->bg_color, para->fg_color);
        }
    }
    safe_showstr_wrapped(para->start_x + actual_width - 2, para->start_y, "┓", para->bg_color, para->fg_color);
    for (int row = 1; row < actual_height - 1; row++)
    {
        safe_showstr_wrapped(para->start_x, para->start_y + row, "┃", para->bg_color, para->fg_color);
        safe_showstr_wrapped(para->start_x + actual_width - 2, para->start_y + row, "┃", para->bg_color, para->fg_color);
    }
    safe_showstr_wrapped(para->start_x, para->start_y + actual_height - 1, "┗", para->bg_color, para->fg_color);
    for (int i = 2; i < actual_width - 2; i += 2)
    {
        safe_showstr_wrapped(para->start_x + i, para->start_y + actual_height - 1, "━", para->bg_color, para->fg_color);
    }
    safe_showstr_wrapped(para->start_x + actual_width - 2, para->start_y + actual_height - 1, "┛", para->bg_color, para->fg_color);
}
static void draw_all_menu_items(const char menu[][MAX_ITEM_LEN], const struct PopMenu* para,
    int menu_count, int selected, int scroll_offset, int actual_width)
{
    int display_rows = (menu_count < para->high) ? menu_count : para->high;
    int menu_start_y = para->start_y + 1;
    int content_width = actual_width - 4;
    for (int row = 0; row < display_rows; row++)
    {
        int menu_index = row + scroll_offset;
        int y_pos = menu_start_y + row;

        if (menu_index < menu_count)
        {
            int bg_color = para->bg_color;
            int fg_color = para->fg_color;
            if (menu_index == selected)
            {
                bg_color = para->fg_color;
                fg_color = para->bg_color;
            }
            for (int col = 2; col < actual_width - 2; col++)
            {
                safe_showch_wrapped(para->start_x + col, y_pos, ' ', bg_color, fg_color);
            }
            int safe_maxlen = safe_truncate_length(menu[menu_index], content_width);
            if (safe_maxlen > 0) 
            {
                char temp_str[MAX_ITEM_LEN + 1];
                for (int i = 0; i < safe_maxlen; i++) 
                {
                    temp_str[i] = menu[menu_index][i];
                }
                temp_str[safe_maxlen] = '\0';
                safe_showstr_wrapped(para->start_x + 2, y_pos, temp_str, bg_color, fg_color);
            }
        }
        else
        {
            for (int col = 2; col < actual_width - 2; col++)
            {
                safe_showch_wrapped(para->start_x + col, y_pos, ' ', para->bg_color, para->fg_color);
            }
        }
    }
}
static void update_menu_item(const char menu[][MAX_ITEM_LEN], const struct PopMenu* para,
    int menu_index, bool is_selected, int scroll_offset, int actual_width, int menu_count)
{
    int display_rows = (menu_count < para->high) ? menu_count : para->high;
    int display_row = menu_index - scroll_offset;
    if (display_row < 0 || display_row >= display_rows)
    {
        return;
    }
    int y_pos = para->start_y + 1 + display_row;
    int content_width = actual_width - 4;
    int bg_color = para->bg_color;
    int fg_color = para->fg_color;
    if (is_selected)
    {
        bg_color = para->fg_color;
        fg_color = para->bg_color;
    }
    for (int col = 2; col < actual_width - 2; col++)
    {
        safe_showch_wrapped(para->start_x + col, y_pos, ' ', bg_color, fg_color);
    }
    int safe_maxlen = safe_truncate_length(menu[menu_index], content_width);
    if (safe_maxlen > 0) 
    {
        char temp_str[MAX_ITEM_LEN + 1];
        for (int i = 0; i < safe_maxlen; i++) 
        {
            temp_str[i] = menu[menu_index][i];
        }
        temp_str[safe_maxlen] = '\0';
        safe_showstr_wrapped(para->start_x + 2, y_pos, temp_str, bg_color, fg_color);
    }
}
/***************************************************************************
  函数名称：pop_menu
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：menu - 菜单项数组
           original_para - 菜单参数结构体
  返 回 值：选中的菜单项号(1-based)，0表示ESC退出
  说    明：实现无闪屏的弹出式菜单
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    if (menu == NULL || original_para == NULL)
        return 0;
    int menu_count = get_menu_count(menu);
    if (menu_count == 0)
        return 0;
    int actual_width = calculate_actual_width(original_para);
    int actual_height = calculate_actual_height(original_para, menu_count);
    struct PopMenu para = *original_para;
    cct_setcursor(CURSOR_INVISIBLE);
    cct_enable_mouse();
    int selected = 0;
    int last_selected = -1;
    int scroll_offset = 0;
    int last_scroll_offset = -1;
    int display_rows = (menu_count < para.high) ? menu_count : para.high;
    draw_menu_frame(&para, actual_width, actual_height);
    draw_all_menu_items(menu, &para, menu_count, selected, scroll_offset, actual_width);
    last_selected = selected;
    last_scroll_offset = scroll_offset;
    int return_value = 0; 
    while (true)
    {
        int MX, MY, MAction, keycode1, keycode2;
        int input_type = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
        if (input_type == CCT_KEYBOARD_EVENT)
        {
            if (keycode1 == 27)
            {
                return_value = 0;
                break;
            }
            else if (keycode1 == 13)
            {
                return_value = selected + 1;
                break;
            }
            else if (keycode1 == 0xe0)
            {
                if (keycode2 == KB_ARROW_UP)
                {
                    if (selected > 0)
                    {
                        selected--;
                        if (selected < scroll_offset)
                        {
                            scroll_offset = selected;
                        }
                    }
                }
                else if (keycode2 == KB_ARROW_DOWN)
                {
                    if (selected < menu_count - 1)
                    {
                        selected++;
                        if (selected >= scroll_offset + display_rows)
                        {
                            scroll_offset = selected - display_rows + 1;
                        }
                    }
                }
            }
        }
        else if (input_type == CCT_MOUSE_EVENT)
        {
            if (MAction == MOUSE_LEFT_BUTTON_CLICK)
            {
                if (MX >= para.start_x + 2 && MX < para.start_x + actual_width - 2 &&
                    MY >= para.start_y + 1 && MY < para.start_y + actual_height - 1)
                {
                    int clicked_item = MY - para.start_y - 1 + scroll_offset;
                    if (clicked_item >= 0 && clicked_item < menu_count)
                    {
                        return_value = clicked_item + 1;
                        break;
                    }
                }
            }
            else if (MAction == MOUSE_WHEEL_MOVED_UP)
            {
                if (scroll_offset > 0)
                {
                    scroll_offset--;
                    if (selected >= scroll_offset + display_rows)
                    {
                        selected = scroll_offset + display_rows - 1;
                    }
                }
            }
            else if (MAction == MOUSE_WHEEL_MOVED_DOWN)
            {
                if (scroll_offset + display_rows < menu_count)
                {
                    scroll_offset++;
                    if (selected < scroll_offset)
                    {
                        selected = scroll_offset;
                    }
                }
            }
        }
        if (scroll_offset != last_scroll_offset)
        {
            draw_all_menu_items(menu, &para, menu_count, selected, scroll_offset, actual_width);
        }
        else if (selected != last_selected)
        {
            if (last_selected >= scroll_offset && last_selected < scroll_offset + display_rows)
            {
                update_menu_item(menu, &para, last_selected, false, scroll_offset, actual_width, menu_count);
            }
            if (selected >= scroll_offset && selected < scroll_offset + display_rows)
            {
                update_menu_item(menu, &para, selected, true, scroll_offset, actual_width, menu_count);
            }
        }
        last_selected = selected;
        last_scroll_offset = scroll_offset;
    }
    cct_disable_mouse();
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cct_setcolor();
    return return_value;
}