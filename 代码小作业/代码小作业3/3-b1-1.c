/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const double PI = 3.14159;
int main()
{
	double r, h;
	printf("������뾶�͸߶�\n");
	scanf("%lf%lf", &r, &h);
	printf("%-11s: %.2lf\n", "Բ�ܳ�", 2 * PI * r);
	printf("%-11s: %.2lf\n", "Բ���", PI * r * r);
	printf("%-11s: %.2lf\n", "Բ������", 4 * PI * r * r);
	printf("%-11s: %.2lf\n", "Բ�����", 4 * PI * r * r * r / 3);
	printf("%-11s: %.2lf\n", "Բ�����", PI * r * r * h);
	return 0;
}
