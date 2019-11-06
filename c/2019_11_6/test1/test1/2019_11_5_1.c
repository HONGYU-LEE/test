#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

int my_strlen(const char* str)
{
	int count = 0;
	assert(str);
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

void reverse_str(char* left, char* right)
{
	int i = 0;
	char t;
	assert(left && right);
	while (left < right)
	{
		t = *left;
		*left = *right;
		*right = t;
		left++;
		right--;
	}
}

void reverse(char* str)
{
	assert(str);
	char* left = str;
	char* right = left;
	int len = my_strlen(str);
	reverse_str(str, str + len - 1);
	//���巭ת

	while (*right)
	{
		left = right;
		//����ÿ�����ʵ���ʼλ��
		while (*right != ' ' && *right != '\0')
		{
			right++;
		}
		//�ҵ���ǰ���ʵĽ���λ��

		reverse_str(left, right - 1);
		//��ת�������

		while (*right == ' ')
		{
			right++;
		}
		//�ҵ��¸����ʵ���ʼλ��
	}
}
int main()
{
	int n;
	char str[] = "student a am i";
	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);
	return 0;
}