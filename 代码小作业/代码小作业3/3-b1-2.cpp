/*2351495 ������ ��ҵ��*/
#include<iostream>
#include<iomanip>
using namespace std;
const double PI = 3.14159;
int main()
{
	double r, h;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2);
	cout << setw(11) << "Բ�ܳ�" << ": " << 2 * PI * r << endl;
	cout << setw(11) << "Բ���" << ": " << PI * r * r << endl;
	cout << setw(11) << "Բ������" << ": " << 4 * PI * r * r << endl;
	cout << setw(11) << "Բ�����" << ": " << 4 * PI * r * r * r / 3 << endl;
	cout << setw(11) << "Բ�����" << ": " << PI * r * r * h << endl;
	return 0;
}
