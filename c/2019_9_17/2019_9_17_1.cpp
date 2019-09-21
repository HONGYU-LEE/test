#include<stdio.h>
int main()
{
	int i,j,t;
	printf("请输入两个要交换的整形数据i和j:\n");
	scanf("%d%d",&i,&j);
	t = i;
	i = j;
	j = t;
	printf("交换后i = %d j = %d",i,j); 
	return 0;
}
