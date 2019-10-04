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
	printf("请输入需要判断的年份:\n");
	scanf("%d",&years);
	if(year(years)==1)
		printf("该年是闰年\n");
	else
		printf("该年不是闰年\n");
	return 0;
}
