#include<stdio.h>
int main()
{	
	int i,count=0;
	for(i=0 ; i<100; i++)
		if( i%9 == 0 ) 
			count++;
	printf("9���ֵĴ���Ϊ��%d",count);
	return 0;
}
