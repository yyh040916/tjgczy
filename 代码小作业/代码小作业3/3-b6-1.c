/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int main()
{
	double n;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &n);
	if (n == 0)
	{
		printf("��д�����:\n��Բ��\n");
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
	printf("��д�����:\n");
	//ʮ��
	if (n1 == 1)
		printf("Ҽʰ");
	else if (n1 == 2)
		printf("��ʰ");
	else if (n1 == 3)
		printf("��ʰ");
	else if (n1 == 4)
		printf("��ʰ");
	else if (n1 == 5)
		printf("��ʰ");
	else if (n1 == 6)
		printf("½ʰ");
	else if (n1 == 7)
		printf("��ʰ");
	else if (n1 == 8)
		printf("��ʰ");
	else if (n1 == 9)
		printf("��ʰ");
	//��
	if (n2 == 0 && n1 != 0)
		printf("��");
	else if (n2 == 1)
		printf("Ҽ��");
	else if (n2 == 2)
		printf("����");
	else if (n2 == 3)
		printf("����");
	else if (n2 == 4)
		printf("����");
	else if (n2 == 5)
		printf("����");
	else if (n2 == 6)
		printf("½��");
	else if (n2 == 7)
		printf("����");
	else if (n2 == 8)
		printf("����");
	else if (n2 == 9)
		printf("����");
	if (flag3 == 0 && !n3 && !n4 && !n5 && !n6 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12 && (n1 || n2))
	{
		printf("Բ��");
		flag3 = 1;
	}
	//ǧ��
	if (n3 == 0)
	{
		if ((n4 || n5 || n6) && (n1 || n2))
		{
			printf("��");
			flag1 = 1;
		}
	}
	else if (n3 == 1)
		printf("ҼǪ");
	else if (n3 == 2)
		printf("��Ǫ");
	else if (n3 == 3)
		printf("��Ǫ");
	else if (n3 == 4)
		printf("��Ǫ");
	else if (n3 == 5)
		printf("��Ǫ");
	else if (n3 == 6)
		printf("½Ǫ");
	else if (n3 == 7)
		printf("��Ǫ");
	else if (n3 == 8)
		printf("��Ǫ");
	else if (n3 == 9)
		printf("��Ǫ");
	//����
	if (n4 == 0)
	{
		if (!flag1 && ((n1 || n2) || n3) && (n5 || n6))
		{
			printf("��");
			flag1 = 1;
		}
	}
	else if (n4 == 1)
		printf("Ҽ��");
	else if (n4 == 2)
		printf("����");
	else if (n4 == 3)
		printf("����");
	else if (n4 == 4)
		printf("����");
	else if (n4 == 5)
		printf("���");
	else if (n4 == 6)
		printf("½��");
	else if (n4 == 7)
		printf("���");
	else if (n4 == 8)
		printf("�ư�");
	else if (n4 == 9)
		printf("����");
	//ʮ��
	if (n5 == 0)
	{
		if ((!flag1 && ((n1 || n2) || n3 || n4) && (n6)) || (flag1 && n4 != 0 && n6 != 0))
		{
			printf("��");
			flag1 = 1;
		}
	}
	else if (n5 == 1)
		printf("Ҽʰ");
	else if (n5 == 2)
		printf("��ʰ");
	else if (n5 == 3)
		printf("��ʰ");
	else if (n5 == 4)
		printf("��ʰ");
	else if (n5 == 5)
		printf("��ʰ");
	else if (n5 == 6)
		printf("½ʰ");
	else if (n5 == 7)
		printf("��ʰ");
	else if (n5 == 8)
		printf("��ʰ");
	else if (n5 == 9)
		printf("��ʰ");
	//��
	if (n6 == 0)
	{
		if (n3 || n4 || n5)
			printf("��");
	}
	else if (n6 == 1)
		printf("Ҽ��");
	else if (n6 == 2)
		printf("����");
	else if (n6 == 3)
		printf("����");
	else if (n6 == 4)
		printf("����");
	else if (n6 == 5)
		printf("����");
	else if (n6 == 6)
		printf("½��");
	else if (n6 == 7)
		printf("����");
	else if (n6 == 8)
		printf("����");
	else if (n6 == 9)
		printf("����");
	if (flag3 == 0 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12)
	{
		printf("Բ��");
		flag3 = 1;
	}
	//ǧ
	if (n7 == 0)
	{
		if (((n1 || n2) || (n3 || n4 || n5 || n6)) && (n8 || n9 || n10))
		{
			printf("��");
			flag2 = 1;
		}
	}
	else if (n7 == 1)
		printf("ҼǪ");
	else if (n7 == 2)
		printf("��Ǫ");
	else if (n7 == 3)
		printf("��Ǫ");
	else if (n7 == 4)
		printf("��Ǫ");
	else if (n7 == 5)
		printf("��Ǫ");
	else if (n7 == 6)
		printf("½Ǫ");
	else if (n7 == 7)
		printf("��Ǫ");
	else if (n7 == 8)
		printf("��Ǫ");
	else if (n7 == 9)
		printf("��Ǫ");
	//��
	if (n8 == 0)
	{
		if (!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7) && (n9 || n10))
		{
			printf("��");
			flag2 = 1;
		}
	}
	else if (n8 == 1)
		printf("Ҽ��");
	else if (n8 == 2)
		printf("����");
	else if (n8 == 3)
		printf("����");
	else if (n8 == 4)
		printf("����");
	else if (n8 == 5)
		printf("���");
	else if (n8 == 6)
		printf("½��");
	else if (n8 == 7)
		printf("���");
	else if (n8 == 8)
		printf("�ư�");
	else if (n8 == 9)
		printf("����");
	//ʮ
	if (n9 == 0)
	{
		if ((!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7 || n8) && (n10)) || (flag2 && n8 != 0 && n10 != 0))
		{
			printf("��");
			flag2 = 1;
		}
	}
	else if (n9 == 1)
		printf("Ҽʰ");
	else if (n9 == 2)
		printf("��ʰ");
	else if (n9 == 3)
		printf("��ʰ");
	else if (n9 == 4)
		printf("��ʰ");
	else if (n9 == 5)
		printf("��ʰ");
	else if (n9 == 6)
		printf("½ʰ");
	else if (n9 == 7)
		printf("��ʰ");
	else if (n9 == 8)
		printf("��ʰ");
	else if (n9 == 9)
		printf("��ʰ");
	//��
	if (n10 == 0)
		printf("");
	else if (n10 == 1)
		printf("Ҽ");
	else if (n10 == 2)
		printf("��");
	else if (n10 == 3)
		printf("��");
	else if (n10 == 4)
		printf("��");
	else if (n10 == 5)
		printf("��");
	else if (n10 == 6)
		printf("½");
	else if (n10 == 7)
		printf("��");
	else if (n10 == 8)
		printf("��");
	else if (n10 == 9)
		printf("��");

	if (flag3 == 0 && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10))
	{
		printf("Բ");
		if (flag3 == 0 && !n11 && !n12)
		{
			printf("��");
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
			printf("��");
		}
	}
	else if (n11 == 1)
		printf("Ҽ��");
	else if (n11 == 2)
		printf("����");
	else if (n11 == 3)
		printf("����");
	else if (n11 == 4)
		printf("����");
	else if (n11 == 5)
		printf("���");
	else if (n11 == 6)
		printf("½��");
	else if (n11 == 7)
		printf("���");
	else if (n11 == 8)
		printf("�ƽ�");
	else if (n11 == 9)
		printf("����");

	if (n12 == 0)
		printf("��");
	else if (n12 == 1)
		printf("Ҽ��");
	else if (n12 == 2)
		printf("����");
	else if (n12 == 3)
		printf("����");
	else if (n12 == 4)
		printf("����");
	else if (n12 == 5)
		printf("���");
	else if (n12 == 6)
		printf("½��");
	else if (n12 == 7)
		printf("���");
	else if (n12 == 8)
		printf("�Ʒ�");
	else if (n12 == 9)
		printf("����");

	printf("\n");
	return 0;
}
