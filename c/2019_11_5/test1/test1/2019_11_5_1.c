#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void sort(int *arr, int n)
{
	int *left = arr;
	int *right = arr + n - 1,t;
	while (left < right)
	{
		while (*left % 2 != 0)
			left++;
		while (*right % 2 == 0)
			right--;
		if (left < right)
		{
			t = *left;
			*left = *right;
			*right = t;
		}
	}
}
int main()
{
	int* arr, n, i;
	printf("请输入数组长度:\n");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}