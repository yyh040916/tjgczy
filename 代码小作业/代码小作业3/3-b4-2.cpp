/*2351495 ������ ��ҵ��*/
#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.14159;
int main()
{
	int a, b, c;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> c;
	cout << setiosflags(ios::fixed) << setprecision(3);
	double area= 0.5 * sin(c * PI / 180) * a * b;
	cout << "�����ε����Ϊ : " << float(area) << endl;
	return 0;
}
