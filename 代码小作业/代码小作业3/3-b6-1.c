/*2351495 ´óÊý¾Ý ãÆÒµºÀ*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int main()
{
	double n;
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	scanf("%lf", &n);
	if (n == 0)
	{
		printf("´óÐ´½á¹ûÊÇ:\nÁãÔ²Õû\n");
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
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	printf("´óÐ´½á¹ûÊÇ:\n");
	//Ê®ÒÚ
	if (n1 == 1)
		printf("Ò¼Ê°");
	else if (n1 == 2)
		printf("·¡Ê°");
	else if (n1 == 3)
		printf("ÈþÊ°");
	else if (n1 == 4)
		printf("ËÁÊ°");
	else if (n1 == 5)
		printf("ÎéÊ°");
	else if (n1 == 6)
		printf("Â½Ê°");
	else if (n1 == 7)
		printf("ÆâÊ°");
	else if (n1 == 8)
		printf("°ÆÊ°");
	else if (n1 == 9)
		printf("¾ÁÊ°");
	//ÒÚ
	if (n2 == 0 && n1 != 0)
		printf("ÒÚ");
	else if (n2 == 1)
		printf("Ò¼ÒÚ");
	else if (n2 == 2)
		printf("·¡ÒÚ");
	else if (n2 == 3)
		printf("ÈþÒÚ");
	else if (n2 == 4)
		printf("ËÁÒÚ");
	else if (n2 == 5)
		printf("ÎéÒÚ");
	else if (n2 == 6)
		printf("Â½ÒÚ");
	else if (n2 == 7)
		printf("ÆâÒÚ");
	else if (n2 == 8)
		printf("°ÆÒÚ");
	else if (n2 == 9)
		printf("¾ÁÒÚ");
	if (flag3 == 0 && !n3 && !n4 && !n5 && !n6 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12 && (n1 || n2))
	{
		printf("Ô²Õû");
		flag3 = 1;
	}
	//Ç§Íò
	if (n3 == 0)
	{
		if ((n4 || n5 || n6) && (n1 || n2))
		{
			printf("Áã");
			flag1 = 1;
		}
	}
	else if (n3 == 1)
		printf("Ò¼Çª");
	else if (n3 == 2)
		printf("·¡Çª");
	else if (n3 == 3)
		printf("ÈþÇª");
	else if (n3 == 4)
		printf("ËÁÇª");
	else if (n3 == 5)
		printf("ÎéÇª");
	else if (n3 == 6)
		printf("Â½Çª");
	else if (n3 == 7)
		printf("ÆâÇª");
	else if (n3 == 8)
		printf("°ÆÇª");
	else if (n3 == 9)
		printf("¾ÁÇª");
	//°ÙÍò
	if (n4 == 0)
	{
		if (!flag1 && ((n1 || n2) || n3) && (n5 || n6))
		{
			printf("Áã");
			flag1 = 1;
		}
	}
	else if (n4 == 1)
		printf("Ò¼°Û");
	else if (n4 == 2)
		printf("·¡°Û");
	else if (n4 == 3)
		printf("Èþ°Û");
	else if (n4 == 4)
		printf("ËÁ°Û");
	else if (n4 == 5)
		printf("Îé°Û");
	else if (n4 == 6)
		printf("Â½°Û");
	else if (n4 == 7)
		printf("Æâ°Û");
	else if (n4 == 8)
		printf("°Æ°Û");
	else if (n4 == 9)
		printf("¾Á°Û");
	//Ê®Íò
	if (n5 == 0)
	{
		if ((!flag1 && ((n1 || n2) || n3 || n4) && (n6)) || (flag1 && n4 != 0 && n6 != 0))
		{
			printf("Áã");
			flag1 = 1;
		}
	}
	else if (n5 == 1)
		printf("Ò¼Ê°");
	else if (n5 == 2)
		printf("·¡Ê°");
	else if (n5 == 3)
		printf("ÈþÊ°");
	else if (n5 == 4)
		printf("ËÁÊ°");
	else if (n5 == 5)
		printf("ÎéÊ°");
	else if (n5 == 6)
		printf("Â½Ê°");
	else if (n5 == 7)
		printf("ÆâÊ°");
	else if (n5 == 8)
		printf("°ÆÊ°");
	else if (n5 == 9)
		printf("¾ÁÊ°");
	//Íò
	if (n6 == 0)
	{
		if (n3 || n4 || n5)
			printf("Íò");
	}
	else if (n6 == 1)
		printf("Ò¼Íò");
	else if (n6 == 2)
		printf("·¡Íò");
	else if (n6 == 3)
		printf("ÈþÍò");
	else if (n6 == 4)
		printf("ËÁÍò");
	else if (n6 == 5)
		printf("ÎéÍò");
	else if (n6 == 6)
		printf("Â½Íò");
	else if (n6 == 7)
		printf("ÆâÍò");
	else if (n6 == 8)
		printf("°ÆÍò");
	else if (n6 == 9)
		printf("¾ÁÍò");
	if (flag3 == 0 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12)
	{
		printf("Ô²Õû");
		flag3 = 1;
	}
	//Ç§
	if (n7 == 0)
	{
		if (((n1 || n2) || (n3 || n4 || n5 || n6)) && (n8 || n9 || n10))
		{
			printf("Áã");
			flag2 = 1;
		}
	}
	else if (n7 == 1)
		printf("Ò¼Çª");
	else if (n7 == 2)
		printf("·¡Çª");
	else if (n7 == 3)
		printf("ÈþÇª");
	else if (n7 == 4)
		printf("ËÁÇª");
	else if (n7 == 5)
		printf("ÎéÇª");
	else if (n7 == 6)
		printf("Â½Çª");
	else if (n7 == 7)
		printf("ÆâÇª");
	else if (n7 == 8)
		printf("°ÆÇª");
	else if (n7 == 9)
		printf("¾ÁÇª");
	//°Ù
	if (n8 == 0)
	{
		if (!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7) && (n9 || n10))
		{
			printf("Áã");
			flag2 = 1;
		}
	}
	else if (n8 == 1)
		printf("Ò¼°Û");
	else if (n8 == 2)
		printf("·¡°Û");
	else if (n8 == 3)
		printf("Èþ°Û");
	else if (n8 == 4)
		printf("ËÁ°Û");
	else if (n8 == 5)
		printf("Îé°Û");
	else if (n8 == 6)
		printf("Â½°Û");
	else if (n8 == 7)
		printf("Æâ°Û");
	else if (n8 == 8)
		printf("°Æ°Û");
	else if (n8 == 9)
		printf("¾Á°Û");
	//Ê®
	if (n9 == 0)
	{
		if ((!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7 || n8) && (n10)) || (flag2 && n8 != 0 && n10 != 0))
		{
			printf("Áã");
			flag2 = 1;
		}
	}
	else if (n9 == 1)
		printf("Ò¼Ê°");
	else if (n9 == 2)
		printf("·¡Ê°");
	else if (n9 == 3)
		printf("ÈþÊ°");
	else if (n9 == 4)
		printf("ËÁÊ°");
	else if (n9 == 5)
		printf("ÎéÊ°");
	else if (n9 == 6)
		printf("Â½Ê°");
	else if (n9 == 7)
		printf("ÆâÊ°");
	else if (n9 == 8)
		printf("°ÆÊ°");
	else if (n9 == 9)
		printf("¾ÁÊ°");
	//¸ö
	if (n10 == 0)
		printf("");
	else if (n10 == 1)
		printf("Ò¼");
	else if (n10 == 2)
		printf("·¡");
	else if (n10 == 3)
		printf("Èþ");
	else if (n10 == 4)
		printf("ËÁ");
	else if (n10 == 5)
		printf("Îé");
	else if (n10 == 6)
		printf("Â½");
	else if (n10 == 7)
		printf("Æâ");
	else if (n10 == 8)
		printf("°Æ");
	else if (n10 == 9)
		printf("¾Á");

	if (flag3 == 0 && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10))
	{
		printf("Ô²");
		if (flag3 == 0 && !n11 && !n12)
		{
			printf("Õû");
			flag3 = 1;
		}
	}
	if (flag3 == 1)
	{
		printf("\n");
		return 0;
	}
	if (n11 == 0)
	{
		if (n12 && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10))
		{
			printf("Áã");
		}
	}
	else if (n11 == 1)
		printf("Ò¼½Ç");
	else if (n11 == 2)
		printf("·¡½Ç");
	else if (n11 == 3)
		printf("Èþ½Ç");
	else if (n11 == 4)
		printf("ËÁ½Ç");
	else if (n11 == 5)
		printf("Îé½Ç");
	else if (n11 == 6)
		printf("Â½½Ç");
	else if (n11 == 7)
		printf("Æâ½Ç");
	else if (n11 == 8)
		printf("°Æ½Ç");
	else if (n11 == 9)
		printf("¾Á½Ç");

	if (n12 == 0)
		printf("Õû");
	else if (n12 == 1)
		printf("Ò¼·Ö");
	else if (n12 == 2)
		printf("·¡·Ö");
	else if (n12 == 3)
		printf("Èþ·Ö");
	else if (n12 == 4)
		printf("ËÁ·Ö");
	else if (n12 == 5)
		printf("Îé·Ö");
	else if (n12 == 6)
		printf("Â½·Ö");
	else if (n12 == 7)
		printf("Æâ·Ö");
	else if (n12 == 8)
		printf("°Æ·Ö");
	else if (n12 == 9)
		printf("¾Á·Ö");

	printf("\n");
	return 0;
}
