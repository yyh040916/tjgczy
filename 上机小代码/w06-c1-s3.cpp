/*2351495 大数据 闫业豪*/
#include<iostream>
#include<iomanip>
using namespace std;
 
int main()
{
	int x1,y1,x2,y2;
	cout<<"请输入第1个点的坐标 : ";
	cin>>x1>>y1;
	cout<<"请输入第2个点的坐标 : ";
	cin>>x2>>y2;
	if(x1==x2)
		cout<<"平行于y轴"<<endl;
	else if(y1==y2)
		cout<<"平行于x轴"<<endl;
	else if(x1*y2==x2*y1)
		cout<<"经过原点"<<endl;
	else
	{
		double k=(double)(y2-y1)/(x2-x1);
		double b=(double)(y1-k*x1);
		double m = -b / k;
        double n = b;
		cout<<setiosflags(ios::fixed)<<setprecision(2);
		cout<<"直线与x轴交点 : ("<<m<<", 0.00)"<<endl;
		cout<<"直线与y轴交点 : (0.00, "<<n<<")"<<endl;
	}
	return 0;
}

