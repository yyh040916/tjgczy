/*2351495 ������ ��ҵ��*/
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
		printf("��������[1900-2100]���¡��գ�\n");
		if (scanf("%d%d%d", &y, &m, &d) != 3) 
		{
			while (getchar() != '\n'); 
			continue;
		}
		if (y < 1900 || y > 2100) 
		{
			printf("��ݲ���ȷ������������\n");
			continue;
		}
		if (m < 1 || m > 12) 
		{
			printf("�·ݲ���ȷ������������\n");
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
			printf("�ղ���ȷ������������\n");
			continue;
		}
		w = zeller(y, m, d);
		switch (w) 
		{
		case 0:
			printf("������\n");
			break;
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		case 6:
			printf("������\n");
			break;
		}
		break;
	}
	return 0;
}