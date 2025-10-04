/*2351495 大数据 闫业豪*/
#include"hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
int main()
{
	/* 将这段复制到main的最前面 */
	cout << "请确认当前cmd窗口的大小为40行*120列以上，字体为新宋体/16，按C继续，Q退出" << endl;
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
			return 0;
	}
	/* 从这里继续你的程序 */
	char choice;
	while (true)
	{
		choice = menu();
		if (choice == '0')
		{
			cct_gotoxy(20, 35);
			return 0;
		}
		cout << endl << endl;
		switch (choice)
		{
		case '1':
			solve_basic_hanoi();
			cout << endl;
			break;
		case '2':
			solve_with_step_count();
			cout << endl;
			break;
		case '3':
			solve_shuiping();
			cout << endl;
			break;
		case '4':
			solve_both_arrays();
			cout << endl;
			break;
		case '5':
			prepare_graphical_pillars();
			cout << endl;
			break;
		case '6':
			prepare_graphical_disks();
			cout << endl;
			break;
		case '7':
			first_disk_move();
			cout << endl;
			break;
		case '8':
			auto_move_hanoi();
			cout << endl;
			break;
		case '9':
			interactive_move_hanoi();
			cout << endl;
			break;
		}
	}
	return 0;
}