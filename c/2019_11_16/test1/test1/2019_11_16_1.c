#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int my_strcmp(const char* str1, const char* str2)
{
	unsigned char* s1 = (unsigned char* )str1;
	unsigned char* s2 = (unsigned char* )str2;

	while (*s1 && *s2)
	{
		if (*s1 < *s2)
			return -1;
		else if (*s1 > *s2)
			return 1;
		else
		{
			s1++;
			s2++;
		}
	}
	
	if ('\0' == *s1 && '\0' == *s2)
		return 0;
	else if ('\0' == *s1)
		return -1;
	else
		return 1;
}

int main()
{
	char str1[] = "aello";
	char str2[] = "bello";

	printf("%d\n", my_strcmp(str1, str2));
	return 0;
}