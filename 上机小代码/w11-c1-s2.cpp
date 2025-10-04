/*2351495 大数据 闫业豪*/
#include <iostream>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（不包括宏定义、全局const变量）
   ---------------------------------------------------------------------
*/
bool is_lastzero(int num, int base)
{
	if (num == 0)
		return false;
	int lastnum = num % base;
	return lastnum == 0;
}
int countzero(int a[], int n, int base)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (is_lastzero(a[i], base))
		{
			count++;
		}
	}
	return count;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	int n, a[10000], base;
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> n;
	cout << "请输入" << n << "个正整数" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "请输入基数[2..9]" << endl;
	cin >> base;
	cout << n << "个数中" << base << "进制个位为0的个数 : " << countzero(a, n, base) << endl;
	return 0;
}
