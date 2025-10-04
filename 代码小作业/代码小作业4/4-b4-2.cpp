/*2351495 ������ ��ҵ��*/
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�cls()
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������const HANDLE hout
  �� �� ֵ����
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
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
		cout << "1.��I��J��K��L��������������(��Сд���ɣ������ͷ��겻�������ƣ��߽�ֹͣ)" << endl;
		cout << "2.��I��J��K��L��������������(��Сд���ɣ������ͷ��겻�������ƣ��߽����)" << endl;
		cout << "3.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽�ֹͣ��" << endl;
		cout << "4.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽���ƣ�" << endl;
		cout << "0.�˳�" << endl;
		cout << "[��ѡ��0-4] ";
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
			cout << "��Ϸ���������س������ز˵�.";
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
			cout << "��Ϸ���������س������ز˵�.";
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
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