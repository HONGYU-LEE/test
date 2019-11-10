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
		//���ҳɹ�
		else if (key > arr[row1][col1])
		{
			col1++;
		}
		//��ֵƫС�������ƶ�һ��
		else
		{
			row1--;
		}
	}
	*prow = -1;
	*pcol = -1;

	//����ʧ��
	return 0;
}

int main()
{
	int row, col, i, j, key, prow = -1, pcol = -1;
	printf("����������������������\n");
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
	printf("������Ҫ���ҵ�ֵ��\n");
	scanf("%d", &key);
	search(arr, row, col, key, &prow, &pcol);
	if (-1 == prow || -1 == pcol)
		printf("����ʧ�ܣ������ڸ�����\n");
	else
		printf("���ҵ�������Ϊ�� x:%d  y:%d", prow, pcol);
	return 0;
}