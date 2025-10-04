/*2351495 大数据 闫业豪*/
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> n;
	cout << "万位 : " << n / 10000 % 10 << endl;
	cout << "千位 : " << n / 1000 % 10 << endl;
	cout << "百位 : " << n / 100 % 10 << endl;
	cout << "十位 : " << n / 10 % 10 << endl;
	cout << "个位 : " << n / 1 % 10 << endl;
	return 0;
}
