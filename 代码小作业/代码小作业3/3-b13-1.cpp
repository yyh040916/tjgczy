/*2351495 ������ ��ҵ��*/
#include <iostream>
#include<limits>
#include<iomanip>
using namespace std;
int main()
{
	int y = 0, m = 0, w = 0, d = 0;
	while (1)
	{
		cout << "���������(2000-2030)���·�(1-12) : ";
		if (!(cin >> y >> m))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if (y > 2030 || y < 2000 || m>12 || m < 1)
		{
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if (m == 1)
			d = 31;
		else if (m == 2)
		{
			if ((!(y % 4) && y % 100) || !(y % 400))
				d = 29;
			else
				d = 28;
		}
		else if (m == 3)
			d = 31;
		else if (m == 4)
			d = 30;
		else if (m == 5)
			d = 31;
		else if (m == 6)
			d = 30;
		else if (m == 7)
			d = 31;
		else if (m == 8)
			d = 31;
		else if (m == 9)
			d = 30;
		else if (m == 10)
			d = 31;
		else if (m == 11)
			d = 30;
		else if (m == 12)
			d = 31;
		while (1)
		{
			cout << "������" << y << "��" << m << "��1�յ�����(0-6��ʾ������-������) : ";
			if (!(cin >> w))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "����Ƿ�������������" << endl;
				continue;
			}
			if (w<0||w>6)
			{
				cout << "����Ƿ�������������" << endl;
				continue;
			}
			cout << endl;
			cout << y << "��" << m << "�µ�����Ϊ:" << endl;
			cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
			int t = w;
			for (int i = 0; i < w; i++) 
				cout << "        ";
			cout << setiosflags(ios::right);
			for (int i = 1; i <= d; i++)
			{
				t++;
				cout << "  " << setw(2) << i << "    ";
				if (t == 7)
				{
					cout << endl;
					t = 0;
				}
			}
			break;
		}
		cout << endl;
		break;
	}
	return 0;
}