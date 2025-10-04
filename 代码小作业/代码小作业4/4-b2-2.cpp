/*2351495 ������ ��ҵ��*/
#include<iostream>
#include<limits>
using namespace std;
int zeller(int y, int m, int d)
{
	if (m < 3)
	{
		m += 12;
		y -= 1;
	}
	int c = y / 100;
	y = y % 100;
	int w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5 )+ d - 1;
	w = (w % 7 + 7) % 7;
	return w;
}
int main()
{
	int y, m, d, w;
	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		if (!(cin >> y>>m>>d))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (y < 1900 || y>2100)
		{
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		if (m < 1 || m > 12)
		{
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		int maxday=0;
		switch (m)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			maxday = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			maxday = 30;
			break;
		case 2:
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) 
			{
				maxday = 29;
			}
			else 
			{
				maxday = 28;
			}
			break;
		}
		if (d<0 || d>maxday)
		{
			cout << "�ղ���ȷ������������" << endl;
			continue;
		}
		w = zeller(y, m, d);
		switch (w)
		{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
		}
		break;
	}
	return 0;
}