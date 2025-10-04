/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void my_strcat(char dest[], const char src[])
{
    int i = 0, j = 0;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}
void add_char(char dest[], char c)
{
    int i = 0;
    while (dest[i] != '\0')
        i++;
    dest[i] = c;
    dest[i + 1] = '\0';
}
void daxie(int num, int flag_of_zero)
{
    if (num == 0 && flag_of_zero)
    {
        add_char(result, chnstr[0]);
        add_char(result, chnstr[1]);
    }
    else if (num > 0 && num <= 9)
    {
        add_char(result, chnstr[num * 2]);
        add_char(result, chnstr[num * 2 + 1]);
    }
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
    double n;
    result[0] = '\0';
    while (1)
    {
        printf("������[0-100��)֮�������:\n");
        if (scanf("%lf", &n) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        if (n >= 0 && n < 10000000000)
            break;
    }
    printf("��д�����:\n");
    if (fabs(n) < 0.000001)
    {
        daxie(0, 1);
        my_strcat(result, "Բ��");
        printf("%s\n", result);
        return 0;
    }
    int n1 = (int)(n / 1000000000) % 10;
    int n2 = (int)(n / 100000000) % 10;
    int n3 = (int)(n / 10000000) % 10;
    int n4 = (int)(n / 1000000) % 10;
    int n5 = (int)(n / 100000) % 10;
    int n6 = (int)(n / 10000) % 10;
    int n7 = (int)(n / 1000) % 10;
    int n8 = (int)(n / 100) % 10;
    int n9 = (int)(n / 10) % 10;
    n /= 10;
    n -= floor(n);
    n *= 1000;
    n += 0.001;
    int n10 = (int)(n / 100) % 10;
    int n11 = (int)(n / 10) % 10;
    int n12 = (int)(n / 1) % 10;
    int flag = 0, yuanzheng = 0;
    
    //ʮ��-��λ
    if (n1 > 0 || n2 > 0)
    {
        if (n1 > 0)
        {
            daxie(n1,0);
            my_strcat(result, "ʰ");
        }
        daxie(n2, 0);
        my_strcat(result, "��");
        if (n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 &&
            n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 &&
            n11 == 0 && n12 == 0)
        {
            my_strcat(result, "Բ��");
            yuanzheng = 1;
        }
    }
    //ǧ��-��λ
    if (n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0)
    {
        if ((n1 > 0 || n2 > 0) && n3 == 0 && (n4 > 0 || n5 > 0 || n6 > 0))
        {
            daxie(0, 1);
            flag = 1;
        }
        if (n3 > 0)
        {
            daxie(n3,0);
            my_strcat(result, "Ǫ");
            flag = 0;
        }
        if (n4 == 0 && n3 > 0 && (n5 > 0 || n6 > 0))
        {
            daxie(0, 1);
            flag = 1;
        }
        else if (n4 > 0)
        {
            daxie(n4,0);
            my_strcat(result, "��");
            flag = 0;
        }
        if (n5 == 0 && (n3 > 0 || n4 > 0) && n6 > 0 && flag == 0)
        {
            daxie(0, 1);
            flag = 1;
        }
        else if (n5 > 0)
        {
            daxie(n5,0);
            my_strcat(result, "ʰ");
            flag = 0;
        }
        if (n6 > 0)
        {
            daxie(n6,0);
        }
        my_strcat(result, "��");
        flag = 0;
        if (n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 &&
            n11 == 0 && n12 == 0)
        {
            my_strcat(result, "Բ��");
            yuanzheng = 1;
        }
    }
    // ǧ-��λ
    if (n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0)
    {
        if ((n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) &&
            n7 == 0 && (n8 > 0 || n9 > 0 || n10 > 0))
        {
            daxie(0, 1);
            flag = 1;
        }
        if (n7 > 0)
        {
            daxie(n7,0);
            my_strcat(result, "Ǫ");
            flag = 0;
        }
        if (n8 == 0 && n7 > 0 && (n9 > 0 || n10 > 0))
        {
            daxie(0, 1);
            flag = 1;
        }
        else if (n8 > 0)
        {
            daxie(n8,0);
            my_strcat(result, "��");
            flag = 0;
        }
        if (n9 == 0 && (n7 > 0 || n8 > 0) && n10 > 0 && flag == 0) {
            daxie(0, 1);
        }
        else if (n9 > 0)
        {
            daxie(n9,0);
            my_strcat(result, "ʰ");
        }

        if (n10 > 0)
        {
            daxie(n10,0);
        }
    }
    if ((n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 ||
        n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) && yuanzheng == 0)
    {
        my_strcat(result, "Բ");
        if (n11 == 0 && n12 == 0)
        {
            my_strcat(result, "��");
        }
    }
    if (n11 > 0 || n12 > 0)
    {
        if (n11 == 0 && n12 > 0 &&
            (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 ||
                n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0))
        {
            daxie(0, 1);
        }
        else if (n11 > 0)
        {
            daxie(n11,0);
            my_strcat(result, "��");
        }
        if (n12 > 0)
        {
            daxie(n12,0);
            my_strcat(result, "��");
        }
        else if (n11 > 0)
        {
            my_strcat(result, "��");
        }
    }
    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}