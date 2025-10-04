/*2351495 大数据 闫业豪*/
#include<iostream>
#include<iomanip>
using namespace std;
const double PI = 3.14159;
int main()
{
	double r, h;
	cout << "请输入半径和高度" << endl;
	cin >> r >> h;
	cout << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2);
	cout << setw(11) << "圆周长" << ": " << 2 * PI * r << endl;
	cout << setw(11) << "圆面积" << ": " << PI * r * r << endl;
	cout << setw(11) << "圆球表面积" << ": " << 4 * PI * r * r << endl;
	cout << setw(11) << "圆球体积" << ": " << 4 * PI * r * r * r / 3 << endl;
	cout << setw(11) << "圆柱体积" << ": " << PI * r * r * h << endl;
	return 0;
}
