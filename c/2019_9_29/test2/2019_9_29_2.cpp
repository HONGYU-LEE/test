#include<stdio.h>

int fib(int N) 
{
    int a=0,b=1,c=1;
    if( N==0)
        return 0;
    if( N==1 )
        return 1;
	if(N>1)
		return fib(N-1) + fib(N-2); 
}
int main()
{
	int i,n;
	printf("请输入斐波那契的阶数:\n");
	scanf("%d",&n); 
	printf("%d",fib(n));
	return 0;
} 


