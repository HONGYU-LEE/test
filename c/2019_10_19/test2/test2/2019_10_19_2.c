#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

char* my_strcpy(char* dest, const char* src)
{
	char* str = dest;
	assert(dest && src);
	while (*dest++ = *src++)
	{
		;
	}
	return dest;
}

int main()
{
	char dest[20] = "hello";
	char src[20] = "hello world";
	my_strcpy(dest, src);
	printf("%s\n", dest);
	return 0;
}