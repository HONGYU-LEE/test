#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i, j, t, count=0;
	printf("请输入要判断二进制位不同的两个数字:\n");
	scanf("%d%d", &i, &j);
	t = i ^ j;
	while (t)
	{
		t &= (t - 1);
		count++;
	}
	printf("不同的位数为：%d\n",count);
	return 0;
}
