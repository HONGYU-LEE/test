#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Average(int a, int b)
{
	return (a & b) + ((a ^ b) >> 1);
}
int main()
{
	int a, b;
	printf("������Ҫ����ƽ�������������֣�\n");
	scanf("%d %d", &a, &b);
	printf("ƽ����Ϊ��%d\n", Average(a, b));
	return 0;
}