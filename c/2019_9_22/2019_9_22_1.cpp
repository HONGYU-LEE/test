#include<stdio.h>
int main()
{	
	int i,j,z,n;
	for(i=1,n=1; i<=7; i++)
	{
		n = 2*i-1;
		for(j=7-i; j>0; j--)
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
	for(i=0; i<6; i++)
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
