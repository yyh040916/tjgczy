/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
    double n;
    printf("����������ֵ��\n");
    scanf("%lf", &n);
    int ans = 0, num50 = 0, num20 = 0, num10 = 0, num5 = 0, num1 = 0, num05 = 0, num01 = 0, num005 = 0, num002 = 0, num001 = 0;
    double n1 = floor(n); 
    double n2 = (n - floor(n)) * 100; 
    int a = (int)n1, b = (int)n2;
    num50 = a / 50;
    a %= 50;
    num20 = a / 20;
    a %= 20;
    num10 = a / 10;
    a %= 10;
    num5 = a / 5;
    a %= 5;
    num1 = a;

    num05 = b / 50;
    b %= 50;
    num01 = b / 10;
    b %= 10;
    num005 = b / 5;
    b %= 5;
    num002 = b / 2;
    b %= 2;
    num001 = b;
    ans = num50 + num20 + num10 + num5 + num1 + num05 + num01 + num005 + num002 + num001;
    printf("��%d�����㣬�������£�\n", ans);

    if (num50 > 0)
        printf("50Ԫ : %d��\n", num50);
    if (num20 > 0)
        printf("20Ԫ : %d��\n", num20);
    if (num10 > 0)
        printf("10Ԫ : %d��\n", num10);
    if (num5 > 0)
        printf("5Ԫ  : %d��\n", num5);
    if (num1 > 0) 
        printf("1Ԫ  : %d��\n", num1);
    if (num05 > 0) 
        printf("5��  : %d��\n", num05);
    if (num01 > 0) 
        printf("1��  : %d��\n", num01);
    if (num005 > 0) 
        printf("5��  : %d��\n", num005);
    if (num002 > 0) 
        printf("2��  : %d��\n", num002);
    if (num001 > 0)
        printf("1��  : %d��\n", num001);
    return 0;
}
