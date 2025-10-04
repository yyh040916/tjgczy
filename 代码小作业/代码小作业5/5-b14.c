/*2351495 大数据 闫业豪*/
/*2353626 贺胡鸣 2451777 梁越涵 2453160 韦天翔 2353763 魏卓越 2452101 凌霄 2452514 李俊熙 2452020 王思锐 2453795 郑铭浩 2454075 张振洋 2454074 祁嘉倬 2451038 刘若愚*/
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
        printf("错误1\n");
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
                printf("错误2\n");
                return 0;
            }
        }
    }
    printf("正确\n");
    return 0;
}