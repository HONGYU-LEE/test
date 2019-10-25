#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	const int row = 50;
	const int col = 50;
	int i, j, n;
	int arr[row][col] = { 0 };
	printf("请输入杨辉三角的层数：\n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = n - i- 1; j > 0; j--)
		{
			printf(" ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

}