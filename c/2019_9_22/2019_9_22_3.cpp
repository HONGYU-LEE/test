#include<stdio.h>
int main()
{
	int a[5]={0},i,j,sum=0;
	printf("������n����ֵ��\n");
	scanf("%d",&a[0]);
	sum += a[0];
	for(i=1; i<5; i++)
	{	
		a[i] =  a[i-1] * 10 + a[0] ;
		sum += a[i];
	} 
	printf("���Ϊ%d",sum); 
	return 0;
}
