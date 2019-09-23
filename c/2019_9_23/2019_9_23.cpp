#include<stdio.h>
int main()
{	
	int i,j,z,n,k;
	printf("请输入菱形的行数:\n"); 
	scanf("%d",&k); 
	k = k / 2 +1; 
	for(i=1,n=1; i<= k; i++)
	{
		n = 2*i-1;
		for(j=k-i; j>0; j--)
		{
			printf(" ");
		}
		for(z=0; z< n; z++)
		{
			printf("*");
		}
		printf("\n");
	}
	n-=2;
	for(i=0; i<k-1; i++)
	{
		for(j=0; j<i+1; j++)
		{
			printf(" ");
		}
		for(z=n-2*i; z>0; z--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
} 
