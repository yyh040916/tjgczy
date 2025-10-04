/*2351495 ������ ��ҵ��*/
/*2353626 �غ��� 2451777 ��Խ�� 2453160 Τ���� 2353763 κ׿Խ 2452101 ���� 2452514 ��� 2452020 ��˼�� 2453795 ֣���� 2454075 ������ 2454074 ���پ 2451038 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    char grid[10][26];
    int i, j, star_count = 0;
    int row = 0, col = 0;
    char c;
    for (i = 0; i < 10; i++) 
        for (j = 0; j < 26; j++) 
            grid[i][j] = '0';
    while (row < 10) 
    {
        c = getchar();
        if (c == '\n') 
        {
            row++;
            col = 0;
            continue;
        }
        if (c == ' ')
            continue;
        if (col < 26) 
        {
            grid[row][col] = c;
            if (c == '*')
                star_count++;
            col++;
        }
    }
    if (star_count != 50)
    {
        printf("����1\n");
        return 0;
    }
    char calculated_grid[10][26];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (grid[i][j] == '*') 
            {
                calculated_grid[i][j] = '*';
                continue;
            }
            int count = 0;
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    if (di == 0 && dj == 0)
                        continue;
                    int ni = i + di;
                    int nj = j + dj;
                    if (ni >= 0 && ni < 10 && nj >= 0 && nj < 26)
                    {
                        if (grid[ni][nj] == '*')
                            count++;
                    }
                }
            }
            calculated_grid[i][j] = '0' + count;
        }
    }
    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 26; j++) 
        {
            if (calculated_grid[i][j] != grid[i][j]) 
            {
                printf("����2\n");
                return 0;
            }
        }
    }
    printf("��ȷ\n");
    return 0;
}