/*2351495 大数据 闫业豪*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：cls()
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：const HANDLE hout
  返 回 值：无
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

char menu(const HANDLE hout)
{
	char key;
	while (1)
	{
		cls(hout);
		cout << "1.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界停止)" << endl;
		cout << "2.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界回绕)" << endl;
		cout << "3.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界停止）" << endl;
		cout << "4.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界回绕）" << endl;
		cout << "0.退出" << endl;
		cout << "[请选择0-4] ";
		key = _getch();
		if (key >= '0' && key <= '4')
		{
			break;
		}
	}
	return key;
}
int handle_x(int x, bool wrap) 
{
	if (wrap) 
	{
		if (x < 1) 
			return MAX_X;
		else if (x > MAX_X) 
			return 1;
		else return x;
	}
	else 
	{
		if (x < 1) 
			return 1;
		else if (x > MAX_X) 
			return MAX_X;
		else 
			return x;
	}
}

int handle_y(int y, bool wrap) 
{
	if (wrap) 
	{
		if (y < 1) 
			return MAX_Y;
		else if (y > MAX_Y) 
			return 1;
		else 
			return y;
	}
	else 
	{
		if (y < 1) 
			return 1;
		else if (y > MAX_Y) 
			return MAX_Y;
		else 
			return y;
	}
}
void move_by_ijkl(const HANDLE hout, int x, int y, bool wrap)
{
	int nowx = x, nowy = y;
	bool exitgame = false;
	while (!exitgame) 
	{
		int ch = _getch();
		if (ch == 'Q' || ch == 'q')
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			while (_getch() != 13);
			exitgame = 1;
			break;
		}
		ch = (ch >= 'a' && ch <= 'z') ? ch - 'a' + 'A' : ch;
		switch (ch)
		{
		case 'I': 
			nowy--; 
			break;
		case 'K': 
			nowy++; 
			break;
		case 'J': 
			nowx--; 
			break;
		case 'L': 
			nowx++; 
			break;
		}

		if (ch == ' ') 
		{
			showch(hout, nowx, nowy, ' ');
		}

		nowx = handle_x(nowx, wrap);
		nowy = handle_y(nowy, wrap);

		gotoxy(hout, nowx, nowy);
	}
}
void move_by_arrow(const HANDLE hout, int x, int y, bool wrap)
{
	int nowx = x, nowy = y;
	bool exitgame = false;
	while (!exitgame)
	{
		int ch = _getch();
		if (ch == 'Q' || ch == 'q')
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			while (_getch() != 13);
			exitgame = 1;
			break;
		}
		if (ch == 0xE0)
		{
			int arrow = _getch();
			switch (arrow) 
			{
			case 72: 
				nowy--; 
				break; 
			case 80: 
				nowy++; 
				break; 
			case 75: 
				nowx--; 
				break; 
			case 77: 
				nowx++; 
				break; 
			}
		}

		if (ch == ' ')
		{
			showch(hout, nowx, nowy, ' ');
		}

		nowx = handle_x(nowx, wrap);
		nowy = handle_y(nowy, wrap);

		gotoxy(hout, nowx, nowy);
	}
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	while (true)
	{
		char choice = menu(hout);
		if (choice == '0')
		{
			putchar('0');
			break;
		}
		cls(hout);
		init_border(hout);
		int nowx = MAX_X / 2, nowy = MAX_Y / 2;
		bool wrapmode = (choice == '2' || choice == '4');
		bool usearrow = (choice == '3' || choice == '4');
		gotoxy(hout, nowx, nowy);
		if (usearrow) 
		{
			move_by_arrow(hout, nowx, nowy, wrapmode);
		}
		else 
		{
			move_by_ijkl(hout, nowx, nowy, wrapmode);
		}
	}
	return 0;
}