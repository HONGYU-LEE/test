#include<stdio.h>

int count_one_bits(unsigned int value)
{
	int count = 0;
	while(value>0)
	{
		count++;
		value &= (value-1);
	}
	return count;
}


int main()
{
	unsigned int value;
	printf("请输入数字：\n"); 
	scanf("%d",&value);
	printf("数字：%d的二进制中有%d个1",value,count_one_bits(value)); 
	return 0;
} 
