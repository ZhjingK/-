#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("��������Ϸ\n");
	printf("1.��ӭ���룡\n");
	printf("0.�ź��˳���\n");
}
void game()
{
	char arr[ROW][COL] = {0};
	char tmp = 0;
	InitBoard(arr, ROW, COL);
	while (1)
	{
		printf("�������\n");        //��ʾ�������
		PlayerMove(arr, ROW, COL);   //�������
		(tmp = IsWin(arr, ROW, COL)) != ' ';
		Display(arr, ROW, COL);      //��ӡ����     
		ComputerMove(arr,ROW,COL);
		(tmp = IsWin(arr, ROW, COL)) != ' ';
		Display(arr, ROW, COL);
		if (tmp == 'O')
		{
			printf("��ϲ����Ӯ��\n");
			
		}
		else if (tmp == 'X')
		{
			printf("���ź���������\n");
			
		}
		else if(tmp == 'a')
		{
			printf("���ƽ��\n");
			
		}
	}	
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();                     //��ӡ�˵�
	    printf("��ѡ��");
	    scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("��������ȷ��ѡ��!\n");
				break;
		}
	}
	while (input);     //����do-whileѭ������Ϸ����������
	system("pause");
	return 0;
}