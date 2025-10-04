/*2351495 大数据 闫业豪*/
#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.14159;
int main()
{
	int a, b, c;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> c;
	cout << setiosflags(ios::fixed) << setprecision(3);
	double area= 0.5 * sin(c * PI / 180) * a * b;
	cout << "三角形的面积为 : " << float(area) << endl;
	return 0;
}
