#include<stdio.h>

int year(int years)
{
	if(years%400==0 || (years%100!=0 && years%4==0))
		return 1;
	else
		return 0;
}

int main()
{
	int years;
	printf("��������Ҫ�жϵ����:\n");
	scanf("%d",&years);
	if(year(years)==1)
		printf("����������\n");
	else
		printf("���겻������\n");
	return 0;
}
