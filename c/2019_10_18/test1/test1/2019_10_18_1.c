#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 0, arr[32] = {0}, x;
	printf("������һ�����֣�\n");
	scanf("%d", &x);
	while (i<32)
	{
		arr[i++] = (x  & 1);
		x >>= 1;

	}
	printf("������λΪ\n");
	for (i = 31; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}

	printf("\n����λΪ��\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}

	printf("\nż��λΪ��\n");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}