#include<stdio.h>

int a(int n)
{
	if( n==1 )
		return 1;
	return n*a(n-1); 
}
int main()
{
	int n;
	printf("��������Ҫ����׳˵�����\n");
	scanf("%d",&n);
	printf("%d",a(n)); 
	return 0;
} 
