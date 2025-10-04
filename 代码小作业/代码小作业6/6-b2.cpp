/*2351495 ������ ��ҵ��*/
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
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
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