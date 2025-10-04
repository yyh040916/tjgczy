/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[1005], len = 0, count[105] = { 0 };
	printf("请输入成绩（最多1000个），负数结束输入\n");
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
		printf("输入的数组为:\n");
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
		printf("无有效输入\n");
		return 0;
	}
	printf("\n分数与人数的对应关系为:\n");
	for (int score = 100; score >= 00; score--)
	{
		if (count[score] > 0)
		{
			printf("%d %d\n", score, count[score]);
		}
	}
	return 0;
}