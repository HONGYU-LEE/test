#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

char* my_strncat(char* dst, const char* src, int num)
{
	assert(dst && src);
	char* dst1 = dst;
	int i;
	while (*dst1)
	{
		dst1++;
	}
	for (i = 0; i < num; i++)
	{
		*dst1++ = *src++ ;
	
	}
	*dst1 = '\0';

	return dst;
}
int main()
{
	char str1[20] = "hello";
	char str2[10] = "world";
	my_strncat(str1, str2, 5);
	printf("%s\n", str1);
	return 0;
}