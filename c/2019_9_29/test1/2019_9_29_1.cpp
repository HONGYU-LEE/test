#include<stdio.h>

int tribonacci(int n) 
{
    int t1=0,t2=1,t3=1,t;
    if(n==0)
        return 0;
    else if(n<=2)
        return 1;
    while(n-->2)
    {
        t = t1 + t2 + t3;
        t1 = t2;
        t2 = t3;
        t3 = t;
    }
    return t;
}

int main()
{
	int i,n;
	printf("请输入泰波那契数的阶数:\n");
	scanf("%d",&n); 
	printf("%d",tribonacci(n));
	return 0;
} 

