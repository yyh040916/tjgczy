/*2351495 ������ ��ҵ��*/
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> n;
	cout << "��λ : " << n / 10000 % 10 << endl;
	cout << "ǧλ : " << n / 1000 % 10 << endl;
	cout << "��λ : " << n / 100 % 10 << endl;
	cout << "ʮλ : " << n / 10 % 10 << endl;
	cout << "��λ : " << n / 1 % 10 << endl;
	return 0;
}
