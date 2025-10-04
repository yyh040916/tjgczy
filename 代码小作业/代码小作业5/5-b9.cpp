/*2351495 大数据 闫业豪*/
#include<iostream>
#include<limits>
using namespace std;
const int length = 9;
void input(int board[][length])
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < length;)
	{
		for (int j = 0; j < length;)
		{
			int num;
			if (!(cin >> num))
			{
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				continue;
			}
			if (num < 1 || num>9)
			{
				cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
				continue;
			}
			board[i][j] = num;
			j++;
		}
		i++;
	}
}
bool is_shudu(int board[][length])
{
	//行
	for (int i = 0; i < length; i++)
	{
		bool check1[length + 1] = { false };
		for (int j = 0; j < length; j++)
		{
			int num = board[i][j];
			if (check1[num])
				return false;
			check1[num] = true;
		}
	}
	//列
	for (int j = 0; j < length; j++)
	{
		bool check2[length + 1] = { false };
		for (int i = 0; i < length; i++)
		{
			int num = board[i][j];
			if (check2[num])
				return false;
			check2[num] = true;
		}
	}
	//小九宫格
	for (int boxi = 0; boxi < 3; boxi++)
	{
		for (int boxj = 0; boxj < 3; boxj++)
		{
			bool check3[length+1] = { false };
			for (int i = boxi * 3; i < (boxi + 1) * 3; i++)
			{
				for (int j = boxj * 3; j < (boxj + 1) * 3; j++)
				{
					int num = board[i][j];
					if (check3[num])
						return false;
					check3[num] = true;
				}
			}
		}
	}
	return true;
}
int main()
{
	int board[length][length];
	input(board);
	bool k = is_shudu(board);
	cout << (k ? "是数独的解" : "不是数独的解") << endl;
	return 0;
}