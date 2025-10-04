/*2351495 大数据 闫业豪*/
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
		cout << "请输入年[1900-2100]、月、日：" << endl;
		if (!(cin >> y>>m>>d))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (y < 1900 || y>2100)
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (m < 1 || m > 12)
		{
			cout << "月份不正确，请重新输入" << endl;
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
			cout << "日不正确，请重新输入" << endl;
			continue;
		}
		w = zeller(y, m, d);
		switch (w)
		{
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
		}
		break;
	}
	return 0;
}