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
	printf("\n�����ĸ���Ϊ��%d��",count); 
	return 0;
}
