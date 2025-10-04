/*2351495 大数据 闫业豪*/
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
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;
	unsigned int ans = binary_to_decimal(str);
	cout << ans << endl;
	return 0;
}