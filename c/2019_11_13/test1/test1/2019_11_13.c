#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void left_revolve(char* str1)
{
	char temp;
	int i = 0;
	temp = str1[0];
	while (str1[i + 1])
	{
		str1[i] = str1[i + 1];
		i++;
	}
	str1[i] = temp;
}

int judge(char* str1, char* str2)
{
	int n = strlen(str1);
	if (0 == strcmp(str1, str2))
		return 1;
	else
		while (n--)
		{
			left_revolve(str1);
			if (0 == strcmp(str1, str2))
				return 1;
		}
	return 0;
}
int main()
{
	int ret;
	char str1[20], str2[20];
	printf("�������ַ�����\n");
	scanf("%s", str1);
	printf("��������Ҫ�жϵ��ַ���:\n");
	scanf("%s", str2);
	if (judge(str1, str2))
		printf("str1��str2��ת֮����ַ���\n");
	else
		printf("str1����str2��ת֮����ַ���\n");
	return 0;
}