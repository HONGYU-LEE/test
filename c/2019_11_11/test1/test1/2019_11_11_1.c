#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void search(int *arr, int n)
{
	int flag = 0, i, j;
	int x = 0, y = 0;
	for (i = 0; i < n; i++)
	{
		flag ^= arr[i];
	}
	i = 0;
	while (1 == flag >> i & 1)
		break;
	for (j = 0; j < n; j++)
	{
		if (1 == arr[j] >> i & 1)
			x ^= arr[j];
		else
			y ^= arr[j];
	}
	printf("只出现过两次的数字为：%d和%d\n", x, y);
}
int main()
{
	int* arr, i, n;
	printf("请输入数组的大小：\n");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	search(arr, n);
	return 0;
}