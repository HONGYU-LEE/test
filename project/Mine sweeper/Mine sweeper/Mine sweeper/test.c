#include "head.h"

int main()
{
	int n;
	char Board1[ROWS][COLS] = { 0 };
	char Boom1[ROWS][COLS] = { 0 };
	srand((int)time(NULL));
	do
	{
		GameMenu();
		printf("����������ѡ��\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			Game(Board1, Boom1, ROWS, COLS);
			break;
		case 0:
			printf("������Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	}while (n);

	return 0;
}