/*2351495 ������ ��ҵ��*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "5-b7.h"
using namespace std;
int stackA[10] = { 0 }, stackB[10] = { 0 }, stackC[10] = { 0 };
int topA = 0, topB = 0, topC = 0;
int num = 1;
void init(int n, char src)
{
    topA = topB = topC = 0;
    for (int i = n; i >= 1; i--)
    {
        if (src == 'A')
            stackA[topA++] = i;
        else if (src == 'B')
            stackB[topB++] = i;
        else
            stackC[topC++] = i;
    }
}
void show()
{
    cct_gotoxy(0, 20);
    cout << "         =========================" << endl;
    cout << "           A         B         C";
}
void showshuiping()
{
    cout << " A:";
    for (int i = 0; i < 10; i++)
    {
        if (stackA[i])
            cout << setw(2) << stackA[i];
        else
            cout << "  ";
    }
    cout << " B:";
    for (int i = 0; i < 10; i++)
    {
        if (stackB[i])
            cout << setw(2) << stackB[i];
        else
            cout << "  ";
    }
    cout << " C:";
    for (int i = 0; i < 10; i++)
    {
        if (stackC[i])
            cout << setw(2) << stackC[i];
        else
            cout << "  ";
    }
    cout << endl;
}
void showshuzhi(char src, char dst, int speed, int init)
{
    show();
    if (init) 
    {
        for (int i = 0; i < topA; i++) 
        {
            cct_gotoxy(10, 19 - i);
            cout << setw(2) << stackA[i];
        }
        for (int i = 0; i < topB; i++) 
        {
            cct_gotoxy(20, 19 - i);
            cout << setw(2) << stackB[i];
        }
        for (int i = 0; i < topC; i++) 
        {
            cct_gotoxy(30, 19 - i);
            cout << setw(2) << stackC[i];
        }
    }
    else 
    {
        if (src == 'A') 
        {
            cct_gotoxy(10, 19 - topA);
            cout << "  ";
        }
        else if (src == 'B') 
        {
            cct_gotoxy(20, 19 - topB);
            cout << "  ";
        }
        else if (src == 'C') 
        {
            cct_gotoxy(30, 19 - topC);
            cout << "  ";
        }
        if (dst == 'A') 
        {
            cct_gotoxy(10, 20 - topA);
            cout << setw(2) << stackA[topA - 1];
        }
        else if (dst == 'B') 
        {
            cct_gotoxy(20, 20 - topB);
            cout << setw(2) << stackB[topB - 1];
        }
        else if (dst == 'C') 
        {
            cct_gotoxy(30, 20 - topC);
            cout << setw(2) << stackC[topC - 1];
        }
    }
    if (speed)
        Sleep(200 * (5 - speed + 1));
    else 
        cin.ignore();
}
void move(char src, char dst, int speed, int show)
{
    int disk;
    if (src == 'A') {
        disk = stackA[--topA];
        stackA[topA] = 0; 
    }
    else if (src == 'B') {
        disk = stackB[--topB];
        stackB[topB] = 0; 
    }
    else {
        disk = stackC[--topC];
        stackC[topC] = 0; 
    }

    if (dst == 'A')
        stackA[topA++] = disk;
    else if (dst == 'B')
        stackB[topB++] = disk;
    else
        stackC[topC++] = disk;

    if (show)
    {
        cct_gotoxy(40, 25);
        showshuiping();
    }
    showshuzhi(src, dst, speed, 0);
}
void hanoi(int n, char src, char tmp, char dst, int speed, int show) 
{
    if (n > 1) 
    {
        hanoi(n - 1, src, dst, tmp, speed, show);
        cct_gotoxy(20, 25);
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst << "        "; 
        move(src, dst, speed, show);
        hanoi(n - 1, tmp, src, dst, speed, show);
    }
    if (n == 1) 
    {
        cct_gotoxy(20, 25);
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst << "        "; 
        move(src, dst, speed, show);
    }
}
int main()
{
    int n = 0, speed = 0, show = 0;
    char src, tmp, dst;
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
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
        cin.ignore(2048, '\n');
        break;
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
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
            cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(2048, '\n');
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
    while (1) 
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> speed;
        if (speed < 0 || speed > 5) {
            cout << "������Ч�����������룡" << endl;
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        break;
    }
    while (1) 
    {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> show;
        if (show != 0 && show != 1) {
            cout << "������Ч�����������룡" << endl;
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        break;
    }
    init(n, src);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << "��" << (show ? "" : "��") << "��ʾ�ڲ�����ֵ" << endl;
    if (show) 
    {
        cct_gotoxy(40, 25); 
        cout << "��ʼ:               ";
        showshuiping();
        if (speed) 
            Sleep(200 * (5 - speed + 1));
        else 
            cin.ignore();
        showshuzhi(src, dst, speed, 1);
    }
    else 
        showshuzhi(src, dst, speed, 1);
    hanoi(n, src, tmp, dst, speed, show);
    cct_gotoxy(20, 35);
    system("pause");
    return 0;
}