/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void mystrcpy(char dest[], char src[])
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
void input(char ids[][8], char names[][9], int scores[], int indices[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", ids[i], names[i], &scores[i]);
		indices[i] = i;
	}
}
void sortbyscoredesc(char ids[][8], char names[][9], int scores[], int indices[])
{
	for (int i = 0; i < 10 - 1; i++) 
	{
		for (int j = 0; j < 10 - 1 - i; j++) 
		{
			if (scores[j] < scores[j + 1] || (scores[j] == scores[j + 1] && indices[j] > indices[j + 1])) 
			{
				char tempId[8];
				mystrcpy(tempId, ids[j]);
				mystrcpy(ids[j], ids[j + 1]);
				mystrcpy(ids[j + 1], tempId);

				char tempName[9];
				mystrcpy(tempName, names[j]);
				mystrcpy(names[j], names[j + 1]);
				mystrcpy(names[j + 1], tempName);

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
void print(char ids[][8], char names[][9], int scores[])
{
	printf("\n全部学生(成绩降序):\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%s %s %d\n", names[i], ids[i], scores[i]);
	}
}
int main()
{
	char ids[10][8];
	char names[10][9];
	int scores[10];
	int indices[10];
	input(ids, names, scores, indices);
	sortbyscoredesc(ids, names, scores, indices);
	print(ids, names, scores);
	return 0;
}