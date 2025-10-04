/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int is_leapyear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
int numdays(int year,int month,int day)
{
	int a[12] = { 31,28 + is_leapyear(year),31,30,31,30,31,31,30,31,30,31 };
	int sum = 0;
	if (day <= 0 || day > a[month - 1])
		return 0;
	for (int i = 0; i < month - 1; i++)
		sum += a[i];
	sum += day;
	return sum;
}
int main()
{
	int year, month, day;
	printf("�������꣬�£���\n");
	scanf("%d %d %d", &year, &month, &day);
	if (month > 12 || month < 1)
	{
		printf("�������-�·ݲ���ȷ\n");
		return  0;
	}
	int ans = numdays(year, month, day);
	if (ans == 0)
	{
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
		return 0;
	}
	printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, ans);
	return 0;
}