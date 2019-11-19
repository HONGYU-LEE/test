#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

size_t my_strlen(const char* p)
{
	size_t count = 0;
	assert(p != NULL);
	while (*p)
	{
		count++;
		p++;
	}
	return count;
}
int main()
{
	int len = 0;
	char arr[] = "hello world";
	len = my_strlen(arr);
	printf("%d", len);
	return 0;
}