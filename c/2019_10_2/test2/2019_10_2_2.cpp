#include<stdio.h>
int DigitSum(int n)
{
	if( n/10 ==0)
		return n%10;
	else
	return n%10+DigitSum(n/10);
}
int main()
{
	int n;
	printf("������n����ֵ\n");
	scanf("%d",&n); 
	printf("%d\n",DigitSum(n));
	return 0;
}
