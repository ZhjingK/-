#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("三子棋游戏\n");
	printf("1.欢迎进入！\n");
	printf("0.遗憾退出！\n");
}
void game()
{
	char arr[ROW][COL] = {0};
	char tmp = 0;
	InitBoard(arr, ROW, COL);
	while (1)
	{
		printf("玩家下棋\n");        //提示玩家下棋
		PlayerMove(arr, ROW, COL);   //玩家下棋
		(tmp = IsWin(arr, ROW, COL)) != ' ';
		Display(arr, ROW, COL);      //打印棋盘     
		ComputerMove(arr,ROW,COL);
		(tmp = IsWin(arr, ROW, COL)) != ' ';
		Display(arr, ROW, COL);
		if (tmp == 'O')
		{
			printf("恭喜，你赢了\n");
			
		}
		else if (tmp == 'X')
		{
			printf("很遗憾，你输了\n");
			
		}
		else if(tmp == 'a')
		{
			printf("达成平局\n");
			
		}
	}	
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();                     //打印菜单
	    printf("请选择：");
	    scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("请输入正确的选择!\n");
				break;
		}
	}
	while (input);     //利用do-while循环让游戏可以连续玩
	system("pause");
	return 0;
}