/*2351495 大数据 闫业豪*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double n;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> n;
	cout << "十亿位 : " << int(n / 1000000000) % 10 << endl;
	cout << "亿位   : " << int(n / 100000000) % 10 << endl;
	cout << "千万位 : " << int(n / 10000000) % 10 << endl;
	cout << "百万位 : " << int(n / 1000000) % 10 << endl;
	cout << "十万位 : " << int(n / 100000) % 10 << endl;
	cout << "万位   : " << int(n / 10000) % 10 << endl;
	cout << "千位   : " << int(n / 1000) % 10 << endl;
	cout << "百位   : " << int(n / 100) % 10 << endl;
	cout << "十位   : " << int(n / 10) % 10 << endl;
	n /= 10;
	n -= floor(n);
	n *= 1000;
	n += 0.001;
	cout << "圆     : " << int(n / 100) % 10 << endl;
	cout << "角     : " << int(n / 10) % 10 << endl;
	cout << "分     : " << int(n / 1) % 10 << endl;
	return 0;
}
