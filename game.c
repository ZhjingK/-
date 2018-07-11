#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char arr[ROW][COL],int row, int col)
{
	memset(arr, ' ', row*col*sizeof(arr[0][0]));
}
void Display(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("| %c | %c | %c |\n", arr[i][0], arr[i][1], arr[i][2]);
		if (i < 2)
		{
			printf("----|---|----\n");
		}
	}
	printf("\n");
}
static int IsFull(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 1;//未下满
			}
		}
	}
	return 0;//棋盘下满了
}
void ComputerMove(char arr[ROW][COL],int row,int col)
{
	while (1)
	{
		int i = rand() % 3;
		int j = rand() % 3;
	    if (arr[i][j] == ' ')
		{
			arr[i][j] = 'X';
			break;
		}
	}
}
void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	while (1)
	{
		
	    printf("请输入坐标：");
		scanf("%d%d", &i, &j);
		i--;
		j--;
		if (((i >= 0) && (i < 3)) && ((j >= 0) && (j < 3)))
		{
			if (arr[i][j] == ' ')
			{
				arr[i][j] = 'O';
				break;
			}
			else
			{
				printf("当前坐标已经被占用，请重新输入：");
			}
		}
		else
		{
			printf("输入的坐标有误");
		}
	}
}
char IsWin(char arr[ROW][COL], int row, int col)//满足行相等，列相等，对角线相等
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2] && arr[i][j + 1] != ' ')//行相等
			{
				return arr[i][j+1];
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == arr[i + 1][j]
				&& arr[i + 1][j] == arr[i + 2][j]
				&& arr[i + 1][j] != ' ')//列相等
			{
				return arr[i+1][j];
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == arr[i + 1][j + 1] &&
				arr[i + 1][j + 1] == arr[i + 2][j + 2] &&
				arr[i + 1][j + 1] != ' ')//对角线相等 
			{
				return arr[i+1][j+1];
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i + 2][j] == arr[i + 1][j + 1]
				&& arr[i + 1][j + 1] == arr[i][j + 2]
				&& arr[i + 1][j + 1] != ' ')
			{
				return arr[i + 1][j + 1];
			}
		}
	}
	if (IsFull(arr, row, col) == 0)//平局
	{
		return 'a';
	}
}