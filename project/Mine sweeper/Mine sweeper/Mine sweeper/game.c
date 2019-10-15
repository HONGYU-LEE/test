#include "head.h"

void GameMenu()
{
	printf("*****************************************\n");
	printf("*********      1.开始游戏       *********\n");
	printf("*********      0.结束游戏       *********\n");
	printf("*****************************************\n");
}

void InitBoard(char Board[ROWS][COLS], int row, int col,char ch)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Board[i][j] = ch;
		}
	}
}

void SetBoom(char Boom[ROWS][COLS], int row, int col)
{
	int x, y,count=0;
	while( count < BOOMNUM )
	{
		x = rand() % row+1;
		y = rand() % col+1;

		if (Boom[x][y] != '1')
		{
			Boom[x][y] = '1';
			count++;
		}
	}
}

void ShowBoard(char Board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf(" ");
	for (i = 0; i < row+1; i++)
	{
		printf("%d   ",i);
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		if (0 == i)
			printf("   |");
		else
			printf("|");
		printf("---");
	}
	printf("|");
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			
			if (0 == j)
			{
				printf(" ");
				printf("%d ", i + 1);
				printf("|");
			}
			printf(" %c ", Board[i+1][j+1]);
			printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			if ( 0 == j )
				printf("   |");
			printf("---");
			printf("|");
		}
		printf("\n");
	}
}

int BombsAround(char Boom[ROWS][COLS], int row, int col)
{
	int count = 0;
	count = Boom[row - 1][col] + Boom[row + 1][col] + Boom[row][col - 1] + Boom[row][col + 1] + Boom[row + 1][col + 1] + Boom[row - 1][col - 1] + Boom[row + 1][col - 1] + Boom[row - 1][col + 1] - 6 * '0';
	return count;
}

char FindBoom(char Board[ROWS][COLS], char Boom[ROWS][COLS], int row, int col)
{
	int x, y,count=0;
	while(count != SAFENUM)
	{
		ShowBoard(Board, ROW, COL);
		printf("请输入行和列：\n");
		scanf("%d%d",&x,&y);

		if ( Boom[x + 1][y + 1] == '1' )
		{
			ShowBoard(Boom, ROW, COL);
			return 'F';
		}

		Board[x + 1][y + 1] = BombsAround(Boom, x + 1, y + 1);
		count++;
		ShowBoard(Board, ROW, COL);
	}
	return 'T';
}

void Game(char Board[ROWS][COLS],char Boom[ROWS][COLS], int row, int col)
{
	char flag;
	InitBoard(Board, ROWS, COLS, '*');
	InitBoard(Boom, ROWS, COLS, '0');
	SetBoom(Boom, ROW, COL);
	ShowBoard(Board, ROW, COL);
	printf("\n");
	ShowBoard(Boom, ROW, COL);
	flag = FindBoom(Board, Boom, ROW, COL);
	if (flag == 'F')
	{
		printf("该位置为炸弹，游戏结束\n");
	}
	else
	{
		printf("游戏胜利\n");
	}
}