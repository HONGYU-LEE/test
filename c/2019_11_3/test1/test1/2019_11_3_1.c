#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	unsigned int ret = 0, i;
	for (i = 0; i < 32; i++)
	{
		ret += ((value >> i) & 1) * pow(2, 31 - i);
	}
	return ret;
}

int main()
{
	unsigned int value;
	printf("������Ҫ��ת������λ�����֣�\n");
	scanf("%u", &value);
	printf("��ת��:%u\n ", reverse_bit(value));
	return 0;
}