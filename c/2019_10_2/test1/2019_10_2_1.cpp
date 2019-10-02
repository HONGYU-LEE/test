#include<stdio.h>

int  a(int x,int y)
{
	if(y == 0)
		return 1;
	return x*a(x,y-1);
}
int main()
{
	int x,y;
	printf("请输入需要计算阶乘的数字：\n");
	scanf("%d",&x);
	printf("请输入次方数：\n");
	scanf("%d",&y);
	printf("%d",a(x,y));
	return 0;
}
