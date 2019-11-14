#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* str1, const char* str2)
{
	assert(str1 && str2);
	char* str = str1;
	while (*str1)
	{
		str1++;
	}
	while (*str1++ = *str2++);

	*str1 = *str2;

	return str;
}
int main()
{
	char str1[20];
	char str2[20];
	printf("ÇëÊäÈë´ıÆ´½Ó×Ö·û´®:\n");
	scanf("%s", &str1);
	printf("ÇëÊäÈëÆ´½ÓµÄ×Ö·û´®:\n");
	scanf("%s", &str2);
	my_strcat(str1, str2);
	printf("%s\n", str1);
	return 0;
}