#include "head.h"

int main()
{
	int n;
	char board[ROWS][COLS] = { 0 };
	char bombs[ROWS][COLS] = { 0 };
	srand((int)time(NULL));
	do
	{
		GameMenu();
		printf("请输入您的选择：\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			Game(board, bombs, ROWS, COLS);
			break;
		case 0:
			printf("结束游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	}while (n);

	return 0;
}