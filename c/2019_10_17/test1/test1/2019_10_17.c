#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i, j, t, count=0;
	printf("������Ҫ�ж϶�����λ��ͬ����������:\n");
	scanf("%d%d", &i, &j);
	t = i ^ j;
	while (t)
	{
		t &= (t - 1);
		count++;
	}
	printf("��ͬ��λ��Ϊ��%d\n",count);
	return 0;
}
