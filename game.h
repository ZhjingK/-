#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROW 3   //定义棋盘的行数
#define COL 3   //定义棋盘的列数


void InitBoard(char arr[ROW][COL], int row, int col);//初始化棋盘
void Display(char arr[ROW][COL], int row, int col);//打印棋盘
static int IsFull(char arr[ROW][COL], int row, int col);//判断棋盘是否下满
void ComputerMove(char arr[ROW][COL],int row,int col);//电脑下棋
void PlayerMove(char arr[ROW][COL], int row, int col);//玩家下棋
char IsWin(char arr[ROW][COL], int row, int col);//判断输赢

#endif //__GAME_H__ 





