/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int y = 0, m = 0, w = 0, d = 0;
	int a;
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		scanf("%d %d", &y, &m);
		while ((a = getchar()) != EOF && a != '\n');
		if (y < 2000 || y>2030 || m < 1 || m>12)
		{
			printf("输入非法，请重新输入\n");
			continue;
		}
		if (m == 1)
			d = 31;
		else if (m == 2)
		{
			if ((!(y % 4) && y % 100) || !(y % 400))
				d = 29;
			else
				d = 28;
		}
		else if (m == 3)
			d = 31;
		else if (m == 4)
			d = 30;
		else if (m == 5)
			d = 31;
		else if (m == 6)
			d = 30;
		else if (m == 7)
			d = 31;
		else if (m == 8)
			d = 31;
		else if (m == 9)
			d = 30;
		else if (m == 10)
			d = 31;
		else if (m == 11)
			d = 30;
		else if (m == 12)
			d = 31;
		while (1)
		{
			printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", y, m);
			scanf("%d", &w);
			while ((a = getchar()) != EOF && a != '\n')
			{
				printf("输入非法，请重新输入\n");
			}
			if (w < 0 || w>6)
			{
				printf("输入非法，请重新输入\n");
				continue;
			}
			printf("\n");
			printf("%d年%d月的月历为:\n", y, m);
			printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
			int t = w;
			for (int i = 0; i < w; i++)
				printf("        ");
			for (int i = 1; i <= d; i++)
			{
				t++;
				printf("  %2d    ", i);
				if (t == 7)
				{
					printf("\n");
					t = 0;
				}
			}
			break;
		}
		printf("\n");
		break;
	}
	return 0;
}