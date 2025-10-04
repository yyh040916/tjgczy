/*2351495 大数据 闫业豪*/
#include <iostream>
#include<limits>
#include<iomanip>
using namespace std;
int main()
{
	int y = 0, m = 0, w = 0, d = 0;
	while (1)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		if (!(cin >> y >> m))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (y > 2030 || y < 2000 || m>12 || m < 1)
		{
			cout << "输入非法，请重新输入" << endl;
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
			cout << "请输入" << y << "年" << m << "月1日的星期(0-6表示星期日-星期六) : ";
			if (!(cin >> w))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入非法，请重新输入" << endl;
				continue;
			}
			if (w<0||w>6)
			{
				cout << "输入非法，请重新输入" << endl;
				continue;
			}
			cout << endl;
			cout << y << "年" << m << "月的月历为:" << endl;
			cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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