/*2351495 ������ ��ҵ��*/
#include<iostream>
using namespace std;
int main()
{
	char str[3][128];
	int uppercase = 0, lowercase = 0, space = 0, digit = 0, other = 0;
	cout << "�������1��" << endl;
	cin.getline(str[0], 128);
	cout << "�������2��" << endl;
	cin.getline(str[1], 128);
	cout << "�������3��" << endl;
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
	cout << "��д : " << uppercase << endl;
	cout << "Сд : " << lowercase << endl;
	cout << "���� : " << digit << endl;
	cout << "�ո� : " << space << endl;
	cout << "���� : " << other << endl;
	return 0;
}