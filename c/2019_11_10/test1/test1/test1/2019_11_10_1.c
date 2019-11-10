#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int  search(int** arr, int row, int col, int key, int* prow, int* pcol)
{
	int row1 = row - 1;
	int col1 = 0;
	while (row1 > -1 && col1 < col)
	{
		if (key == arr[row1][col1])
		{
			*prow = row1;
			*pcol = col1;
			return 0;
		}
		//查找成功
		else if (key > arr[row1][col1])
		{
			col1++;
		}
		//数值偏小，向右移动一行
		else
		{
			row1--;
		}
	}
	*prow = -1;
	*pcol = -1;

	//查找失败
	return 0;
}

int main()
{
	int row, col, i, j, key, prow = -1, pcol = -1;
	printf("请输入矩阵的行数与列数：\n");
	scanf("%d %d", &row, &col);
	int **arr = (int**)malloc(sizeof(int*) * row);
	for (i = 0; i < row; i++)
	{		
		arr[i] = (int*)malloc(sizeof(int) * col);
		for (j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	printf("请输入要查找的值：\n");
	scanf("%d", &key);
	search(arr, row, col, key, &prow, &pcol);
	if (-1 == prow || -1 == pcol)
		printf("查找失败，不存在该数字\n");
	else
		printf("查找到的坐标为： x:%d  y:%d", prow, pcol);
	return 0;
}