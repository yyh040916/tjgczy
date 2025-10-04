/*2351495 ������ ��ҵ��*/
#define _CRT_SECURE_NO_WARNINGS		//ʹ����VS��Ϊunsafe�ĺ���
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>	//Dev/CB��strlen��Ҫ

struct tj_time {
	int tj_year;	//��ʾ���
	int tj_month;	//��ʾ��(1-12)
	int tj_day;		//��ʾ��(1-28/29/30/31)
	int tj_hour;	//��ʾСʱ(0-23)
	int tj_minute;	//��ʾ��(0-59)
	int tj_second;	//��ʾ��(0-59)
};

/* �����ڴ˶���������Ҫ�ĺ��� */

int is_leap_year(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int get_days_in_month(int year, int month)
{
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && is_leap_year(year)) 
	{
		return 29;
	}
	return days_in_month[month - 1];
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�������ʾ���ȴ��س���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	printf("\n���س�������");
	while (_getch() != '\r')
		;
	printf("\n\n");
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�����ϵͳ��ת��������������ֵת��Ϊ�뱾�����ƵĽṹ�岢���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void system_time_output(const time_t input_time)  //time_t�ı�����64λ�޷�������
{
	struct tm* tt;	//struct tm Ϊϵͳ����Ľṹ��

	tt = localtime(&input_time);	//localtimeΪϵͳ����

	/* tm_*** Ϊstruct tm�еĳ�Ա���ͱ����struct tj_time��������ݲ���ȫ���ϣ����庬���Լ������������ */
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tt->tm_year + 1900, tt->tm_mon + 1, tt->tm_mday, tt->tm_hour, tt->tm_min, tt->tm_sec);

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void tj_time_output(const struct tj_time* const tp)
{
	/* ʵ���Զ���ṹ������������ʽ��system_time_output��ͬ */
	printf("%04d-%02d-%02d %02d:%02d:%02d\n", tp->tj_year, tp->tj_month, tp->tj_day, tp->tj_hour, tp->tj_minute, tp->tj_second);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��Զ���ת������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
struct tj_time* tj_time_convert(int input_time)
{
	static struct tj_time result;	//���徲̬�ֲ���������׼��

	/* ʵ�ֹ��̿�ʼ�������������Ӧ�Ķ��弰ִ����伴�� */
	long long seconds = (long long)input_time + 8 * 3600;
	result.tj_second = seconds % 60;
	seconds /= 60;
	result.tj_minute = seconds % 60;
	seconds /= 60;
	result.tj_hour = seconds % 24;
	seconds /= 24;
	result.tj_year = 1970;
	while (1)
	{
		int days_in_year = is_leap_year(result.tj_year) ? 366 : 365;
		if (seconds >= days_in_year) 
		{
			seconds -= days_in_year;
			result.tj_year++;
		}
		else 
		{
			break;
		}
	}
	result.tj_month = 1;
	while (result.tj_month <= 12) 
	{
		int days_this_month = get_days_in_month(result.tj_year, result.tj_month);
		if (seconds >= days_this_month) 
		{
			seconds -= days_this_month;
			result.tj_month++;
		}
		else 
		{
			break;
		}
	}
	result.tj_day = (int)seconds + 1;
	/* ʵ�ֹ��̽��� */

	return &result;	//ע�⣬���ص��Ǿ�̬�ֲ������ĵ�ַ������䲻׼��
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
	int read_time;
	struct tj_time* tp;

	for (;;) {
		int ret = scanf("%d", &read_time); //��Ϊ���������ض��򣬴˴������κ���ʾ

		/* ��������<0���˳�ѭ�� */
		if (ret != 1)
			break;

		printf("����             : %d\n", read_time);
		printf("ϵͳת���Ľ��   : ");
		system_time_output(read_time);

		printf("�Զ���ת���Ľ�� : ");
		tp = tj_time_convert(read_time);
		tj_time_output(tp);

		wait_for_enter();
	}

	if (1) {
		struct tj_time* tp;
		int t = (int)time(0);		//ϵͳ������ȡ��ǰϵͳʱ�䣨��1970-01-01 00:00:00��ʼ��������

		printf("��ǰϵͳʱ��     : %d\n", t);
		printf("ϵͳת���Ľ��   : ");
		system_time_output(t);

		printf("�Զ���ת���Ľ�� : ");
		tp = tj_time_convert(t);
		tj_time_output(tp);

		wait_for_enter();
	}

	return 0;
}