/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
	double n;
	printf("请输入[0,100亿)之间的数字:\n");
	scanf("%lf", &n);
	printf("%-7s%s%d\n", "十亿位", ": ", (int)(n / 1000000000) % 10);
	printf("%-7s%s%d\n", "亿位", ": ", (int)(n / 100000000) % 10);
	printf("%-7s%s%d\n", "千万位", ": ", (int)(n / 10000000) % 10);
	printf("%-7s%s%d\n", "百万位", ": ", (int)(n / 1000000) % 10);
	printf("%-7s%s%d\n", "十万位", ": ", (int)(n / 100000) % 10);
	printf("%-7s%s%d\n", "万位", ": ", (int)(n / 10000) % 10);
	printf("%-7s%s%d\n", "千位", ": ", (int)(n / 1000) % 10);
	printf("%-7s%s%d\n", "百位", ": ", (int)(n / 100) % 10);
	printf("%-7s%s%d\n", "十位", ": ", (int)(n / 10) % 10);
	n /= 10;
	n -= floor(n);
	n *= 1000;
	n += 0.001;
	printf("%-7s%s%d\n", "圆", ": ", (int)(n / 100) % 10);
	printf("%-7s%s%d\n", "角", ": ", (int)(n / 10) % 10);
	printf("%-7s%s%d\n", "分", ": ", (int)(n / 1) % 10);
	return 0;
}
