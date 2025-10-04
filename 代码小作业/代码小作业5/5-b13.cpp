/*2351495 大数据 闫业豪*/
#include<iostream>
#include<ctime>
using namespace std;
int main()
{
	srand((unsigned int)(time(0)));
	char grid[10][26];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 26; j++)
			grid[i][j] = '0';
	int minesplaced = 0;
	while (minesplaced < 50)
	{
		int row = rand() % 10;
		int col = rand() % 25;
		if (grid[row][col] != '*')
		{
			grid[row][col] = '*';
			minesplaced++;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (grid[i][j] == '*')
				continue;
			int count = 0;
			for (int di = -1; di <= 1; di++)
			{
				for (int dj = -1; dj <= 1; dj++)
				{
					if (di == 0 && dj == 0)
						continue;
					int ni = i + di, nj = j + dj;
					if (ni >= 0 && nj >= 0 && ni < 10 && nj < 26)
					{
						if (grid[ni][nj] == '*')
							count++;
					}
				}
			}
			grid[i][j] = '0' + count;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}