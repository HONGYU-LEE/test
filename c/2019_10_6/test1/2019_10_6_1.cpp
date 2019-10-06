#include<stdio.h>

int a(int n)
{
	if( n==1 )
		return 1;
	return n*a(n-1); 
}
int main()
{
	int n;
	printf("请输入需要计算阶乘的数：\n");
	scanf("%d",&n);
	printf("%d",a(n)); 
	return 0;
} 
