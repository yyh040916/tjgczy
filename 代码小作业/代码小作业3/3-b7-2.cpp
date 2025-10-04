/*2351495 大数据 闫业豪*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double n;
	cout << fixed << setprecision(2);
	cout << "请输入找零值：" << endl;
	cin >> n;
	int ans = 0, num50 = 0, num20 = 0, num10 = 0, num5 = 0, num1 = 0, num05 = 0, num01 = 0, num005 = 0, num002 = 0, num001 = 0;
	double n1 = floor(n), n2 = (n - floor(n)) * 100;
	int a = int(n1), b = int(n2);
	num50 = a / 50;
	a %= 50;
	num20 = a / 20;
	a %= 20;
	num10 = a / 10;
	a %= 10;
	num5 = a / 5;
	a %= 5;
	num1 = a;

	num05 = b / 50;
	b %= 50;
	num01 = b / 10;
	b %= 10;
	num005 = b / 5;
	b %= 5;
	num002 = b / 2;
	b %= 2;
	num001 = b;
	ans = num50 + num20 + num10 + num5 + num1 + num05 + num01 + num005 + num002 + num001;
    cout << "共" << ans << "张找零，具体如下：" << endl;
    if (num50 > 0) 
        cout << "50元 : " << num50 << "张" << endl;
    if (num20 > 0) 
        cout << "20元 : " << num20 << "张" << endl;
    if (num10 > 0)
        cout << "10元 : " << num10 << "张" << endl;
    if (num5 > 0)
        cout << "5元  : " << num5 << "张" << endl;
    if (num1 > 0) 
        cout << "1元  : " << num1 << "张" << endl;
    if (num05 > 0) 
        cout << "5角  : " << num05 << "张" << endl;
    if (num01 > 0) 
        cout << "1角  : " << num01 << "张" << endl;
    if (num005 > 0) 
        cout << "5分  : " << num005 << "张" << endl;
    if (num002 > 0) 
        cout << "2分  : " << num002 << "张" << endl;
    if (num001 > 0) 
        cout << "1分  : " << num001 << "张" << endl;
	return 0;
}
