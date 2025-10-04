/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &n);
	printf("%s : %d\n", "万位", n / 10000 % 10);
	printf("%s : %d\n", "千位", n / 1000 % 10);
	printf("%s : %d\n", "百位", n / 100 % 10);
	printf("%s : %d\n", "十位", n / 10 % 10);
	printf("%s : %d\n", "个位", n / 1 % 10);
	return 0;
}
