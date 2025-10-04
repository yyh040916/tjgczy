/*2351495 大数据 闫业豪*/
#include<iostream>
using namespace std;
int main()
{
	char str[3][128];
	int uppercase = 0, lowercase = 0, space = 0, digit = 0, other = 0;
	cout << "请输入第1行" << endl;
	cin.getline(str[0], 128);
	cout << "请输入第2行" << endl;
	cin.getline(str[1], 128);
	cout << "请输入第3行" << endl;
	cin.getline(str[2], 128);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; str[i][j] != '\0'; j++)
		{
			char c = str[i][j];
			if (c >= 'A' && c <= 'Z')
				uppercase++;
			else if (c >= 'a' && c <= 'z')
				lowercase++;
			else if (c >= '0' && c <= '9')
				digit++;
			else if (c == ' ')
				space++;
			else
				other++;
		}
	}
	cout << "大写 : " << uppercase << endl;
	cout << "小写 : " << lowercase << endl;
	cout << "数字 : " << digit << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other << endl;
	return 0;
}