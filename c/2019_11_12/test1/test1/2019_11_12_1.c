#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int total = 20, bottle = 20, empty = 20, t;
	while (bottle)
	{
		bottle = empty / 2;
		//��ƿ�ܻ�����ƿ
		t = empty % 2;
		//��ʣ�µĿ�ƿ
		empty = bottle + t;
		//��ʣ�µĺ͸պ����
		total += bottle;
	}
	printf("�����Ժ�%dƿ����\n",total);
	return 0;
}