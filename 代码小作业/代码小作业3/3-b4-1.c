/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
const double PI = 3.14159;
int main()
{
	int a, b, c;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d", &a, &b, &c);
	double area = 0.5 * sin(c * PI / 180) * a * b;
	printf("三角形的面积为 : %.3f\n", (float)(area));
	return 0;
}
