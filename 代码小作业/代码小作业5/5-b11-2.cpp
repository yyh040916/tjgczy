/*2351495 ������ ��ҵ��*/
#include <iostream>
#include <string>
#include <cmath>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero = 0)
{
    if (num == 0 && flag_of_zero)
    {
        result += chnstr[0];
        result += chnstr[1];
    }
    else if (num > 0 && num <= 9)
    {
        result += chnstr[num * 2];
        result += chnstr[num * 2 + 1];
    }
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
    double n;
    while (1)
    {
        cout << "������[0-100��)֮�������:" << endl;
        if (!(cin >> n))
        {
            cin.clear();
            cin.ignore(2048, '\n');
            continue;
        }
        if (n >= 0 && n < 10000000000)
            break;
    }
    cout << "��д�����:" << endl;
    if (n == 0)
    {
        daxie(0, 1);
        result += "Բ��";
        cout << result << endl;
        return 0;
    }
    int n1 = int(n / 1000000000) % 10; 
    int n2 = int(n / 100000000) % 10;  
    int n3 = int(n / 10000000) % 10;  
    int n4 = int(n / 1000000) % 10; 
    int n5 = int(n / 100000) % 10;   
    int n6 = int(n / 10000) % 10;  
    int n7 = int(n / 1000) % 10;   
    int n8 = int(n / 100) % 10;  
    int n9 = int(n / 10) % 10;   
    n /= 10;
    n -= floor(n);
    n *= 1000;
    n += 0.001;
    int n10 = int(n / 100) % 10;       
    int n11 = int(n / 10) % 10;        
    int n12 = int(n / 1) % 10;
    int flag = 0, yuanzheng = 0;

    
    //ʮ��-��λ
    if (n1 > 0 || n2 > 0)
    {
        if (n1 > 0)
        {
            daxie(n1);
            result += "ʰ";
        }
        daxie(n2);
        result += "��";
        if (n3 == 0 && n4 == 0 && n5 == 0 && n6 == 0 &&
            n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 &&
            n11 == 0 && n12 == 0) 
        {
            result += "Բ��";
            yuanzheng = 1;
        }
    }
    //ǧ��-��λ
    if (n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0)
    {
        if ((n1 > 0 || n2 > 0) && n3 == 0 && (n4 > 0 || n5 > 0 || n6 > 0)) 
        {
            daxie(0, 1);
            flag = 1;
        }
        if (n3 > 0) 
        {
            daxie(n3);
            result += "Ǫ";
            flag = 0;
        }
        if (n4 == 0 && n3 > 0 && (n5 > 0 || n6 > 0)) 
        {
            daxie(0, 1);
            flag = 1;
        }
        else if (n4 > 0) 
        {
            daxie(n4);
            result += "��";
            flag = 0;
        }
        if (n5 == 0 && (n3 > 0 || n4 > 0) && n6 > 0 && flag == 0) 
        {
            daxie(0, 1);
            flag = 1;
        }
        else if (n5 > 0) 
        {
            daxie(n5);
            result += "ʰ";
            flag = 0;
        }
        if (n6 > 0) 
        {
            daxie(n6);
        }
        result += "��";
        flag = 0;
        if (n7 == 0 && n8 == 0 && n9 == 0 && n10 == 0 &&
            n11 == 0 && n12 == 0) 
        {
            result += "Բ��";
            yuanzheng = 1;
        }
    }
    // ǧ-��λ
    if (n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0)
    {
        if ((n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0) &&
            n7 == 0 && (n8 > 0 || n9 > 0 || n10 > 0)) 
        {
            daxie(0, 1);
            flag = 1;
        }
        if (n7 > 0) 
        {
            daxie(n7);
            result += "Ǫ";
            flag = 0;
        }
        if (n8 == 0 && n7 > 0 && (n9 > 0 || n10 > 0)) 
        {
            daxie(0, 1);
            flag = 1;
        }
        else if (n8 > 0) 
        {
            daxie(n8);
            result += "��";
            flag = 0;
        }
        if (n9 == 0 && (n7 > 0 || n8 > 0) && n10 > 0 && flag == 0) {
            daxie(0, 1);
        }
        else if (n9 > 0) 
        {
            daxie(n9);
            result += "ʰ";
        }

        if (n10 > 0) 
        {
            daxie(n10);
        }
    }
    if ((n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 || n6 > 0 ||
        n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0) && yuanzheng == 0) 
    {
        result += "Բ";
        if (n11 == 0 && n12 == 0) 
        {
            result += "��";
        }
    }
    if (n11 > 0 || n12 > 0)
    {
        if (n11 == 0 && n12 > 0 &&
            (n1 > 0 || n2 > 0 || n3 > 0 || n4 > 0 || n5 > 0 ||
                n6 > 0 || n7 > 0 || n8 > 0 || n9 > 0 || n10 > 0)) 
        {
            daxie(0, 1);
        }
        else if (n11 > 0) 
        {
            daxie(n11);
            result += "��";
        }
        if (n12 > 0) 
        {
            daxie(n12);
            result += "��";
        }
        else if (n11 > 0) 
        {
            result += "��";
        }
    }
    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}