#include<stdio.h>
#include<math.h>
int a(int i)
{
	int j;
	for( j=2; j<=sqrt(i); j++)
	{ 
		if( 0 == i%j )
		{
			break;
		}
	}
	return j;
}

int main()
{	
	int i,j;
	printf("������Ҫ�жϵ����֣�\n");
	scanf("%d",&i);
	j = a(i); 
	printf("%d\n",j); 
	if( j > sqrt(i) )
	{
		printf("%d������\n",i); 
	}
	else
	{
		printf("%d��������\n",i); 		
	}
	return 0;
} 
