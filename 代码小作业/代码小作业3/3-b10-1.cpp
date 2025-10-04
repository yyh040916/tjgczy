/*2351495 ������ ��ҵ��*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int ans = 0;
	for (int i = 123; i <= 985; i++)
	{
		int a1 = i / 100, a2 = i / 10 % 10, a3 = i % 10;
		if (a1 == 0 || a2 == 0 || a3 == 0)
			continue;
		if (a1 == a2 || a2 == a3 || a1 == a3)
			continue;
		for (int j = i + 1; j <= 987; j++)
		{
			int b1 = j / 100, b2 = j / 10 % 10, b3 = j % 10;
			if (b1 == 0 || b2 == 0 || b3 == 0)
				continue;
			if (b1 == b2 || b2 == b3 || b1 == b3 ||
				a1 == b1 || a1 == b2 || a1 == b3 ||
				a2 == b1 || a2 == b2 || a2 == b3 ||
				a3 == b1 || a3 == b2 || a3 == b3)
				continue;
			for (int k = j + 1; k <= 987; k++)
			{
				int c1 = k / 100, c2 = k / 10 % 10, c3 = k % 10;
				if (c1 == 0 || c2 == 0 || c3 == 0)
					continue;
				if (c1 == c2 || c1 == c3 || c2 == c3 ||
					a1 == c1 || a1 == c2 || a1 == c3 ||
					a2 == c1 || a2 == c2 || a2 == c3 ||
					a3 == c1 || a3 == c2 || a3 == c3 ||
					b1 == c1 || b1 == c2 || b1 == c3 ||
					b2 == c1 || b2 == c2 || b2 == c3 ||
					b3 == c1 || b3 == c2 || b3 == c3) 
					continue;
				if (i + j + k == 1953)
				{
					ans++;
					cout << "No." << setw(3) << ans << " : " << i << "+" << j << "+" << k << "=1953" << endl;
				}
			}
		}
	}
	cout << "total=" << ans << endl;
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}