#include<stdio.h>
int main()
{
	char a[50];
	int i=0,count=0;
	gets(a);
	while(a[i] != '\0')
	{
		count++;
		i++;		
	}		
	printf("字符串的元素个数为：%d\n",count);
	return 0; 
}
