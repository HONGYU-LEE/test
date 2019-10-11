#include "head.h"

void Menu_Game()
{
	printf("*****************************************\n");
	printf("*********      1.��ʼ��Ϸ       *********\n");
	printf("*********      0.������Ϸ       *********\n");
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
//��ʼ������

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
//��ʾ����


void Player_Move(char Checkerboard[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("��������Ҫ�µ�λ�ã�\n");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= ROW && y > 0 && y <= COL)
		{

			if (Checkerboard[x - 1][y - 1] == ' ')
			{
				Checkerboard[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������ѱ�����\n");
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}

}
//����ƶ�

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
//�����ƶ�

char Full_Checkerboard(char Checkerboard[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			if (Checkerboard[i][j] == ' ')
				return 'N';
	return 'F';
}
//�ж������Ƿ����� 

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
	//�ж����Ƿ�����

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
	//�ж����Ƿ����� 

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
	//�ж���Խ����Ƿ�����

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
	//�ж��ҶԽ����Ƿ�����

	if (Full_Checkerboard(Checkerboard, ROW, COL) == 'F')
		return 'F';
	//�ж������Ƿ�����

	return 'N';
}
//�ж���Ϸʤ�����

void Game(char Checkerboard[ROW][COL], int row, int col)
{
	char flag = 'N';
	srand((unsigned int)time(NULL));
	//��������� 
	Init_Checkerboard(Checkerboard, ROW, COL);
	Show_Checkerboard(Checkerboard, ROW, COL);
	while (1)
	{
		printf("��������Ļغ�\n");
		Player_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

		printf("�����Ƕ��ֵĻغ�\n");
		Computer_Move(Checkerboard, ROW, COL);
		Show_Checkerboard(Checkerboard, ROW, COL);
		if ((flag = Win_Game(Checkerboard, ROW, COL)) != 'N')
			break;

	}
	if (flag == '*')
	{
		printf("��һ�ʤ\n");
	}
	else if (flag == '#')
	{
		printf("���Ի�ʤ\n");
	}
	else if (flag == 'F')
	{
		printf("��������ƽ��\n");
	}
}