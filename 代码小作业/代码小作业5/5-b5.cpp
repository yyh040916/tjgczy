/*2351495 ������ ��ҵ��*/
#include<iostream>
using namespace std;
void bubble_sort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int score[1005], len = 0, temp[1005];
	cout << "������ɼ������1000������������������" << endl;
	for (int i = 0; i < 1000; i++)
	{
		cin >> score[i];
		if (score[i] < 0)
			break;
		temp[len] = score[i];
		len++;
	}
	if (len > 0)
	{
		cout << "���������Ϊ:" << endl;
		int t = 0;
		for (int i = 0; i < len; i++)
		{
			cout << temp[i] << ' ';
			t++;
			if (t == 10)
			{
				cout << endl;
				t = 0;
			}
		}
		cout << endl << "���������εĶ�Ӧ��ϵΪ:" << endl;
		bubble_sort(temp, len);
		int rank = 1;
		cout << temp[0] << " " << rank << endl;
		for (int i = 1; i < len; i++)
		{
			if (temp[i] != temp[i - 1])
				rank = i + 1;
			cout << temp[i] << " " << rank << endl;
		}
	}
	else
	{
		cout << "����Ч����" << endl;
		return 0;
	}
	return 0;
}