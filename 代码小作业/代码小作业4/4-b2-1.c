/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int zeller(int y, int m, int d)
{
	if (m < 3)
	{
		m += 12;
		y -= 1;
	}
	int c = y / 100;
	y = y % 100;
	int w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	w = (w % 7 + 7) % 7;
	return w;
}
int main()
{
	int y, m, d, w;
	while (1)
	{
		printf("请输入年[1900-2100]、月、日：\n");
		if (scanf("%d%d%d", &y, &m, &d) != 3) 
		{
			while (getchar() != '\n'); 
			continue;
		}
		if (y < 1900 || y > 2100) 
		{
			printf("年份不正确，请重新输入\n");
			continue;
		}
		if (m < 1 || m > 12) 
		{
			printf("月份不正确，请重新输入\n");
			continue;
		}
		int maxday=0;
		switch (m) 
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			maxday = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			maxday = 30;
			break;
		case 2:
			if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) 
			{
				maxday = 29;
			}
			else 
			{
				maxday = 28;
			}
			break;
		}
		if (d < 0 || d > maxday) 
		{
			printf("日不正确，请重新输入\n");
			continue;
		}
		w = zeller(y, m, d);
		switch (w) 
		{
		case 0:
			printf("星期日\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
		}
		break;
	}
	return 0;
}