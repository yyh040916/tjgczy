/*2351495 大数据 闫业豪*/
#pragma once

/* 将所有const常量定义的头文件包含进来 */


/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
#include "hanoi_const_value.h"
#include "cmd_console_tools.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Windows.h"
char menu();
void solve_basic_hanoi();
void solve_with_step_count();
void solve_shuiping();
void solve_both_arrays();
void prepare_graphical_pillars();
void prepare_graphical_disks();
void auto_move_hanoi();
void first_disk_move();
void interactive_move_hanoi();
// 窗口大小
const int win_width = 1000, win_high = 900;
// 基本尺寸
const int pillar_width = HDC_Base_Width;
const int base_height = HDC_Base_High;
// 计算最大圆盘宽度并确保底座比它大
const int max_layer = MAX_LAYER;
const int max_disk_width = (3 + 2 * (max_layer - 1)) * pillar_width;
const int base_width = max_disk_width * 11/10; 
// 柱子高度
const int pillar_height = (HDC_Start_Y - HDC_Top_Y) * 8 / 10;
// 基本起始坐标
const int start_x = HDC_Start_X;
const int base_y = HDC_Start_Y;
// 三个柱子中心坐标
const int center1_x = win_width / 5;      
const int center3_x = win_width * 4 / 5;  
const int center2_x = (center1_x + center3_x) / 2;