/*2351495 ������ ��ҵ��*/
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	cin.getline(str, 256);
	p = str;
	pnum = a;
	pa = a;
	is_num = false;
	while (*p != '\0' && (pnum - pa) < N)
	{
		if (*p >= '0' && *p <= '9')
		{
			if (!is_num)
			{
				*pnum = 0;
				is_num = true;
			}
			*pnum = *pnum * 10 + (*p - '0');
		}
		else
		{
			if (is_num)
			{
				pnum++;
				is_num = false;
			}
		}
		p++;
	}
	if (is_num)
		pnum++;
	int count = pnum - a;
	cout << "����" << count << "������" << endl;
	if (count > 0)
	{
		pa = a;
		while (pa < pnum)
		{
			cout << *pa;
			pa++;
			if (pa < pnum)
				cout << ' ';
		}
		cout << endl;
	}
	return 0;
}