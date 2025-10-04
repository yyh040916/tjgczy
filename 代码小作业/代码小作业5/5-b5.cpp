/*2351495 大数据 闫业豪*/
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
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
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
		cout << "输入的数组为:" << endl;
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
		cout << endl << "分数与名次的对应关系为:" << endl;
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
		cout << "无有效输入" << endl;
		return 0;
	}
	return 0;
}