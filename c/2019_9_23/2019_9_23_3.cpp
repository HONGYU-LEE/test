#include<stdio.h>
#include<string.h>
 
int main()
{
	int i; 	
	char str2[]={0};
	char str1[]="password";

	for(i=0; i<3; i++)
	{
		printf("���������룺\n"); 
		scanf("%s",str2);
		
		if( 0 == strcmp(str1,str2) )
		{
			printf("������ȷ������ɹ�\n");
			break; 
		}
		else
		{
			printf("�������\n"); 
		} 
	}
	
	if( 3 == i )
	{
		printf("������������˳�����\n"); 
	} 
	return 0;
} 
