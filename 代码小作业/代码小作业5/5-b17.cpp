/*2351495 ������ ��ҵ��*/
#include<iostream>
#include <ctime>
using namespace std;
int main()
{
	static const char other[] = "!@#$%^&*-_=+,.?";
	char password[17];
	int totallength, uppercount, lowercount, digitcount, othercount;
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	if (!(cin >> totallength >> uppercount >> lowercount >> digitcount >> othercount))
	{
		cout << "����Ƿ�" << endl;
		return 0;
	}
	if (totallength < 12 || totallength > 16) 
	{
		cout << "���볤��[" << totallength << "]����ȷ" << endl;
		return 0;
	}
	if (uppercount < 2 || uppercount > totallength)
	{
		cout << "��д��ĸ����[" << uppercount << "]����ȷ" << endl;
		return 0;
	}
	if (lowercount < 2 || lowercount > totallength)
	{
		cout << "Сд��ĸ����[" << lowercount << "]����ȷ" << endl;
		return 0;
	}
	if (digitcount < 2 || digitcount > totallength)
	{
		cout << "���ָ���[" << digitcount << "]����ȷ" << endl;
		return 0;
	}
	if (othercount < 2 || othercount > totallength)
	{
		cout << "�������Ÿ���[" << othercount << "]����ȷ" << endl;
		return 0;
	}
	if (uppercount + lowercount + digitcount + othercount > totallength)
	{
		cout << "�����ַ�����֮��[" << uppercount << "+" << lowercount << '+' << digitcount << '+' << othercount << "]���������볤��[" << totallength << ']' << endl;
		return 0;
	}
	cout << totallength << ' ' << uppercount << ' ' << lowercount << ' ' << digitcount << ' ' << othercount << endl;
	srand((unsigned int)(time(0)));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < totallength; j++)
			password[j] = 0;
		password[totallength] = '\0';
		//��д
		for (int j = 0; j < uppercount; j++)
		{
			int pos;
			do
			{
				pos = rand() % totallength;
			} while (password[pos] != 0);
			password[pos] = 'A' + rand() % 26;
		}
		//Сд
		for (int j = 0; j < lowercount; j++)
		{
			int pos;
			do
			{
				pos = rand() % totallength;
			} while (password[pos] != 0);
			password[pos] = 'a' + rand() % 26;
		}
		//����
		for (int j = 0; j < digitcount; j++)
		{
			int pos;
			do
			{
				pos = rand() % totallength;
			} while (password[pos] != 0);
			password[pos] = '0' + rand() % 10;
		}
		//����
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
			case 0: // ��д��ĸ
				password[pos] = 'A' + rand() % 26;
				break;
			case 1: // Сд��ĸ
				password[pos] = 'a' + rand() % 26;
				break;
			case 2: // ����
				password[pos] = '0' + rand() % 10;
				break;
			case 3: // ��������
				password[pos] = other[rand() % 15];
				break;
			}
		}
		cout << password << endl;
	}
	return 0;
}