#include<stdio.h>
int main()
{
	int i,j,t;
	printf("����������Ҫ��������������i��j:\n");
	scanf("%d%d",&i,&j);
	t = i;
	i = j;
	j = t;
	printf("������i = %d j = %d",i,j); 
	return 0;
}
