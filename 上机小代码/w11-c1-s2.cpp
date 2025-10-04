/*2351495 ������ ��ҵ��*/
#include <iostream>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ��������������궨�塢ȫ��const������
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int n, a[10000], base;
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> n;
	cout << "������" << n << "��������" << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "���������[2..9]" << endl;
	cin >> base;
	cout << n << "������" << base << "���Ƹ�λΪ0�ĸ��� : " << countzero(a, n, base) << endl;
	return 0;
}
