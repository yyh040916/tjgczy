/*2351495 大数据 闫业豪*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	cout << setprecision(10);
	int x = 0;
	double sum = 0, t = 1, m = 0;
	while (1)
	{
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if (x > 65 || x < -10)
		{
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		
		while (fabs(t) > 1e-6)
		{
			sum += t;
			m++;
			t = (double)t * x / m;
		}
		cout << "e^" << x << "=" << sum << endl;
		break;
	}
	return 0;
}