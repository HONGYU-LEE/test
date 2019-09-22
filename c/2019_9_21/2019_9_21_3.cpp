#include<stdio.h>
int main()
{	
	int i,count=0;
	for(i=0 ; i<100; i++)
		if( i%9 == 0 ) 
			count++;
	printf("9出现的次数为：%d",count);
	return 0;
}
