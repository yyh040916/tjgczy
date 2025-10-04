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
int mystrcmp(char s1[],char s2[])
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return s1[i] - s2[i];
}
void input(char ids[][8], char names[][9], int scores[])
{
	for (int i = 0; i < 10; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s %s %d", ids[i], names[i], &scores[i]);
	}
}
void sortbyiddesc(char ids[][8], char names[][9], int scores[])
{
	for (int i = 0; i < 10 - 1; i++)
	{
		int maxindex = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (mystrcmp(ids[j], ids[maxindex]) > 0)
			{
				maxindex = j;
			}
		}
		if (maxindex != i)
		{
			char tempId[9];
			mystrcpy(tempId, ids[i]);
			mystrcpy(ids[i], ids[maxindex]);
			mystrcpy(ids[maxindex], tempId);

			char tempName[9];
			mystrcpy(tempName, names[i]);
			mystrcpy(names[i], names[maxindex]);
			mystrcpy(names[maxindex], tempName);

			int tempScore = scores[i];
			scores[i] = scores[maxindex];
			scores[maxindex] = tempScore;
		}
	}
}
void print(char ids[][8], char names[][9], int scores[])
{
	printf("\n及格名单(学号降序):\n");
	for (int i = 0; i < 10; i++)
	{
		if (scores[i] >= 60)
			printf("%s %s %d\n", names[i], ids[i], scores[i]);
	}
}
int main()
{
	char ids[10][8];
	char names[10][9];
	int scores[10];
	input(ids, names, scores);
	sortbyiddesc(ids, names, scores);
	print(ids, names, scores);
	return 0;
}