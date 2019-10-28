#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void print(int n)
{
	if (n > 9)
		print(n / 10);
	printf("%d ", n % 10);
}
int main()
{
	int n;
	printf("请输入n的数值\n");
	scanf("%d", &n);
	print(n);
	return 0;
}