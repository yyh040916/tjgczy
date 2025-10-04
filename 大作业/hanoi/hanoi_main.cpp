/*2351495 ������ ��ҵ��*/
#include"hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
int main()
{
	/* ����θ��Ƶ�main����ǰ�� */
	cout << "��ȷ�ϵ�ǰcmd���ڵĴ�СΪ40��*120�����ϣ�����Ϊ������/16����C������Q�˳�" << endl;
	while (1) {
		char ch = _getch();
		if (ch == 'C' || ch == 'c')
			break;
		if (ch == 'Q' || ch == 'q')
			return 0;
	}
	/* �����������ĳ��� */
	char choice;
	while (true)
	{
		choice = menu();
		if (choice == '0')
		{
			cct_gotoxy(20, 35);
			return 0;
		}
		cout << endl << endl;
		switch (choice)
		{
		case '1':
			solve_basic_hanoi();
			cout << endl;
			break;
		case '2':
			solve_with_step_count();
			cout << endl;
			break;
		case '3':
			solve_shuiping();
			cout << endl;
			break;
		case '4':
			solve_both_arrays();
			cout << endl;
			break;
		case '5':
			prepare_graphical_pillars();
			cout << endl;
			break;
		case '6':
			prepare_graphical_disks();
			cout << endl;
			break;
		case '7':
			first_disk_move();
			cout << endl;
			break;
		case '8':
			auto_move_hanoi();
			cout << endl;
			break;
		case '9':
			interactive_move_hanoi();
			cout << endl;
			break;
		}
	}
	return 0;
}