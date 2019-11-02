#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Average(int a, int b)
{
	return (a & b) + ((a ^ b) >> 1);
}
int main()
{
	int a, b;
	printf("请输入要计算平均数的两个数字：\n");
	scanf("%d %d", &a, &b);
	printf("平均数为：%d\n", Average(a, b));
	return 0;
}