/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
const double PI = 3.14159;
int main()
{
	int a, b, c;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %d", &a, &b, &c);
	double area = 0.5 * sin(c * PI / 180) * a * b;
	printf("�����ε����Ϊ : %.3f\n", (float)(area));
	return 0;
}
