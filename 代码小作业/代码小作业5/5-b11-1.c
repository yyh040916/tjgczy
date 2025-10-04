/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
    double n;
    result[0] = '\0';
    while (1)
    {
        printf("请输入[0-100亿)之间的数字:\n");
        if (scanf("%lf", &n) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        if (n >= 0 && n < 10000000000)
            break;
    }
    printf("大写结果是:\n");
    if (fabs(n) < 0.000001)
    {
        daxie(0, 1);
        my_strcat(result, "圆整");
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
    
    //十亿-亿位
    if (n1 > 0 || n2 > 0)
    {
        if (n1 > 0)
        {
            daxie(n1,0);
            my_strcat(result, "拾");
        }
        daxie(n2, 0);
        my_strcat(result, "亿");
        if (n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 &&
            n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 &&
            n11 == 0 && n12 == 0)
        {
            my_strcat(result, "圆整");
            yuanzheng = 1;
        }
    }
    //千万-万位
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
            my_strcat(result, "仟");
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
            my_strcat(result, "佰");
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
            my_strcat(result, "拾");
            flag = 0;
        }
        if (n6 > 0)
        {
            daxie(n6,0);
        }
        my_strcat(result, "万");
        flag = 0;
        if (n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 &&
            n11 == 0 && n12 == 0)
        {
            my_strcat(result, "圆整");
            yuanzheng = 1;
        }
    }
    // 千-个位
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
            my_strcat(result, "仟");
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
            my_strcat(result, "佰");
            flag = 0;
        }
        if (n9 == 0 && (n7 > 0 || n8 > 0) && n10 > 0 && flag == 0) {
            daxie(0, 1);
        }
        else if (n9 > 0)
        {
            daxie(n9,0);
            my_strcat(result, "拾");
        }

        if (n10 > 0)
        {
            daxie(n10,0);
        }
    }
    if ((n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 ||
        n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) && yuanzheng == 0)
    {
        my_strcat(result, "圆");
        if (n11 == 0 && n12 == 0)
        {
            my_strcat(result, "整");
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
            my_strcat(result, "角");
        }
        if (n12 > 0)
        {
            daxie(n12,0);
            my_strcat(result, "分");
        }
        else if (n11 > 0)
        {
            my_strcat(result, "整");
        }
    }
    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}