#include<stdio.h>
int main()
{
	int a[5]={0},i,j,sum=0;
	printf("请输入n的数值：\n");
	scanf("%d",&a[0]);
	sum += a[0];
	for(i=1; i<5; i++)
	{	
		a[i] =  a[i-1] * 10 + a[0] ;
		sum += a[i];
	} 
	printf("结果为%d",sum); 
	return 0;
}
