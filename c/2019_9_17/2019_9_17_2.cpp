#include<stdio.h>
int main()
{
	int i,j;
	printf("����������Ҫ��������������i��j:\n");
	scanf("%d%d",&i,&j);
	i ^= j;
	j ^= i;
	i ^= j;
	printf("������i = %d j = %d",i,j); 
	return 0;
}
