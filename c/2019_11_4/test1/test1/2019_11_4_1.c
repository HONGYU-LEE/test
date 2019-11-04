#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	unsigned int ret = 0, i;
	for (i = 0; i < 32; i++)
	{
		ret <<= 1;
		ret |= ((value >> i) & 1);
	//	ret ^= ((value >> i) & 1);
	}
	return ret;
}

int main()
{
	unsigned int value;
	printf("请输入要反转二进制位的数字：\n");
	scanf("%u", &value);
	printf("反转后:%u\n ", reverse_bit(value));
	return 0;
}