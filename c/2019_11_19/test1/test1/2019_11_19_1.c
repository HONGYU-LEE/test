#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

char* my_strchr(const char* str,const char c)
{
	assert(str);
	while (*str)
	{
		if (*str == c)
			return str;
		else
			str++;
	}
	return NULL;
}
int main()
{
	char str[12] = "hello world";
	char c;
	char* ret;
	printf("������Ҫ������һ�γ���λ�õ��ַ�:\n");
	scanf("%c", &c);

	ret = my_strchr(str, c);
	if (ret)
	{
		printf("%s", ret);
	}
	else
	{
		printf("���ַ�������\n");
	}
	return 0;
}