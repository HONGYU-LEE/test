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
	//�����ж��ٸ��ո�
	newlength = length + 2 * count;
	//�õ��޸ĺ�����鳤��
	newend = newlength - 1;
	//�ҵ���β
	while (end)
	{
		if (' ' == str[end])
		{
			str[newend--] = '0';
			str[newend--] = '2';
			str[newend--] = '%';
			end--;
		}
		//��Ϊ�ո��ʱ���޸�Ϊ%20
		else
		{
			str[newend--] = str[end--];
		}
		//��Ϊ�ո��ʱ�򿽱�����
	}
	//����Ҫ��֤�������㹻��Ŀռ䣬��Ϊ����Ľ�β���½�β���� 2 * count ��Ԫ�أ����������������λ�ò���ԭ�����Ͻ���ֱ���滻
}

int main()
{
	char str[30] = "THIS IS TEST DATA";
	test(str, strlen(str));
	printf("%s\n", str);
	return 0;
}