/*2351495 ������ ��ҵ��*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double n;
	cout << fixed << setprecision(2);
	cout << "����������ֵ��" << endl;
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
    cout << "��" << ans << "�����㣬�������£�" << endl;
    if (num50 > 0) 
        cout << "50Ԫ : " << num50 << "��" << endl;
    if (num20 > 0) 
        cout << "20Ԫ : " << num20 << "��" << endl;
    if (num10 > 0)
        cout << "10Ԫ : " << num10 << "��" << endl;
    if (num5 > 0)
        cout << "5Ԫ  : " << num5 << "��" << endl;
    if (num1 > 0) 
        cout << "1Ԫ  : " << num1 << "��" << endl;
    if (num05 > 0) 
        cout << "5��  : " << num05 << "��" << endl;
    if (num01 > 0) 
        cout << "1��  : " << num01 << "��" << endl;
    if (num005 > 0) 
        cout << "5��  : " << num005 << "��" << endl;
    if (num002 > 0) 
        cout << "2��  : " << num002 << "��" << endl;
    if (num001 > 0) 
        cout << "1��  : " << num001 << "��" << endl;
	return 0;
}
