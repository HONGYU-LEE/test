#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("*****************************************\n") ;
	printf("*********      1.��ʼ��Ϸ       *********\n") ;
	printf("*********      0.������Ϸ       *********\n") ;
	printf("*****************************************\n") ;
}
void game()
{
	int ret,guess; 
	ret = rand() % 100 +1;
	
	while(1)
	{
		printf("���������µ�����\n"); 
		scanf("%d",&guess);
		
		if( ret < guess)
		{
			printf("���µ�����ƫ��\n"); 
		}
		else if( ret > guess)
		{
			printf("���µ�����ƫС\n"); 
		} 
		else
		{
			printf("��ϲ���¶���\n");
			break; 
		} 
	} 
} 
int main()
{ 
	int n;
	srand((int)time(NULL)); 

	do
	{
		menu();
		printf("����������ѡ��\n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1:	
				game();
				break;
			case 0: 
				printf("������Ϸ\n");
				break;
			default:
				printf("�����������������\n"); 
				break; 
		} 
		
	} while (n);
	
	return 0;
} 
