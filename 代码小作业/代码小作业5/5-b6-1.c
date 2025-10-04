/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };
int topA = 0, topB = 0, topC = 0;
int num = 1;
void init(int n, char src)
{
    topA = topB = topC = 0;
    for (int i = n; i >= 1; i--)
    {
        if (src == 'A')
            stackA[topA++] = i;
        else if (src == 'B')
            stackB[topB++] = i;
        else
            stackC[topC++] = i;
    }
}
void show(int n, int stackA[], int stackB[], int stackC[])
{
    printf(" A:");
    for (int i = 0; i < topA; i++)
        printf("%2d", stackA[i]);
    for (int i = 1; i < 21 - topA * 2; i++)
        printf(" ");
    printf("B:");
    for (int i = 0; i < topB; i++) 
        printf("%2d", stackB[i]);
    for (int i = 1; i < 21 - topB * 2; i++) 
        printf(" ");
    printf("C:");
    for (int i = 0; i < topC; i++) 
        printf("%2d", stackC[i]);
    printf("\n");
}
void move(char src, char dst)
{
    int disk;
    //out
    if (src == 'A')
        disk = stackA[--topA];
    else if (src == 'B')
        disk = stackB[--topB];
    else
        disk = stackC[--topC];
    //in
    if (dst == 'A')
        stackA[topA++] = disk;
    else if (dst == 'B')
        stackB[topB++] = disk;
    else
        stackC[topC++] = disk;
}
void hanoi(int n, char src, char tmp, char dst) {
    if (n == 1) {
        printf("第%4d 步(%2d): %c-->%c", num++, n, src, dst);
        move(src, dst);
        show(n, stackA, stackB, stackC);
    }
    else {
        hanoi(n - 1, src, dst, tmp);
        printf("第%4d 步(%2d): %c-->%c", num++, n, src, dst);
        move(src, dst);
        show(n, stackA, stackB, stackC);
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
    int n = 0;
    int a;
    char src, tmp, dst;
    while (1)
    {
        printf("请输入汉诺塔的层数(1-10)\n");
        if (scanf("%d", &n) != 1)
        {
            while ((a = getchar()) != EOF && a != '\n');
            continue;
        }
        if (n < 1 || n > 16)
        {
            while ((a = getchar()) != EOF && a != '\n');
            continue;
        }
        while ((a = getchar()) != EOF && a != '\n');
        break;
    }

    while (1)
    {
        printf("请输入起始柱(A-C)\n");
        if (scanf("%c", &src) != 1)
        {
            while ((a = getchar()) != EOF && a != '\n');
            continue;
        }
        if (src >= 'a' && src <= 'c')
        {
            src -= 32;
        }
        if (src < 'A' || src > 'C')
        {
            while ((a = getchar()) != EOF && a != '\n');
            continue;
        }
        while ((a = getchar()) != EOF && a != '\n');
        break;
    }

    while (1)
    {
        printf("请输入目标柱(A-C)\n");
        if (scanf("%c", &dst) != 1)
        {
            while ((a = getchar()) != EOF && a != '\n');
            continue;
        }
        if (dst >= 'a' && dst <= 'c')
        {
            dst -= 32;
        }
        if (dst < 'A' || dst > 'C')
        {
            while ((a = getchar()) != EOF && a != '\n');
            continue;
        }
        if (dst == src)
        {
            printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
            while ((a = getchar()) != EOF && a != '\n');
            continue;
        }
        while ((a = getchar()) != EOF && a != '\n');
        break;
    }
    tmp = 'A';
    if (src == 'A' && dst == 'B')
        tmp = 'C';
    else if (src == 'A' && dst == 'C')
        tmp = 'B';
    else if (src == 'B' && dst == 'A')
        tmp = 'C';
    else if (src == 'B' && dst == 'C')
        tmp = 'A';
    else if (src == 'C' && dst == 'A')
        tmp = 'B';
    else if (src == 'C' && dst == 'B')
        tmp = 'A';
    init(n, src);
    printf("初始:               ");
    show(n, stackA, stackB, stackC);
    hanoi(n, src, tmp, dst);
    return 0;
}