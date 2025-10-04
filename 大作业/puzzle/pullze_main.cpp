/*2351495 大数据 闫业豪*/
#include"pullze.h"
int main()
{
	while (1)
	{
		cct_setfontsize("新宋体", 16);
		cct_setconsoleborder(120, 30, 500,600);
		char choice = main_menu();
		switch (choice)
		{
		case'A':
		case'a':
			putchar(choice);
			A_function();
			break;
		case'B':
		case'b':
			putchar(choice);
			B_function();
			break;
		case'C':
		case'c':
			putchar(choice);
			C_function();
			break;
		case'D':
		case'd':
			putchar(choice);
			D_function();
			break;
		case'E':
		case'e':
			putchar(choice);
			E_function();
			break;
		case'F':
		case'f':
			putchar(choice);
			F_function();
			break;
		case'H':
		case'h':
			putchar(choice);
			H_function();
			break;
		case'I':
		case'i':
			putchar(choice);
			I_function();
			break;
		case'J':
		case'j':
			putchar(choice);
			J_function();
			break;
		case'G':
		case'g':
			putchar(choice);
			G_function();
			break;
		
		case'K':
		case'k':
			putchar(choice);
			K_function();
			break;
		case'Q':
		case'q':
			putchar(choice);
			cct_cls();
			to_be_continued();
			return 0;
		}
	}
	return 0;
}
