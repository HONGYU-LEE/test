#include<stdio.h>
int main()
{
	int i,j;
	printf("请输入两个要交换的整形数据i和j:\n");
	scanf("%d%d",&i,&j);
	i ^= j;
	j ^= i;
	i ^= j;
	printf("交换后i = %d j = %d",i,j); 
	return 0;
}
