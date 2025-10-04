/*2351495 大数据 闫业豪*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
const int MAX_MONTHS = 12;
const int MAX_LINES = 8;
const int LINE_WIDTH = 28;
int zeller(int y, int m, int d)
{
	if (m < 3)
	{
		m += 12;
		y -= 1;
	}
	int c = y / 100;
	y = y % 100;
	int w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	w = (w % 7 + 7) % 7;
	return w;
}
//计算指定年月的天数
int get_days_in_month(int year, int month)
{
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return 29;
	return days[month - 1];
}
//打印月份
void generate_month_title(char title_line[LINE_WIDTH + 1], int month)
{
	char month_str[10];
	sprintf(month_str, "%d月", month);
	int title_length = 0;
	while (month_str[title_length] != '\0')
		title_length++;
	int left_pad = (LINE_WIDTH - title_length) / 2;
	if (month >= 10)
		left_pad -= 1;
	int right_pad = LINE_WIDTH - title_length - left_pad;
	int pos = 0;
	for (int i = 0; i < left_pad; i++)
		title_line[pos++] = ' ';
	for (int i = 0; i < title_length; i++)
		title_line[pos++] = month_str[i];
	for (int i = 0; i < right_pad; i++)
		title_line[pos++] = ' ';
	title_line[pos] = '\0';
}
//打印星期
void generate_weekday_header(char week_line[LINE_WIDTH + 1])
{
	char week_header[29] = "Sun Mon Tue Wed Thu Fri Sat";
	int pos = 0;
	for (int i = 0; i < 7; i++) 
	{
		week_line[pos++] = week_header[i * 4];
		week_line[pos++] = week_header[i * 4 + 1];
		week_line[pos++] = week_header[i * 4 + 2];
		week_line[pos++] = ' ';
	}
	week_line[pos] = '\0';
}
//打印日期
bool generate_date_line(char date_line[LINE_WIDTH + 1], int line_num, int start_weekday, int days)
{
	int start_day = line_num * 7 + 1 - start_weekday;
	if (start_day > days)
		return false;
	int pos = 0;
	for (int i = 0; i < 7; i++)
	{
		int current_day = start_day + i;
		if (current_day < 1 || current_day > days) 
		{
			date_line[pos++] = ' ';
			date_line[pos++] = ' ';
			date_line[pos++] = ' ';
			date_line[pos++] = ' ';
		}
		else 
		{
			if (current_day < 10)
			{  
				date_line[pos++] = '0' + current_day;  
				date_line[pos++] = ' ';
				date_line[pos++] = ' ';
				date_line[pos++] = ' ';
			}
			else 
			{ 
				date_line[pos++] = '0' + (current_day / 10);
				date_line[pos++] = '0' + (current_day % 10);
				date_line[pos++] = ' ';
				date_line[pos++] = ' ';
			}
		}
	}
	date_line[pos] = '\0';
	return true;
}
//打印空白
void generate_blank_line(char blank_line[LINE_WIDTH + 1])
{
	for (int i = 0; i < LINE_WIDTH; i++)
		blank_line[i] = ' ';
	blank_line[LINE_WIDTH] = '\0';
}
//计算月份日历需要的行数
int calculate_month_lines(int start_weekday, int days)
{
	int title_lines = 2;
	int date_lines = (days + start_weekday - 1) / 7 + 1;
	return title_lines + date_lines;
}
int main()
{
	int year, monthsPerLine;
	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;
		if (!(cin >> year))
		{
			cin.clear();
			cin.ignore(2048, '\n');
			continue;
		}
		if (year > 2100 || year < 1900)
			continue;
		break;
	}
	while (1)
	{
		cout << "请输入每行打印的月份数[1/2/3/4/6/12]" << endl;
		if (!(cin >> monthsPerLine))
		{
			cin.clear();
			cin.ignore(2048, '\n');
			continue;
		}
		if (monthsPerLine == 1 || monthsPerLine == 2 || monthsPerLine == 3 ||monthsPerLine == 4 || monthsPerLine == 6 || monthsPerLine == 12)
			break;
	}
	cout << year << "年的日历:" << endl << endl;
	int group_count = (12 / monthsPerLine) + ((12 % monthsPerLine) != 0 ? 1 : 0);
	int month_lines[MAX_MONTHS];
	for (int m = 0; m < MAX_MONTHS; m++) 
	{
		int start_weekday = zeller(year, m + 1, 1);
		int days = get_days_in_month(year, m + 1);
		month_lines[m] = calculate_month_lines(start_weekday, days);
	}
	for (int g = 0; g < group_count; g++) 
	{
		int start_month = g * monthsPerLine;
		int end_month = (start_month + monthsPerLine) < MAX_MONTHS ? (start_month + monthsPerLine) : MAX_MONTHS;
		// 找出本组最大行数
		int max_lines = 0;
		for (int m = start_month; m < end_month; m++) 
		{
			if (month_lines[m] > max_lines) 
			{
				max_lines = month_lines[m];
			}
		}

		for (int line = 0; line < max_lines; line++) 
		{
			for (int m = start_month; m < end_month; m++) 
			{
				
				if (m > start_month) 
				{
					cout << "    "; 
				}
				// 获取当前月份信息
				int month_num = m + 1;
				int start_weekday = zeller(year, month_num, 1);
				int days = get_days_in_month(year, month_num);

				
				char line_buffer[LINE_WIDTH + 1];

				if (line == 0) 
				{
					
					generate_month_title(line_buffer, month_num);
				}
				else if (line == 1) 
				{
					
					generate_weekday_header(line_buffer);
				}
				else if (line - 2 < (month_lines[m] - 2)) 
				{
					if (!generate_date_line(line_buffer, line - 2, start_weekday, days)) 
					{
						generate_blank_line(line_buffer);
					}
				}
				else 
				{
					generate_blank_line(line_buffer);
				}
				cout << line_buffer;
			}
			cout << endl; 
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}