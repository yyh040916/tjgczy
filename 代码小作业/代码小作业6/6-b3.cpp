/*2351495 ������ ��ҵ��*/
#include <iostream>
using namespace std;
unsigned int binary_to_decimal(const char* str)
{
	if (str == NULL)
		return 0;
	const char* p = str;
	unsigned int ans = 0;
	while (*p != '\0')
	{
		if (*p == '0' || *p == '1')
			ans = ans * 2 + (*p - '0');
		p++;
	}
	return ans;
}
int main()
{
	char str[33];
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> str;
	unsigned int ans = binary_to_decimal(str);
	cout << ans << endl;
	return 0;
}