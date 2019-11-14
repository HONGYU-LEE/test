#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
void* my_memcpy(void* dst, const void* src, size_t num)
{
	assert(dst && src);
	char* dst1 = (char*)dst;
	char* src1 = (char*)src;
	size_t i;
	for (i = 0; i < num; i++)
	{
		dst1[i] = src1[i];
	}
	return dst;
}
int main()
{
	int a1[5] = { 1, 3, 5, 7, 9 };
	int a2[5] = { 2, 4, 6, 8, 10 };
	int i;
	my_memcpy(a2, a1, 4 * sizeof(int));
	for (i = 0; i < 5; i++)
		printf("%d ", a2[i]);
}