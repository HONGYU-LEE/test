#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

int my_strncmp(const char* dst, const char* src, int num)
{
	assert(dst && src);
	unsigned char* dst1 = (unsigned char*)dst;
	unsigned char* src1 = (unsigned char*)src;
	while (*dst1 && *src1 && num)
	{
		if (*dst1 < *src1)
			return -1;
		else if (*dst1 > * src1)
			return 1;
		else
		{
			dst1++;
			src1++;
			num--;
		}
	}
	if ('\0' != *dst1 && '\0' == *src1)
		return 1;
	if ('\0' == *dst1 && '\0' != *src1)
		return -1;
	else
		return 0;
}
int main()
{
	char str1[10] = "aaabo";
	char str2[10] = "aaaad";
	int ret = my_strncmp(str1, str2, 3);

	printf("%d\n", ret);
	return 0;
}