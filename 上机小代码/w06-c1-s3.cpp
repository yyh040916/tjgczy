/*2351495 ������ ��ҵ��*/
#include<iostream>
#include<iomanip>
using namespace std;
 
int main()
{
	int x1,y1,x2,y2;
	cout<<"�������1��������� : ";
	cin>>x1>>y1;
	cout<<"�������2��������� : ";
	cin>>x2>>y2;
	if(x1==x2)
		cout<<"ƽ����y��"<<endl;
	else if(y1==y2)
		cout<<"ƽ����x��"<<endl;
	else if(x1*y2==x2*y1)
		cout<<"����ԭ��"<<endl;
	else
	{
		double k=(double)(y2-y1)/(x2-x1);
		double b=(double)(y1-k*x1);
		double m = -b / k;
        double n = b;
		cout<<setiosflags(ios::fixed)<<setprecision(2);
		cout<<"ֱ����x�ύ�� : ("<<m<<", 0.00)"<<endl;
		cout<<"ֱ����y�ύ�� : (0.00, "<<n<<")"<<endl;
	}
	return 0;
}

