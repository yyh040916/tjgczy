/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &n);
	printf("%s : %d\n", "��λ", n / 10000 % 10);
	printf("%s : %d\n", "ǧλ", n / 1000 % 10);
	printf("%s : %d\n", "��λ", n / 100 % 10);
	printf("%s : %d\n", "ʮλ", n / 10 % 10);
	printf("%s : %d\n", "��λ", n / 1 % 10);
	return 0;
}
