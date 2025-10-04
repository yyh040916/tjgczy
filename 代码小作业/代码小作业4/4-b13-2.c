/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int step;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        step++;
        printf("%5d: %2d# %c-->%c\n", step, 1, src, dst);
        return;
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        step++;
        printf("%5d: %2d# %c-->%c\n", step, n, src, dst);
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n = 0;
    int a;
    char src, tmp, dst;
    while (1)
    {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
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
        printf("��������ʼ��(A-C)\n");
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
        printf("������Ŀ����(A-C)\n");
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
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
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
    printf("�ƶ�����Ϊ:\n");
    hanoi(n, src, tmp, dst);
    return 0;
}
