#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num = 0, i, n,*arr;
	printf("����������Ԫ�ظ�����\n");
	scanf("%d", &n);
	printf("���������飺\n");
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0;i < n;i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0;i < n;i++)
	{
		num ^= arr[i];
	}
	printf("%d\n",num);
	return 0;
}