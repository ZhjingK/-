#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROW 3   //�������̵�����
#define COL 3   //�������̵�����


void InitBoard(char arr[ROW][COL], int row, int col);//��ʼ������
void Display(char arr[ROW][COL], int row, int col);//��ӡ����
static int IsFull(char arr[ROW][COL], int row, int col);//�ж������Ƿ�����
void ComputerMove(char arr[ROW][COL],int row,int col);//��������
void PlayerMove(char arr[ROW][COL], int row, int col);//�������
char IsWin(char arr[ROW][COL], int row, int col);//�ж���Ӯ

#endif //__GAME_H__ 





