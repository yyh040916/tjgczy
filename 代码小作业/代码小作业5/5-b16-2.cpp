/*2351495 ������ ��ҵ��*/
#include<iostream>
#include <string>
using namespace std;
void input(string ids[], string names[], int scores[], int indices[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> ids[i] >> names[i] >> scores[i];
		indices[i] = i;
	}
}
void sortbyscodeasc(string ids[], string names[], int scores[], int indices[])
{
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - 1 - i; j++)
		{
			if (scores[j] > scores[j + 1] || (scores[j] == scores[j + 1] && indices[j] > indices[j + 1]))
			{
				string tempId = ids[j];
				ids[j] = ids[j + 1];
				ids[j + 1] = tempId;

				string tempName = names[j];
				names[j] = names[j + 1];
				names[j + 1] = tempName;

				int tempScore = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = tempScore;

				int tempIndex = indices[j];
				indices[j] = indices[j + 1];
				indices[j + 1] = tempIndex;
			}
		}
	}
}
void print(string ids[], string names[], int scores[])
{
	cout << endl << "����������(�ɼ�����):" << endl;
	for(int i=0;i<10;i++)
		if(scores[i]<60)
			cout << names[i] << " " << ids[i] << " " << scores[i] << endl;
}
int main()
{
	string ids[10];
	string names[10];
	int scores[10];
	int indices[10];
	input(ids, names, scores, indices);
	sortbyscodeasc(ids, names, scores, indices);
	print(ids, names, scores);
	return 0;
}