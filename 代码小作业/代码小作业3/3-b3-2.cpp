/*2351495 ������ ��ҵ��*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double n;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> n;
	cout << "ʮ��λ : " << int(n / 1000000000) % 10 << endl;
	cout << "��λ   : " << int(n / 100000000) % 10 << endl;
	cout << "ǧ��λ : " << int(n / 10000000) % 10 << endl;
	cout << "����λ : " << int(n / 1000000) % 10 << endl;
	cout << "ʮ��λ : " << int(n / 100000) % 10 << endl;
	cout << "��λ   : " << int(n / 10000) % 10 << endl;
	cout << "ǧλ   : " << int(n / 1000) % 10 << endl;
	cout << "��λ   : " << int(n / 100) % 10 << endl;
	cout << "ʮλ   : " << int(n / 10) % 10 << endl;
	n /= 10;
	n -= floor(n);
	n *= 1000;
	n += 0.001;
	cout << "Բ     : " << int(n / 100) % 10 << endl;
	cout << "��     : " << int(n / 10) % 10 << endl;
	cout << "��     : " << int(n / 1) % 10 << endl;
	return 0;
}
