/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[1005], len = 0, count[105] = { 0 };
	printf("������ɼ������1000������������������\n");
	for (int i = 0; i < 1000; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] < 0)
			break;
		if (a[i] <= 100)
		{
			count[a[i]]++;
			len++;
		}
	}
	if (len > 0)
	{
		printf("���������Ϊ:\n");
		int t = 0;
		for (int i = 0; i < len; i++)
		{
			printf("%d ", a[i]);
			t++;
			if (t == 10)
			{
				printf("\n");
				t = 0;
			}
		}
	}
	else
	{
		printf("����Ч����\n");
		return 0;
	}
	printf("\n�����������Ķ�Ӧ��ϵΪ:\n");
	for (int score = 100; score >= 00; score--)
	{
		if (count[score] > 0)
		{
			printf("%d %d\n", score, count[score]);
		}
	}
	return 0;
}