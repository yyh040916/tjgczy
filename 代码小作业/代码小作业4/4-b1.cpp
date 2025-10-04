/*2351495 大数据 闫业豪*/
#include <iostream>
#include<cmath>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：daxie()
  功    能：输出大写的0~9
  输入参数：int num, int flag_of_zero
  返 回 值：无
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记控制是否输出“零”
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main() {
    double n;
    cout << "请输入[0-100亿)之间的数字:" << endl;
    cin >> n;
    if (n == 0) 
    {
        cout << "大写结果是:" << endl;
        daxie(0, 1);
        cout << "圆整" << endl;
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
    int n10 = int(n / 100) % 10;       // 角
    int n11 = int(n / 10) % 10;        // 分
    int n12 = int(n / 1) % 10;         // 分
    bool flag1 = false, flag2 = false, flag3 = false;
    cout << "大写结果是:" << endl;
    // 十亿
    if (n1 == 1) 
    {
        daxie(1, true); 
        cout << "拾"; 
    }
    else if (n1 == 2) 
    { 
        daxie(2, true); 
        cout << "拾"; 
    }
    else if (n1 == 3) 
    { 
        daxie(3, true); 
        cout << "拾"; 
    }
    else if (n1 == 4) 
    { 
        daxie(4, true); 
        cout << "拾"; 
    }
    else if (n1 == 5) 
    { 
        daxie(5, true); 
        cout << "拾"; 
    }
    else if (n1 == 6) 
    { 
        daxie(6, true); 
        cout << "拾"; 
    }
    else if (n1 == 7) 
    {
        daxie(7, true); 
        cout << "拾"; 
    }
    else if (n1 == 8) 
    { 
        daxie(8, true); 
        cout << "拾"; 
    }
    else if (n1 == 9) 
    { 
        daxie(9, true); 
        cout << "拾"; 
    }
    // 亿
    if (n2 == 0 && n1 != 0) 
    { 
        cout << "亿"; 
    }
    else if (n2 == 1) 
    { 
        daxie(1, true); 
        cout << "亿"; 
    }
    else if (n2 == 2) 
    { 
        daxie(2, true); 
        cout << "亿"; 
    }
    else if (n2 == 3) 
    { 
        daxie(3, true); 
        cout << "亿"; 
    }
    else if (n2 == 4) 
    { 
        daxie(4, true); 
        cout << "亿";
    }
    else if (n2 == 5) 
    {
        daxie(5, true);
        cout << "亿"; 
    }
    else if (n2 == 6) 
    { 
        daxie(6, true); 
        cout << "亿"; 
    }
    else if (n2 == 7) 
    { 
        daxie(7, true); 
        cout << "亿"; 
    }
    else if (n2 == 8) 
    { 
        daxie(8, true); 
        cout << "亿"; 
    }
    else if (n2 == 9) 
    { 
        daxie(9, true); 
        cout << "亿"; 
    }
    if (flag3 == false && !n3 && !n4 && !n5 && !n6 && !n7 && !n8 && !n9 && !n10 && !n11 && !n12 && (n1 || n2)) 
    {
        cout << "圆整";
        flag3 = true;
    }
    // 千万
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
        cout << "仟";
    }
    // 百万
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
        cout << "佰";
    }
    // 十万
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
        cout << "拾";
    }
    // 万
    if (n6 == 0) 
    {
        if (n3 || n4 || n5) 
        { 
            cout << "万"; 
        }
    }
    else 
    {
        daxie(n6, true);
        cout << "万";
    }
    if (flag3 == false && !n7 && !n8 && !n9 && !n10 && !n11 && !n12) 
    {
        cout << "圆整";
        flag3 = true;
    }
    // 千
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
        cout << "仟";
    }
    // 百
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
        cout << "佰";
    }
    // 十
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
        cout << "拾";
    }
    // 个
    if (n10 == 0) 
    {
        // 不输出
    }
    else 
    {
        daxie(n10, true);
    }
    if (flag3 == false && (n1 || n2 || n3 || n4 || n5 || n6 || n7 || n8 || n9 || n10)) 
    {
        cout << "圆";
        if (flag3 == false && !n11 && !n12) 
        {
            cout << "整";
            flag3 = true;
        }
    }
    if (flag3 == true) 
    {
        cout << endl;
        return 0;
    }
    // 角
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
        cout << "角";
    }
    // 分
    if (n12 == 0) 
    {
        cout << "整";
    }
    else 
    {
        daxie(n12, true);
        cout << "分";
    }
    cout << endl;
    return 0;
}
