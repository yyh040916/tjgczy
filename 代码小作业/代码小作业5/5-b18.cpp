/*2351495 大数据 闫业豪*/
#include<iostream>
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	cin.ignore(2048, '\n');
	bool vis = true;
	int totallength, uppercount, lowercount, digitcount, othercount;
	cin >> totallength >> uppercount >> lowercount >> digitcount >> othercount;
	cin.ignore(2048, '\n');
	if (cin.good() == 0 ||
		(totallength < 12 || totallength > 16) ||
		(uppercount < 2 || uppercount > 16) ||
		(lowercount < 2 || lowercount > 16) ||
		(digitcount < 2 || digitcount > 16) ||
		(othercount < 2 || othercount > 16) ||
		(uppercount + lowercount + digitcount + othercount > totallength))
	{
		vis = false;
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			char key[17] = { 0 };
            int check_upper = 0, check_lower = 0, check_digit = 0, check_other = 0;
            cin.getline(key, 17, '\n');
            int length = 0;
            while (key[length] != '\0')
                length++;
            if (length != totallength)
            {
                vis = false;
                break;
            }
            for (int j = 0; j < totallength; j++)
            {
                if (key[j] >= 'A' && key[j] <= 'Z')
                    check_upper++;
                else if (key[j] >= 'a' && key[j] <= 'z')
                    check_lower++;
                else if (key[j] >= '0' && key[j] <= '9')
                    check_digit++;
                else
                {
                    bool exist = false;
                    for (int k = 0; k < 15; k++)
                    {
                        if (key[j] == other[k])
                        {
                            exist = true;
                            break;
                        }
                    }
                    if (exist == false)
                    {
                        vis = false;
                        break;
                    }
                    else
                    {
                        check_other++;
                    }
                }

                if (vis == false)
                    break;
            }

            if (uppercount > check_upper || lowercount > check_lower ||
                digitcount > check_digit || othercount > check_other)
            {
                vis = false;
            }
            if (vis == false)
                break;
		}
	}
	if (vis)
		cout << "正确" << endl;
	else
		cout << "错误" << endl;
	return 0;
}