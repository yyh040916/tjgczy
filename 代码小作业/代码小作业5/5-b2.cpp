/*2351495 大数据 闫业豪*/
#include<iostream>
using namespace std;
int main()
{
	bool a[100] = { 0 };
	for (int pindex = 1; pindex <= 100; pindex++)
	{
		for (int lindex = pindex; lindex <= 100; lindex++)
		{
			if (lindex % pindex == 0)
				a[lindex-1] = !a[lindex-1];
		}
	}
	for (int i = 0; i < 100; i++) 
	{
		if (a[i]) 
		{
			cout << (i + 1) << " ";
		}
	}
	cout << endl;
	return 0;
}