#include "head.h"

int main()
{
	int n;
	char Checkerboard[ROW][COL] = { 0 };
	srand((int)time(NULL));
	do
	{
		Menu_Game();
		printf("����������ѡ��\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			Game(Checkerboard, ROW, COL);
			break;
		case 0:
			printf("������Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (n);

	return 0;
}
