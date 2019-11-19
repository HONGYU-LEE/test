#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

char* my_strcpy(char* dst, const char* src)
{
	char* str = dst;
	assert(dest && src);
	while (*dest++ = *src++);

	return str;
}

int main()
{
	char dest[20] = "hello";
	char src[20] = "hello world";
	my_strcpy(dest, src);
	printf("%s\n", dest);
	return 0;
}