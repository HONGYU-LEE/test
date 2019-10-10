#include "head.h"

int main()
{
	int n;
	char Checkerboard[ROW][COL] = { 0 };
	srand((int)time(NULL));
	do
	{
		Menu_Game();
		printf("请输入您的选择：\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			Game(Checkerboard, ROW, COL);
			break;
		case 0:
			printf("结束游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (n);

	return 0;
}
