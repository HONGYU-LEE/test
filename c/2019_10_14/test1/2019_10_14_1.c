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
	printf("���������֣�\n"); 
	scanf("%d",&value);
	printf("���֣�%d�Ķ���������%d��1",value,count_one_bits(value)); 
	return 0;
} 
