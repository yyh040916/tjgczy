/*2351495 ������ ��ҵ��*/
#include <iostream>
#include<cmath>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�daxie()
  ��    �ܣ������д��0~9
  ���������int num, int flag_of_zero
  �� �� ֵ����
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
	case 0:
		if (flag_of_zero)	//�˱�ǿ����Ƿ�������㡱
			cout << "��";
		break;
	case 1:
		cout << "Ҽ";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "��";
		break;
	case 5:
		cout << "��";
		break;
	case 6:
		cout << "½";
		break;
	case 7:
		cout << "��";
		break;
	case 8:
		cout << "��";
		break;
	case 9:
		cout << "��";
		break;
	default:
		cout << "error";
		break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main() {
    double n;
    cout << "������[0-100��)֮�������:" << endl;
    cin >> n;
    if (n == 0) 
    {
        cout << "��д�����:" << endl;
        daxie(0, 1);
        cout << "Բ��" << endl;
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
    int n10 = int(n / 100) % 10;       // ��
    int n11 = int(n / 10) % 10;        // ��
    int n12 = int(n / 1) % 10;         // ��
    bool flag1 = false, flag2 = false, flag3 = false;
    cout << "��д�����:" << endl;
    // ʮ��
    if (n1 == 1) 
    {
        daxie(1, true); 
        cout << "ʰ"; 
    }
    else if (n1 == 2) 
    { 
        daxie(2, true); 
        cout << "ʰ"; 
    }
    else if (n1 == 3) 
    { 
        daxie(3, true); 
        cout << "ʰ"; 
    }
    else if (n1 == 4) 
    { 
        daxie(4, true); 
        cout << "ʰ"; 
    }
    else if (n1 == 5) 
    { 
        daxie(5, true); 
        cout << "ʰ"; 
    }
    else if (n1 == 6) 
    { 
        daxie(6, true); 
        cout << "ʰ"; 
    }
    else if (n1 == 7) 
    {
        daxie(7, true); 
        cout << "ʰ"; 
    }
    else if (n1 == 8) 
    { 
        daxie(8, true); 
        cout << "ʰ"; 
    }
    else if (n1 == 9) 
    { 
        daxie(9, true); 
        cout << "ʰ"; 
    }
    // ��
    if (n2 == 0 && n1 != 0) 
    { 
        cout << "��"; 
    }
    else if (n2 == 1) 
    { 
        daxie(1, true); 
        cout << "��"; 
    }
    else if (n2 == 2) 
    { 
        daxie(2, true); 
        cout << "��"; 
    }
    else if (n2 == 3) 
    { 
        daxie(3, true); 
        cout << "��"; 
    }
    else if (n2 == 4) 
    { 
        daxie(4, true); 
        cout << "��";
    }
    else if (n2 == 5) 
    {
        daxie(5, true);
        cout << "��"; 
    }
    else if (n2 == 6) 
    { 
        daxie(6, true); 
        cout << "��"; 
    }
    else if (n2 == 7) 
    { 
        daxie(7, true); 
        cout << "��"; 
    }
    else if (n2 == 8) 
    { 
        daxie(8, true); 
        cout << "��"; 
    }
    else if (n2 == 9) 
    { 
        daxie(9, true); 
        cout << "��"; 
    }
    if (flag3 == false && !n3 && !n4 && !n5 && !n6 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12 && (n1 || n2)) 
    {
        cout << "Բ��";
        flag3 = true;
    }
    // ǧ��
    if (n3 == 0)
    {
        if ((n4 || n5 || n6) && (n1 || n2)) 
        {
            daxie(0, true);
            flag1 = true;
        }
    }
    else 
    {
        daxie(n3, true);
        cout << "Ǫ";
    }
    // ����
    if (n4 == 0) 
    {
        if (!flag1 && ((n1 || n2) || n3) && (n5 || n6)) 
        {
            daxie(0, true);
            flag1 = true;
        }
    }
    else 
    {
        daxie(n4, true);
        cout << "��";
    }
    // ʮ��
    if (n5 == 0) 
    {
        if ((!flag1 && ((n1 || n2) || n3 || n4) && (n6)) || (flag1 && n4 != 0 && n6 != 0)) 
        {
            daxie(0, true);
            flag1 = true;
        }
    }
    else 
    {
        daxie(n5, true);
        cout << "ʰ";
    }
    // ��
    if (n6 == 0) 
    {
        if (n3 || n4 || n5) 
        { 
            cout << "��"; 
        }
    }
    else 
    {
        daxie(n6, true);
        cout << "��";
    }
    if (flag3 == false && !n7 && !n8 && !n9 && !n10 && !n11 && !n12) 
    {
        cout << "Բ��";
        flag3 = true;
    }
    // ǧ
    if (n7 == 0) 
    {
        if (((n1 || n2) || (n3 || n4 || n5 || n6)) && (n8 || n9 || n10)) 
        {
            daxie(0, true);
            flag2 = true;
        }
    }
    else 
    {
        daxie(n7, true);
        cout << "Ǫ";
    }
    // ��
    if (n8 == 0) 
    {
        if (!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7) && (n9 || n10)) 
        {
            daxie(0, true);
            flag2 = true;
        }
    }
    else 
    {
        daxie(n8, true);
        cout << "��";
    }
    // ʮ
    if (n9 == 0) 
    {
        if ((!flag2 && ((n1 || n2) || (n3 || n4 || n5 || n6) || n7 || n8) && (n10)) || (flag2 && n8 != 0 && n10 != 0)) 
        {
            daxie(0, true);
            flag2 = true;
        }
    }
    else 
    {
        daxie(n9, true);
        cout << "ʰ";
    }
    // ��
    if (n10 == 0) 
    {
        // �����
    }
    else 
    {
        daxie(n10, true);
    }
    if (flag3 == false && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10)) 
    {
        cout << "Բ";
        if (flag3 == false && !n11 && !n12) 
        {
            cout << "��";
            flag3 = true;
        }
    }
    if (flag3 == true) 
    {
        cout << endl;
        return 0;
    }
    // ��
    if (n11 == 0) 
    {
        if (n12 && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10)) 
        {
            daxie(0, true);
        }
    }
    else 
    {
        daxie(n11, true);
        cout << "��";
    }
    // ��
    if (n12 == 0) 
    {
        cout << "��";
    }
    else 
    {
        daxie(n12, true);
        cout << "��";
    }
    cout << endl;
    return 0;
}
