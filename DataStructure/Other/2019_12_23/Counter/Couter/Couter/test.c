#define _CRT_SECURE_NO_WARNINGS
#include"couter.h"
int main()
{
	char s1[MaxSize];			
	char s2[MaxSize];			
	printf("��������ʽ:");
	scanf("%s", s1);

	Trans(s1, s2);				

	printf("������Ϊ: %f", Calculate(s2));	


	return 0;
}

