#include<stdio.h>

void move(int n,char x,char y,char z)
{
	if( 1 == n)
	{
		printf("%c-->%c\n",x,z);
	}
	else
	{
		move(n-1,x,z,y);
		printf("%c-->%c\n",x,z);
		move(n-1,y,x,z);
	}
}

int main()
{

	int n;	
	printf("�����뺺ŵ���Ĳ�����\n");	
	scanf("%d",&n);
	move(n,'X','Y','Z');
	return 0; 
}
