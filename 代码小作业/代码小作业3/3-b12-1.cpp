/*2351495 大数据 闫业豪*/
#include <iostream>
#include<limits>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		if (!(cin >> x))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else if (x >= 0 && x <= 100)
			break;
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}