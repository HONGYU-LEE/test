#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 0, arr[32] = {0}, x;
	printf("请输入一个数字：\n");
	scanf("%d", &x);
	while (i<32)
	{
		arr[i++] = (x  & 1);
		x >>= 1;

	}
	printf("二进制位为\n");
	for (i = 31; i >= 0; i--)
	{
		printf("%d ", arr[i]);
	}

	printf("\n奇数位为：\n");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}

	printf("\n偶数位为：\n");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}