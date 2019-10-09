#include<stdio.h>

int  jump(int n)
{
	if(n==0)
        return 0;
	else if(n<=2)
		return 1;
	else if(n>2)
		return jump(n-1) + jump(n-2); 
} 
int main()
{
	int i,n;
	printf("ÇëÊäÈëÂ¥ÌİµÄ½×Êı\n");
	scanf("%d",&n); 
	printf("%d",jump(n));
	return 0;
} 
