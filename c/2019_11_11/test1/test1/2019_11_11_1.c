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
	printf("ֻ���ֹ����ε�����Ϊ��%d��%d\n", x, y);
}
int main()
{
	int* arr, i, n;
	printf("����������Ĵ�С��\n");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	search(arr, n);
	return 0;
}