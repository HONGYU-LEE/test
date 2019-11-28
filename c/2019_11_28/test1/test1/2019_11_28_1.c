#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void test(char* str, int length)
{
	int count = 0, newlength, end = length - 1, newend, i;
	for (i = 0; i < length; i++)
	{
		if (' ' == str[i])
			count++;
	}
	//计算有多少个空格
	newlength = length + 2 * count;
	//得到修改后的数组长度
	newend = newlength - 1;
	//找到结尾
	while (end)
	{
		if (' ' == str[end])
		{
			str[newend--] = '0';
			str[newend--] = '2';
			str[newend--] = '%';
			end--;
		}
		//当为空格的时候修改为%20
		else
		{
			str[newend--] = str[end--];
		}
		//不为空格的时候拷贝数据
	}
	//必须要保证数组有足够大的空间，因为数组的结尾和新结尾差了 2 * count 个元素，所以我们利用这个位置差在原数组上进行直接替换
}

int main()
{
	char str[30] = "THIS IS TEST DATA";
	test(str, strlen(str));
	printf("%s\n", str);
	return 0;
}