#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void left_revolve(char* str,int k)
{
	int i=0;
	char temp;
	k %= strlen(str);
	while (k--)
	{
		i = 0;
		temp = str[0];
		while (str[i + 1])
		{
			str[i] = str[i + 1];
			i++;
		}
		str[i] = temp;
		printf("%s\n", str);
	}
}
int main()
{
	int k;;
	char str[20];
	printf("�������ַ�����\n");
	scanf("%s", str);
	printf("�����������Ĵ���:\n");
	scanf("%d", &k);
	left_revolve(str, k);
	//printf("%s", str);
	return 0;
}