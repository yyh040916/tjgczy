/*2351495 大数据 闫业豪*/
#include<iostream>
using namespace std;
int main()
{
	int a[25],len=0,n;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (int i = 0; i < 20; i++,len++)
	{
		cin >> a[i];
		if (a[i] <= 0)
			break;
	}
	if(len>0)
	{
		cout << "原数组为：" << endl;
		for (int i = 0; i < len; i++)
			cout << a[i] << ' ';
		cout << endl;
	}
	else
	{
		cout << "无有效输入" << endl;
		return 0;
	}
	cin.clear();
	cin.ignore(2048, '\n');
	cout << "请输入要插入的正整数" << endl;
	cin >> n;
	int index = len;
	for (int i = 0; i < len; i++)
	{
		if (a[i] > n)
		{
			index = i;
			break;
		}
	}
	for (int i = len - 1; i >= index; i--)
		a[i + 1] = a[i];
	a[index] = n;
	for (int i = 0; i < len+1; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}