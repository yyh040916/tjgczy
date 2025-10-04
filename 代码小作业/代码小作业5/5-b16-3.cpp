/*2351495 大数据 闫业豪*/
#include<iostream>
#include <string>
using namespace std;
void input(string ids[], string names[], int scores[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> ids[i] >> names[i] >> scores[i];
	}
}
void sortbyidasc(string ids[], string names[], int scores[])
{
	for (int i = 0; i < 10 - 1; i++)
	{
		int minindex = i;
		for (int j = i + 1; j < 10; j++)
			if (ids[j] < ids[minindex])
				minindex = j;
		if (minindex != i)
		{
			string tempId = ids[i];
			ids[i] = ids[minindex];
			ids[minindex] = tempId;

			string tempName = names[i];
			names[i] = names[minindex];
			names[minindex] = tempName;

			int tempScore = scores[i];
			scores[i] = scores[minindex];
			scores[minindex] = tempScore;
		}
	}
}
void print(string ids[], string names[], int scores[]) 
{
	cout << endl << "全部学生(学号升序):" << endl;
	for (int i = 0; i < 10; i++)
		cout << names[i] << " " << ids[i] << " " << scores[i] << endl;
}
int main()
{
	string ids[10];
	string names[10];
	int scores[10];
	input(ids, names, scores);
	sortbyidasc(ids, names, scores);
	print(ids, names, scores);
	return 0;
}