/*2351495 ������ ��ҵ��*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double n;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> n;
	if (n == 0) 
	{
		cout << "��д�����:\n��Բ��" << endl;
		return 0;
	}
	int n1 = int(n / 1000000000) % 10;
	int n2 = int(n / 100000000) % 10;
	int n3 = int(n / 10000000) % 10;
	int n4 = int(n / 1000000) % 10;
	int n5 = int(n / 100000) % 10;
	int n6 = int(n / 10000) % 10;
	int n7 = int(n / 1000) % 10;
	int n8 = int(n / 100) % 10;
	int n9 = int(n / 10) % 10;
	n /= 10;
	n -= floor(n);
	n *= 1000;
	n += 0.001;
	int n10 = int(n / 100) % 10;
	int n11 = int(n / 10) % 10;
	int n12 = int(n / 1) % 10;
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	cout << "��д�����:" << endl;
	//ʮ��
	if (n1 == 1)
		cout << "Ҽʰ";
	else if (n1 == 2)
		cout << "��ʰ";
	else if (n1 == 3)
		cout << "��ʰ";
	else if (n1 == 4)
		cout << "��ʰ";
	else if (n1 == 5)
		cout << "��ʰ";
	else if (n1 == 6)
		cout << "½ʰ";
	else if (n1 == 7)
		cout << "��ʰ";
	else if (n1 == 8)
		cout << "��ʰ";
	else if (n1 == 9)
		cout << "��ʰ";
	//��
	if (n2 == 0 && n1 != 0)
		cout << "��";
	else if (n2 == 1)
		cout << "Ҽ��";
	else if (n2 == 2)
		cout << "����";
	else if (n2 == 3)
		cout << "����";
	else if (n2 == 4)
		cout << "����";
	else if (n2 == 5)
		cout << "����";
	else if (n2 == 6)
		cout << "½��";
	else if (n2 == 7)
		cout << "����";
	else if (n2 == 8)
		cout << "����";
	else if (n2 == 9)
		cout << "����";
	if (flag3 == 0 && !n3 && !n4 && !n5 && !n6 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12 && (n1 || n2))
	{
		cout << "Բ��";
		flag3 = 1;
	}
	//ǧ��
	if (n3 == 0)
	{
		if ((n4 || n5 || n6) && (n1 || n2))
		{
			cout << "��";
			flag1 = 1;
		}
	}
	else if (n3 == 1)
		cout << "ҼǪ";
	else if (n3 == 2)
		cout << "��Ǫ";
	else if (n3 == 3)
		cout << "��Ǫ";
	else if (n3 == 4)
		cout << "��Ǫ";
	else if (n3 == 5)
		cout << "��Ǫ";
	else if (n3 == 6)
		cout << "½Ǫ";
	else if (n3 == 7)
		cout << "��Ǫ";
	else if (n3 == 8)
		cout << "��Ǫ";
	else if (n3 == 9)
		cout << "��Ǫ";
	//����
	if (n4 == 0)
	{
		if (!flag1 && ((n1 || n2) || n3) && (n5 || n6))
		{
			cout << "��";
			flag1 = 1;
		}
	}
	else if (n4 == 1)
		cout << "Ҽ��";
	else if (n4 == 2)
		cout << "����";
	else if (n4 == 3)
		cout << "����";
	else if (n4 == 4)
		cout << "����";
	else if (n4 == 5)
		cout << "���";
	else if (n4 == 6)
		cout << "½��";
	else if (n4 == 7)
		cout << "���";
	else if (n4 == 8)
		cout << "�ư�";
	else if (n4 == 9)
		cout << "����";
	//ʮ��
	if (n5 == 0)
	{
		if ((!flag1 && ((n1 || n2) || n3 || n4) && (n6)) || (flag1 && n4 != 0 && n6 != 0))
		{
			cout << "��";
			flag1 = 1;
		}
	}
	else if (n5 == 1)
		cout << "Ҽʰ";
	else if (n5 == 2)
		cout << "��ʰ";
	else if (n5 == 3)
		cout << "��ʰ";
	else if (n5 == 4)
		cout << "��ʰ";
	else if (n5 == 5)
		cout << "��ʰ";
	else if (n5 == 6)
		cout << "½ʰ";
	else if (n5 == 7)
		cout << "��ʰ";
	else if (n5 == 8)
		cout << "��ʰ";
	else if (n5 == 9)
		cout << "��ʰ";
	//��
	if (n6 == 0)
	{
		if (n3 || n4 || n5)
			cout << "��";
	}
	else if (n6 == 1)
		cout << "Ҽ��";
	else if (n6 == 2)
		cout << "����";
	else if (n6 == 3)
		cout << "����";
	else if (n6 == 4)
		cout << "����";
	else if (n6 == 5)
		cout << "����";
	else if (n6 == 6)
		cout << "½��";
	else if (n6 == 7)
		cout << "����";
	else if (n6 == 8)
		cout << "����";
	else if (n6 == 9)
		cout << "����";
	if (flag3 == 0 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12)
	{
		cout << "Բ��";
		flag3 = 1;
	}
	//ǧ
	if (n7 == 0)
	{
		if (((n1 || n2) || (n3 || n4 || n5 || n6)) && (n8 || n9 || n10))
		{
			cout << "��";
			flag2 = 1;
		}
	}
	else if (n7 == 1)
		cout << "ҼǪ";
	else if (n7 == 2)
		cout << "��Ǫ";
	else if (n7 == 3)
		cout << "��Ǫ";
	else if (n7 == 4)
		cout << "��Ǫ";
	else if (n7 == 5)
		cout << "��Ǫ";
	else if (n7 == 6)
		cout << "½Ǫ";
	else if (n7 == 7)
		cout << "��Ǫ";
	else if (n7 == 8)
		cout << "��Ǫ";
	else if (n7 == 9)
		cout << "��Ǫ";
	//��
	if (n8 == 0)
	{
		if (!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7) && (n9 || n10))
		{
			cout << "��";
			flag2 = 1;
		}
	}
	else if (n8 == 1)
		cout << "Ҽ��";
	else if (n8 == 2)
		cout << "����";
	else if (n8 == 3)
		cout << "����";
	else if (n8 == 4)
		cout << "����";
	else if (n8 == 5)
		cout << "���";
	else if (n8 == 6)
		cout << "½��";
	else if (n8 == 7)
		cout << "���";
	else if (n8 == 8)
		cout << "�ư�";
	else if (n8 == 9)
		cout << "����";
	//ʮ
	if (n9 == 0)
	{
		if ((!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7 || n8) && (n10)) || (flag2 && n8 != 0 && n10 != 0))
		{
			cout << "��";
			flag2 = 1;
		}
	}
	else if (n9 == 1)
		cout << "Ҽʰ";
	else if (n9 == 2)
		cout << "��ʰ";
	else if (n9 == 3)
		cout << "��ʰ";
	else if (n9 == 4)
		cout << "��ʰ";
	else if (n9 == 5)
		cout << "��ʰ";
	else if (n9 == 6)
		cout << "½ʰ";
	else if (n9 == 7)
		cout << "��ʰ";
	else if (n9 == 8)
		cout << "��ʰ";
	else if (n9 == 9)
		cout << "��ʰ";
	//��
	if (n10 == 0)
		cout << "";
	else if (n10 == 1)
		cout << "Ҽ";
	else if (n10 == 2)
		cout << "��";
	else if (n10 == 3)
		cout << "��";
	else if (n10 == 4)
		cout << "��";
	else if (n10 == 5)
		cout << "��";
	else if (n10 == 6)
		cout << "½";
	else if (n10 == 7)
		cout << "��";
	else if (n10 == 8)
		cout << "��";
	else if (n10 == 9)
		cout << "��";

	if (flag3 == 0 && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10))
	{
		cout << "Բ";
		if (flag3 == 0 && !n11 && !n12)
		{
			cout << "��";
			flag3 = 1;
		}
	}
	if (flag3 == 1)
	{
		cout << endl;
		return 0;
	}
	if (n11 == 0)
	{
		if (n12 && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10))
		{
			cout << "��";
		}
	}
	else if (n11 == 1)
		cout << "Ҽ��";
	else if (n11 == 2)
		cout << "����";
	else if (n11 == 3)
		cout << "����";
	else if (n11 == 4)
		cout << "����";
	else if (n11 == 5)
		cout << "���";
	else if (n11 == 6)
		cout << "½��";
	else if (n11 == 7)
		cout << "���";
	else if (n11 == 8)
		cout << "�ƽ�";
	else if (n11 == 9)
		cout << "����";

	if (n12 == 0)
		cout << "��";
	else if (n12 == 1)
		cout << "Ҽ��";
	else if (n12 == 2)
		cout << "����";
	else if (n12 == 3)
		cout << "����";
	else if (n12 == 4)
		cout << "����";
	else if (n12 == 5)
		cout << "���";
	else if (n12 == 6)
		cout << "½��";
	else if (n12 == 7)
		cout << "���";
	else if (n12 == 8)
		cout << "�Ʒ�";
	else if (n12 == 9)
		cout << "����";
	cout << endl;
	return 0;
}
