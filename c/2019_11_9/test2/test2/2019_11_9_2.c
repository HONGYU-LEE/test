#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void reverse_str(char* left, char* right)
{
	char temp;
	while (left < right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

void left_revolve(char* str, int key)
{
	int len = strlen(str);
	reverse_str(str, str + key - 1);
	reverse_str(str + key, str + len - 1);
	reverse_str(str, str + len - 1);
	
}

int main()
{
	int k;;
	char str[20];
	printf("ÇëÊäÈë×Ö·û´®£º\n");
	scanf("%s", str);
	printf("ÇëÊäÈë×óÐýµÄ´ÎÊý:\n");
	scanf("%d", &k);
	k %= strlen(str);
	left_revolve(str, k);
	printf("%s", str);
	return 0;
}