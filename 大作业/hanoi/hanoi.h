/*2351495 ������ ��ҵ��*/
#pragma once

/* ������const���������ͷ�ļ��������� */


/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
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
// ���ڴ�С
const int win_width = 1000, win_high = 900;
// �����ߴ�
const int pillar_width = HDC_Base_Width;
const int base_height = HDC_Base_High;
// �������Բ�̿�Ȳ�ȷ������������
const int max_layer = MAX_LAYER;
const int max_disk_width = (3 + 2 * (max_layer - 1)) * pillar_width;
const int base_width = max_disk_width * 11/10; 
// ���Ӹ߶�
const int pillar_height = (HDC_Start_Y - HDC_Top_Y) * 8 / 10;
// ������ʼ����
const int start_x = HDC_Start_X;
const int base_y = HDC_Start_Y;
// ����������������
const int center1_x = win_width / 5;      
const int center3_x = win_width * 4 / 5;  
const int center2_x = (center1_x + center3_x) / 2;