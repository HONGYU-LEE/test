#include<stdio.h>
int main()
{
	char a[50];
	int i=0,count=0;
	gets(a);
	while(a[i] != '\0')
	{
		count++;
		i++;		
	}		
	printf("�ַ�����Ԫ�ظ���Ϊ��%d\n",count);
	return 0; 
}
