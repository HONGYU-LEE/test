#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr[4] = { 0 }, i;
	for (i = 0; i < 4; i++)
	{
		arr[i] = 1;
		if (((arr[0] == 0) + (arr[2] == 1) + (arr[3] == 1) + (arr[3] == 0)) == 3)
		{
			printf("Ð×ÊÖÎª%c\n", 'A'+i);
			break;
		}
		arr[i] = 0;

	}
	return 0;
}