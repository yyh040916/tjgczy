/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main()
{
	int year, month, day;
	printf("�������꣬�£���\n");
	scanf("%d %d %d", &year, &month, &day);
	bool is_leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (month > 12 || month < 1)
	{
		printf("�������-�·ݲ���ȷ\n");
		return  0;
	}
	else
	{
		int daynum = 0;
		if (month == 1)
			daynum = 31;
		else if (month == 2)
			daynum = is_leapyear == 1 ? 29 : 28;
		else if (month == 3)
			daynum = 31;
		else if (month == 4)
			daynum = 30;
		else if (month == 5)
			daynum = 31;
		else if (month == 6)
			daynum = 30;
		else if (month == 7)
			daynum = 31;
		else if (month == 8)
			daynum = 31;
		else if (month == 9)
			daynum = 30;
		else if (month == 10)
			daynum = 31;
		else if (month == 11)
			daynum = 30;
		else if (month == 12)
			daynum = 31;
		if (day<1 || day>daynum)
		{
			printf("�������-�����¹�ϵ�Ƿ�\n");
			return 0;
		}
		int ans = 0;
		if (month > 1)
			ans += 31;
		if (month > 2)
			ans += is_leapyear == 1 ? 29 : 28;
		if (month > 3)
			ans += 31;
		if (month > 4)
			ans += 30;
		if (month > 5)
			ans += 31;
		if (month > 6)
			ans += 30;
		if (month > 7)
			ans += 31;
		if (month > 8)
			ans += 31;
		if (month > 9)
			ans += 30;
		if (month > 10)
			ans += 31;
		if (month > 11)
			ans += 30;
		ans += day;
		printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, ans);
	}
	return 0;
}
