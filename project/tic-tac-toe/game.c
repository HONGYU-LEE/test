#include "head.h"

void Menu_Game()
{
	printf("*****************************************\n");
	printf("*********      1.开始游戏       *********\n");
	printf("*********      0.结束游戏       *********\n");
	printf("*****************************************\n");
}

void Init_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Checkerboard[i][j] = ' ';
		}
	}
}
//初始化棋盘

void Show_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		printf("---");
		printf("|");
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Checkerboard[i][j]);
				printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("---");
				printf("|");
		}
		printf("\n");
	}
}
//显示棋盘


void Player_Move(char Checkerboard[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入您要下的位置：\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= ROW && x > 0 && x <= ROW)
		{

			if (Checkerboard[x - 1][y - 1] == ' ')
			{
				Checkerboard[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被输入\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}

}
//玩家移动

void Computer_Move(char Checkerboard[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (Checkerboard[x][y] == ' ')
		{
			Checkerboard[x][y] = '#';
			break;
		}
	}



}
//电脑移动

char Full_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (Checkerboard[i][j] == ' ')
				return 'N';
	return 'F';
}
//判断棋盘是否下满 

char Win_Game(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j, flag = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if ((Checkerboard[i][j] == Checkerboard[i][j + 1]) && (Checkerboard[i][j] != ' '))
			{
				flag++;
			}
			else if (flag == CHESS_NUMBER - 1)
				return Checkerboard[i][j];
			else
			{
				flag = 0;
			}
		}
	}
	//判断行是否三子

	for (i = 0; i < row - 1; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((Checkerboard[i][j] == Checkerboard[i + 1][j]) && (Checkerboard[i][j] != ' '))
			{
				flag++;
			}
			else
			{
				flag = 0;
			}
			if (flag == CHESS_NUMBER - 1)
				return Checkerboard[i][j];
		}
	}
	//判断列是否三子 

	flag = 0;
	for (i = 0, j = 0; i < row - 1, j < col - 1; i++, j++)
	{
		if ((Checkerboard[i][j] == Checkerboard[i + 1][j + 1]) && (Checkerboard[i][j] != ' '))
		{
			flag++;
		}
		else
		{
			flag = 0;
		}
		if (flag == CHESS_NUMBER - 1)
			return Checkerboard[i][j];
	}
	//判断左对角线是否三子

	flag = 0;
	for (i = 0, j = row - 1; i < row - 1, j>0; i++, j--)
	{
		if ((Checkerboard[i][j] == Checkerboard[i + 1][j - 1]) && (Checkerboard[i][j] != ' '))
		{
			flag++;
		}
		else
		{
			flag = 0;
		}
		if (flag == CHESS_NUMBER - 1)
			return Checkerboard[i][j];
	}
	//判断右对角线是否三子

	if (Full_Checkerboard(Checkerboard, ROW, COL) == 'F')
		return 'F';
	//判断棋盘是否下满

	return 'N';
}
//判断游戏胜负情况

void Game(char Checkerboard[ROW][COL], int row, int col)
{
	char flag = 'N';
	srand((unsigned int)time(NULL));
	//设置随机数 
	Init_Checkerboard(Checkerboard, ROW, COL);
	Show_Checkerboard(Checkerboard, ROW, COL);
	while (1)
	{
		printf("现在是你的回合\n");
		Player_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

		printf("现在是对手的回合\n");
		Computer_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

	}
	if (flag == '*')
	{
		printf("玩家获胜\n");
	}
	else if (flag == '#')
	{
		printf("电脑获胜\n");
	}
	else if (flag == 'F')
	{
		printf("棋盘满，平局\n");
	}
}