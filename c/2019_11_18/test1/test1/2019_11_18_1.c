#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

void* my_memmove(void* dst, const void* src, size_t num)
{
	assert(dst && src);
	char* dst1 = (char*)dst;
	char* src1 = (char*)src;
	size_t i;
	int j;
	if (dst1 < src1)
	{
		for (i = 0; i < num; i++)
		{
			dst1[i] = src1[i];
		}
	}
	else
	{
		for (j = num - 1; j >= 0; j--)
		{
			dst1[j] = src1[j];
		}
	}

	return dst;
}

int main()
{

	int a1[10] = { 1, 2, 3, 4, 5 };
	int a2[10] = {0};
	int i;
	my_memmove(a1, a2, 4 * sizeof(int));
	for (i = 0; i < 10; i++)
		printf("%d ", a1[i]);
	return 0;
}