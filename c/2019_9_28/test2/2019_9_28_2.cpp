#include<stdio.h>

int  jump(int n)
{
	int a=1,b=2,c;
	if( n == 1 )
		return a;
	else if( n == 2 )
		return b;
	while(n-->2)
	{
		c = a+b;
		a = b;
		b = c;
	} 
	return c;

} 
int main()
{
	int i,n;
	printf("ÇëÊäÈëÂ¥ÌİµÄ½×Êı:\n");
	scanf("%d",&n); 
	printf("%d",jump(n));
	return 0;
} 
