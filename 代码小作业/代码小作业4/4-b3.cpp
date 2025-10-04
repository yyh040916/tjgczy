/*2351495 ������ ��ҵ��*/
#include<iostream>
#include<iomanip>
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
	int w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	w = (w % 7 + 7) % 7;
	return w;
}
void calendar(int year, int month)
{
	int firstday = zeller(year, month, 1);
	int maxday=0;
	switch (month) 
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
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
		{
			maxday = 29;
		}
		else 
		{
			maxday = 28;
		}
		break;
	}
	cout << year << "��" << month << "��" << endl;
	/* ͷ���ָ��ߣ������� */
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

	for (int i = 0; i < firstday; i++)
	{
		cout << "        ";
	}
	int count = firstday;
	for (int j = 1; j <= maxday; j++)
	{
		cout << setiosflags(ios::right) << "  " << setw(2) << j << "    ";
		count++;
		if (count == 7)
		{
			cout << endl;
			count = 0;
		}
	}
	cout << endl;
	/* β���ָ��ߣ������� */
	cout << "======================================================" << endl;
}
int main()
{
	int y, m;
	while (1)
	{
		cout << "��������[1900-2100]����" << endl;
		if (!(cin >> y >> m ))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
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
		cout << endl;
		calendar(y, m);
		break;
	}
	return 0;
}
