/*2351495 大数据 闫业豪*/
#include<iostream>
#include<iomanip>
using namespace std;
int stacks[3][10] = { 0 };
int tops[3] = { 0 };
int num = 1;
void init(int n, char src)
{
    tops[0] = tops[1] = tops[2] = 0;
    int srcIndex = src - 'A';
    for (int i = n; i >= 1; i--)
    {
        stacks[srcIndex][tops[srcIndex]++] = i;
    }
}
void show(int n)
{
    cout << " " << "A:";
    for (int i = 0; i < tops[0]; i++)
        cout << setw(2) << stacks[0][i];
    cout << setw(21- tops[0]*2) << " ";
    cout << "B:";
    for (int i = 0; i < tops[1]; i++)
        cout << setw(2) << stacks[1][i];
    cout << setw(21- tops[1]*2) << " ";
    cout  << "C:";
    for (int i = 0; i < tops[2]; i++)
        cout << setw(2) << stacks[2][i];
    cout << endl;
}
void move(char src, char dst)
{
    int srcIndex = src - 'A';
    int dstIndex = dst - 'A';
    int disk = stacks[srcIndex][--tops[srcIndex]];
    stacks[dstIndex][tops[dstIndex]++] = disk;
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1)
    {
        cout << "第" << setw(4) << num++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        move(src, dst);
        show(n);
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << num++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        move(src, dst);
        show(n);
        hanoi(n - 1, tmp, src, dst);
    }
}
int main()
{
	int n = 0;
	char src, tmp, dst;
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        if (!(cin >> n))
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        if (n < 1 || n>16)
        {
            continue;
        }
        cin.clear();
        cin.ignore(2048, '\n');
        break;
    }
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        if (!(cin >> src))
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        if (src >= 'a' && src <= 'c')
        {
            src -= 32;
        }
        if (src < 'A' || src>'C')
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        if (!(cin >> dst))
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        if (dst >= 'a' && dst <= 'c')
        {
            dst -= 32;
        }
        if (dst < 'A' || dst>'C')
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        if (dst == src)
        {
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
    tmp = 'A';
    if (src == 'A' && dst == 'B')
        tmp = 'C';
    else if (src == 'A' && dst == 'C')
        tmp = 'B';
    else if (src == 'B' && dst == 'A')
        tmp = 'C';
    else if (src == 'B' && dst == 'C')
        tmp = 'A';
    else if (src == 'C' && dst == 'A')
        tmp = 'B';
    else if (src == 'C' && dst == 'B')
        tmp = 'A';
    init(n, src);
    cout << "初始:               ";
    show(n);
    hanoi(n, src, tmp, dst);
	return 0;
}