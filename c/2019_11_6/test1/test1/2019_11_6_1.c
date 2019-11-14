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
	//整体翻转

	while (*right)
	{
		left = right;
		//对齐每个单词的起始位置
		while (*right != ' ' && *right != '\0')
		{
			right++;
		}
		//找到当前单词的结束位置

		reverse_str(left, right - 1);
		//翻转这个单词

		while (*right == ' ')
		{
			right++;
		}
		//找到下个单词的起始位置
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