/*2351495 大数据 闫业豪*/
#include<iostream>
#include <ctime>
using namespace std;
int main()
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	char password[17];
	int totallength, uppercount, lowercount, digitcount, othercount;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	if (!(cin >> totallength >> uppercount >> lowercount >> digitcount >> othercount))
	{
		cout << "输入非法" << endl;
		return 0;
	}
	if (totallength < 12 || totallength > 16) 
	{
		cout << "密码长度[" << totallength << "]不正确" << endl;
		return 0;
	}
	if (uppercount < 2 || uppercount > totallength)
	{
		cout << "大写字母个数[" << uppercount << "]不正确" << endl;
		return 0;
	}
	if (lowercount < 2 || lowercount > totallength)
	{
		cout << "小写字母个数[" << lowercount << "]不正确" << endl;
		return 0;
	}
	if (digitcount < 2 || digitcount > totallength)
	{
		cout << "数字个数[" << digitcount << "]不正确" << endl;
		return 0;
	}
	if (othercount < 2 || othercount > totallength)
	{
		cout << "其它符号个数[" << othercount << "]不正确" << endl;
		return 0;
	}
	if (uppercount + lowercount + digitcount + othercount > totallength)
	{
		cout << "所有字符类型之和[" << uppercount << "+" << lowercount << '+' << digitcount << '+' << othercount << "]大于总密码长度[" << totallength << ']' << endl;
		return 0;
	}
	cout << totallength << ' ' << uppercount << ' ' << lowercount << ' ' << digitcount << ' ' << othercount << endl;
	srand((unsigned int)(time(0)));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < totallength; j++)
			password[j] = 0;
		password[totallength] = '\0';
		//大写
		for (int j = 0; j < uppercount; j++)
		{
			int pos;
			do
			{
				pos = rand() % totallength;
			} while (password[pos] != 0);
			password[pos] = 'A' + rand() % 26;
		}
		//小写
		for (int j = 0; j < lowercount; j++)
		{
			int pos;
			do
			{
				pos = rand() % totallength;
			} while (password[pos] != 0);
			password[pos] = 'a' + rand() % 26;
		}
		//数字
		for (int j = 0; j < digitcount; j++)
		{
			int pos;
			do
			{
				pos = rand() % totallength;
			} while (password[pos] != 0);
			password[pos] = '0' + rand() % 10;
		}
		//符号
		for (int j = 0; j < othercount; j++)
		{
			int pos;
			do
			{
				pos = rand() % totallength;
			} while (password[pos] != 0);
			password[pos] = other[rand() % 15];
		}
		int remainingchars = totallength - (uppercount + lowercount + digitcount + othercount);
		for (int j = 0; j < remainingchars; j++)
		{
			int pos;
			do
			{
				pos = rand() % totallength;
			} while (password[pos] != 0);
			int charType = rand() % 4;
			switch (charType)
			{
			case 0: // 大写字母
				password[pos] = 'A' + rand() % 26;
				break;
			case 1: // 小写字母
				password[pos] = 'a' + rand() % 26;
				break;
			case 2: // 数字
				password[pos] = '0' + rand() % 10;
				break;
			case 3: // 其他符号
				password[pos] = other[rand() % 15];
				break;
			}
		}
		cout << password << endl;
	}
	return 0;
}