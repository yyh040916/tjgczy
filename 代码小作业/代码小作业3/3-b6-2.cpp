/*2351495 ´óÊı¾İ ãÆÒµºÀ*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double n;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	cin >> n;
	if (n == 0) 
	{
		cout << "´óĞ´½á¹ûÊÇ:\nÁãÔ²Õû" << endl;
		return 0;
	}
	int n1 = int(n / 1000000000) % 10;
	int n2 = int(n / 100000000) % 10;
	int n3 = int(n / 10000000) % 10;
	int n4 = int(n / 1000000) % 10;
	int n5 = int(n / 100000) % 10;
	int n6 = int(n / 10000) % 10;
	int n7 = int(n / 1000) % 10;
	int n8 = int(n / 100) % 10;
	int n9 = int(n / 10) % 10;
	n /= 10;
	n -= floor(n);
	n *= 1000;
	n += 0.001;
	int n10 = int(n / 100) % 10;
	int n11 = int(n / 10) % 10;
	int n12 = int(n / 1) % 10;
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	cout << "´óĞ´½á¹ûÊÇ:" << endl;
	//Ê®ÒÚ
	if (n1 == 1)
		cout << "Ò¼Ê°";
	else if (n1 == 2)
		cout << "·¡Ê°";
	else if (n1 == 3)
		cout << "ÈşÊ°";
	else if (n1 == 4)
		cout << "ËÁÊ°";
	else if (n1 == 5)
		cout << "ÎéÊ°";
	else if (n1 == 6)
		cout << "Â½Ê°";
	else if (n1 == 7)
		cout << "ÆâÊ°";
	else if (n1 == 8)
		cout << "°ÆÊ°";
	else if (n1 == 9)
		cout << "¾ÁÊ°";
	//ÒÚ
	if (n2 == 0 && n1 != 0)
		cout << "ÒÚ";
	else if (n2 == 1)
		cout << "Ò¼ÒÚ";
	else if (n2 == 2)
		cout << "·¡ÒÚ";
	else if (n2 == 3)
		cout << "ÈşÒÚ";
	else if (n2 == 4)
		cout << "ËÁÒÚ";
	else if (n2 == 5)
		cout << "ÎéÒÚ";
	else if (n2 == 6)
		cout << "Â½ÒÚ";
	else if (n2 == 7)
		cout << "ÆâÒÚ";
	else if (n2 == 8)
		cout << "°ÆÒÚ";
	else if (n2 == 9)
		cout << "¾ÁÒÚ";
	if (flag3 == 0 && !n3 && !n4 && !n5 && !n6 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12 && (n1 || n2))
	{
		cout << "Ô²Õû";
		flag3 = 1;
	}
	//Ç§Íò
	if (n3 == 0)
	{
		if ((n4 || n5 || n6) && (n1 || n2))
		{
			cout << "Áã";
			flag1 = 1;
		}
	}
	else if (n3 == 1)
		cout << "Ò¼Çª";
	else if (n3 == 2)
		cout << "·¡Çª";
	else if (n3 == 3)
		cout << "ÈşÇª";
	else if (n3 == 4)
		cout << "ËÁÇª";
	else if (n3 == 5)
		cout << "ÎéÇª";
	else if (n3 == 6)
		cout << "Â½Çª";
	else if (n3 == 7)
		cout << "ÆâÇª";
	else if (n3 == 8)
		cout << "°ÆÇª";
	else if (n3 == 9)
		cout << "¾ÁÇª";
	//°ÙÍò
	if (n4 == 0)
	{
		if (!flag1 && ((n1 || n2) || n3) && (n5 || n6))
		{
			cout << "Áã";
			flag1 = 1;
		}
	}
	else if (n4 == 1)
		cout << "Ò¼°Û";
	else if (n4 == 2)
		cout << "·¡°Û";
	else if (n4 == 3)
		cout << "Èş°Û";
	else if (n4 == 4)
		cout << "ËÁ°Û";
	else if (n4 == 5)
		cout << "Îé°Û";
	else if (n4 == 6)
		cout << "Â½°Û";
	else if (n4 == 7)
		cout << "Æâ°Û";
	else if (n4 == 8)
		cout << "°Æ°Û";
	else if (n4 == 9)
		cout << "¾Á°Û";
	//Ê®Íò
	if (n5 == 0)
	{
		if ((!flag1 && ((n1 || n2) || n3 || n4) && (n6)) || (flag1 && n4 != 0 && n6 != 0))
		{
			cout << "Áã";
			flag1 = 1;
		}
	}
	else if (n5 == 1)
		cout << "Ò¼Ê°";
	else if (n5 == 2)
		cout << "·¡Ê°";
	else if (n5 == 3)
		cout << "ÈşÊ°";
	else if (n5 == 4)
		cout << "ËÁÊ°";
	else if (n5 == 5)
		cout << "ÎéÊ°";
	else if (n5 == 6)
		cout << "Â½Ê°";
	else if (n5 == 7)
		cout << "ÆâÊ°";
	else if (n5 == 8)
		cout << "°ÆÊ°";
	else if (n5 == 9)
		cout << "¾ÁÊ°";
	//Íò
	if (n6 == 0)
	{
		if (n3 || n4 || n5)
			cout << "Íò";
	}
	else if (n6 == 1)
		cout << "Ò¼Íò";
	else if (n6 == 2)
		cout << "·¡Íò";
	else if (n6 == 3)
		cout << "ÈşÍò";
	else if (n6 == 4)
		cout << "ËÁÍò";
	else if (n6 == 5)
		cout << "ÎéÍò";
	else if (n6 == 6)
		cout << "Â½Íò";
	else if (n6 == 7)
		cout << "ÆâÍò";
	else if (n6 == 8)
		cout << "°ÆÍò";
	else if (n6 == 9)
		cout << "¾ÁÍò";
	if (flag3 == 0 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12)
	{
		cout << "Ô²Õû";
		flag3 = 1;
	}
	//Ç§
	if (n7 == 0)
	{
		if (((n1 || n2) || (n3 || n4 || n5 || n6)) && (n8 || n9 || n10))
		{
			cout << "Áã";
			flag2 = 1;
		}
	}
	else if (n7 == 1)
		cout << "Ò¼Çª";
	else if (n7 == 2)
		cout << "·¡Çª";
	else if (n7 == 3)
		cout << "ÈşÇª";
	else if (n7 == 4)
		cout << "ËÁÇª";
	else if (n7 == 5)
		cout << "ÎéÇª";
	else if (n7 == 6)
		cout << "Â½Çª";
	else if (n7 == 7)
		cout << "ÆâÇª";
	else if (n7 == 8)
		cout << "°ÆÇª";
	else if (n7 == 9)
		cout << "¾ÁÇª";
	//°Ù
	if (n8 == 0)
	{
		if (!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7) && (n9 || n10))
		{
			cout << "Áã";
			flag2 = 1;
		}
	}
	else if (n8 == 1)
		cout << "Ò¼°Û";
	else if (n8 == 2)
		cout << "·¡°Û";
	else if (n8 == 3)
		cout << "Èş°Û";
	else if (n8 == 4)
		cout << "ËÁ°Û";
	else if (n8 == 5)
		cout << "Îé°Û";
	else if (n8 == 6)
		cout << "Â½°Û";
	else if (n8 == 7)
		cout << "Æâ°Û";
	else if (n8 == 8)
		cout << "°Æ°Û";
	else if (n8 == 9)
		cout << "¾Á°Û";
	//Ê®
	if (n9 == 0)
	{
		if ((!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7 || n8) && (n10)) || (flag2 && n8 != 0 && n10 != 0))
		{
			cout << "Áã";
			flag2 = 1;
		}
	}
	else if (n9 == 1)
		cout << "Ò¼Ê°";
	else if (n9 == 2)
		cout << "·¡Ê°";
	else if (n9 == 3)
		cout << "ÈşÊ°";
	else if (n9 == 4)
		cout << "ËÁÊ°";
	else if (n9 == 5)
		cout << "ÎéÊ°";
	else if (n9 == 6)
		cout << "Â½Ê°";
	else if (n9 == 7)
		cout << "ÆâÊ°";
	else if (n9 == 8)
		cout << "°ÆÊ°";
	else if (n9 == 9)
		cout << "¾ÁÊ°";
	//¸ö
	if (n10 == 0)
		cout << "";
	else if (n10 == 1)
		cout << "Ò¼";
	else if (n10 == 2)
		cout << "·¡";
	else if (n10 == 3)
		cout << "Èş";
	else if (n10 == 4)
		cout << "ËÁ";
	else if (n10 == 5)
		cout << "Îé";
	else if (n10 == 6)
		cout << "Â½";
	else if (n10 == 7)
		cout << "Æâ";
	else if (n10 == 8)
		cout << "°Æ";
	else if (n10 == 9)
		cout << "¾Á";

	if (flag3 == 0 && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10))
	{
		cout << "Ô²";
		if (flag3 == 0 && !n11 && !n12)
		{
			cout << "Õû";
			flag3 = 1;
		}
	}
	if (flag3 == 1)
	{
		cout << endl;
		return 0;
	}
	if (n11 == 0)
	{
		if (n12 && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10))
		{
			cout << "Áã";
		}
	}
	else if (n11 == 1)
		cout << "Ò¼½Ç";
	else if (n11 == 2)
		cout << "·¡½Ç";
	else if (n11 == 3)
		cout << "Èş½Ç";
	else if (n11 == 4)
		cout << "ËÁ½Ç";
	else if (n11 == 5)
		cout << "Îé½Ç";
	else if (n11 == 6)
		cout << "Â½½Ç";
	else if (n11 == 7)
		cout << "Æâ½Ç";
	else if (n11 == 8)
		cout << "°Æ½Ç";
	else if (n11 == 9)
		cout << "¾Á½Ç";

	if (n12 == 0)
		cout << "Õû";
	else if (n12 == 1)
		cout << "Ò¼·Ö";
	else if (n12 == 2)
		cout << "·¡·Ö";
	else if (n12 == 3)
		cout << "Èş·Ö";
	else if (n12 == 4)
		cout << "ËÁ·Ö";
	else if (n12 == 5)
		cout << "Îé·Ö";
	else if (n12 == 6)
		cout << "Â½·Ö";
	else if (n12 == 7)
		cout << "Æâ·Ö";
	else if (n12 == 8)
		cout << "°Æ·Ö";
	else if (n12 == 9)
		cout << "¾Á·Ö";
	cout << endl;
	return 0;
}
