/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	double n;
	printf("������[0,100��)֮�������:\n");
	scanf("%lf", &n);
	printf("%-7s%s%d\n", "ʮ��λ", ": ", (int)(n / 1000000000) % 10);
	printf("%-7s%s%d\n", "��λ", ": ", (int)(n / 100000000) % 10);
	printf("%-7s%s%d\n", "ǧ��λ", ": ", (int)(n / 10000000) % 10);
	printf("%-7s%s%d\n", "����λ", ": ", (int)(n / 1000000) % 10);
	printf("%-7s%s%d\n", "ʮ��λ", ": ", (int)(n / 100000) % 10);
	printf("%-7s%s%d\n", "��λ", ": ", (int)(n / 10000) % 10);
	printf("%-7s%s%d\n", "ǧλ", ": ", (int)(n / 1000) % 10);
	printf("%-7s%s%d\n", "��λ", ": ", (int)(n / 100) % 10);
	printf("%-7s%s%d\n", "ʮλ", ": ", (int)(n / 10) % 10);
	n /= 10;
	n -= floor(n);
	n *= 1000;
	n += 0.001;
	printf("%-7s%s%d\n", "Բ", ": ", (int)(n / 100) % 10);
	printf("%-7s%s%d\n", "��", ": ", (int)(n / 10) % 10);
	printf("%-7s%s%d\n", "��", ": ", (int)(n / 1) % 10);
	return 0;
}
