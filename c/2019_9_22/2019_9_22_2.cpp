#include<stdio.h>
int main()
{	
	int i,j,z,n;
	//i ��λ j ʮλ z ��λ 
	for(n =0; n<=999; n++)
	{
		i = n / 100;
		z = n % 10;
		j = n /10 %10;
		if(n == i*i*i + j*j*j + z*z*z)
		{
			printf("%d ",n);
		} 
	}
	return 0;
} 
