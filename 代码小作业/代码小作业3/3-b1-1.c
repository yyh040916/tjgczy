/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const double PI = 3.14159;
int main()
{
	double r, h;
	printf("请输入半径和高度\n");
	scanf("%lf%lf", &r, &h);
	printf("%-11s: %.2lf\n", "圆周长", 2 * PI * r);
	printf("%-11s: %.2lf\n", "圆面积", PI * r * r);
	printf("%-11s: %.2lf\n", "圆球表面积", 4 * PI * r * r);
	printf("%-11s: %.2lf\n", "圆球体积", 4 * PI * r * r * r / 3);
	printf("%-11s: %.2lf\n", "圆柱体积", PI * r * r * h);
	return 0;
}
