/*2351495 大数据 闫业豪*/
#include <iostream>
using namespace std;
bool is_palindrome(const char* str)
{
	if (str == NULL)
		return true;
	const char* start = str;
	const char* end = str;
	while (*end != '\0')
		end++;
	if (end == start)
		return true;
	end--;
	while (start < end)
	{
		if (*start != *end)
			return false;
		start++;
		end--;
	}
	return true;
}
int main()
{
	char str[82];
	char* p;
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, sizeof(str), stdin);
	p = str;
	while (*p != '\0')
	{
		if (*p == '\n')
		{
			*p = '\0';
			break;
		}
		p++;
	}
	if (is_palindrome(str))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}