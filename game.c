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
				return 1;//δ����
			}
		}
	}
	return 0;//����������
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
		
	    printf("���������꣺");
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
				printf("��ǰ�����Ѿ���ռ�ã����������룺");
			}
		}
		else
		{
			printf("�������������");
		}
	}
}
char IsWin(char arr[ROW][COL], int row, int col)//��������ȣ�����ȣ��Խ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2] && arr[i][j + 1] != ' ')//�����
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
				&& arr[i + 1][j] != ' ')//�����
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
				arr[i + 1][j + 1] != ' ')//�Խ������ 
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
	if (IsFull(arr, row, col) == 0)//ƽ��
	{
		return 'a';
	}
}