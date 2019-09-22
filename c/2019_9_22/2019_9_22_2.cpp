#include<stdio.h>
int main()
{	
	int i,j,z,n;
	//i 百位 j 十位 z 个位 
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
