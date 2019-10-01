#include<stdio.h>
#include<math.h> 
int main()
{
	int i,j,count=0;
	for( i=1; i<=200; i++)
	{
		for( j=2; j<=sqrt(i); j++)
		{ 
			if( 0 == i%j )
			{
				break;
			}
		}
		if( j > sqrt(i) )
		{
			printf("%d ",i);
			count++;
		}
	}
	printf("\n素数的个数为：%d个",count); 
	return 0;
}
