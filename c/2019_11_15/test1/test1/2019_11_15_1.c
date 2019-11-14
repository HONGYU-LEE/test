#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

char* my_strstr(const char* src, const char* sub)
{
	assert(src && sub);
	const char* src1 = src;
	const char* sub1 = sub;

	while (*src1)
	{
		while (*src1 == *sub1 && *sub1)
		{
			src1++;
			sub1++;
		}
		if ('\0' == *sub1)
		{
			return src;
		}
		else
		{
			sub1 = sub;
			src1 = ++src;
		}
	}
	return NULL;

}
int main()
{
	char *str1 = "aaab";
	char *str2 = "aaaabcd";

	if(NULL == my_strstr(str2, str1))
		printf("%s 不是 %s 的子串\n", str1, str2);
	else
		printf("%s 是 %s 的子串\n", str1, str2);
	return 0;
}
