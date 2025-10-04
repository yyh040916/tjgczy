/*2351495 大数据 闫业豪*/
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double pi=3.14159;
int main()
{
 	int x,y,r,a,b;
 	cout<<"请输入圆心x坐标 [-100..100] : ";
 	cin>>x;
 	cout<<"请输入圆心y坐标 [-100..100] : ";
 	cin>>y;
 	cout<<"请输入圆半径r [1..100] : ";
 	cin>>r;
 	cout<<"请输入起点(旧家)角度 [0..360) : ";
 	cin>>a;
 	cout<<"请输入终点(新家)角度 [0..360) : ";
 	cin>>b;
 	double rad1 = a * pi / 180.0;
    double rad2 = b * pi / 180.0;
 	double x1 = x + r * cos(rad1);
    double y1 = y + r * sin(rad1);
    double x2 = x + r * cos(rad2);
    double y2 = y + r * sin(rad2);
    double distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    cout << setiosflags(ios::fixed) << setprecision(3);
    cout << "最近距离 : " << distance << endl;
	return 0;
}
