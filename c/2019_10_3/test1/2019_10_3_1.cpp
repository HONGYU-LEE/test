#include<stdio.h>
void print(int n)
{
	if( n/10 !=0)
	{ 
		print(n/10);	 
		printf("%d ",n%10);
	}
	else
		printf("%d ",n); 
}
int main()
{
	int n;
	printf("请输入n的数值\n");
	scanf("%d",&n); 
	print(n);
	return 0;
}
