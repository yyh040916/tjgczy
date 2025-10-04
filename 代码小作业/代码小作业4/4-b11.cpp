/*2351495 ������ ��ҵ��*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */
void print_space(int num)
{
	if (num > 0)
	{
		cout << ' ';
		print_space(num - 1);
	}
}
void print_left(char current)
{
	if (current > 'A')
	{
		cout << current;
		print_left(current - 1);
	}
}
void print_right(char current)
{
	if (current > 'A')
	{
		print_right(current - 1);
		cout << current;
	}
}
void print_line(char current)
{
	if (current == 'A')
	{
		cout << 'A';
	}
	else
	{
		print_left(current);
		cout << 'A';
		print_right(current);
	}
}
   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
void print_tower(bool order, char current, char end_ch)
{
	int num = end_ch - current;
	if (order)
	{
		if (current <= end_ch)
		{
			print_space(num);
			print_line(current);
			cout << endl;
			if (current < end_ch)
			{
				print_tower(order, current + 1, end_ch);
			}
		}
	}
	else
	{
		if (current >= 'A')
		{
			print_space(num);
			print_line(current);
			cout << endl;
			if (current > 'A')
			{
				print_tower(order, current - 1, end_ch);
			}
		}
	}
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A' + 1) * 2 - 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A' + 1) * 2 - 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(true, 'A', end_ch); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw((end_ch - 'A' + 1) * 2 - 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A' + 1) * 2 - 1) << "" << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(false, end_ch, end_ch); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << setfill('=') << setw((end_ch - 'A' + 1) * 2 - 1) << "" << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw((end_ch - 'A' + 1) * 2 - 1) << "" << endl;/* ����ĸ����������= */
	print_tower(true, 'A', end_ch);   //��ӡ A~�����ַ��������� 
	print_tower(false, end_ch-1, end_ch);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}