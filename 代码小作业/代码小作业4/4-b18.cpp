/*2351495 大数据 闫业豪*/
#include<iostream>
using namespace std;
int max(int a, int b)
{
	return (a > b ? a : b);
}
int max(int a, int b, int c)
{
	int t = a > b ? a : b;
	return (t > c ? t : c);
}
int max(int a, int b, int c, int d)
{
	int m = a > b ? a : b;
	int n = c > d ? c : d;
	return (m > n ? m : n);
}
int main()
{
	int num=0, a=0, b=0, c=0, d=0;
	while (true)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		if (!(cin>>num))
		{
			cin.clear();
			cin.ignore(2048, '\n');
			continue;
		}
		if (num < 2 || num>4)
		{
			cout << "个数输入错误" << endl;
			break;
		}
		if (num == 2)
		{
			cin >> a >> b;
			if(!cin.good())
			{
				cin.clear();
				cin.ignore(2048, '\n');
				continue;
			}
			if (a <= 0 || b <= 0)
			{
				cin.clear();
				cin.ignore(2048, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(2048, '\n');
			break;
		}
		else if (num == 3)
		{
			cin >> a >> b >> c;
			if (cin.good() == 0 || a <= 0 || b <= 0 || c <= 0)
			{
				cin.clear();
				cin.ignore(2048, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(2048, '\n');
			break;
		}
		else if (num == 4)
		{
			cin >> a >> b >> c >> d;
			if (cin.good() == 0 || a <= 0 || b <= 0 || c <= 0 || d <= 0)
			{
				cin.clear();
				cin.ignore(2048, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(2048, '\n');
			break;
		}
	}
	if(num==2)
		cout << "max=" << max(a, b) << endl;
	else if(num==3)
		cout << "max=" << max(a, b, c) << endl;
	else
		cout << "max=" << max(a, b, c, d) << endl;
	return 0;
}