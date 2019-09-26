#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("*****************************************\n") ;
	printf("*********      1.开始游戏       *********\n") ;
	printf("*********      0.结束游戏       *********\n") ;
	printf("*****************************************\n") ;
}
void game()
{
	int ret,guess; 
	ret = rand() % 100 +1;
	
	while(1)
	{
		printf("请输入您猜的数字\n"); 
		scanf("%d",&guess);
		
		if( ret < guess)
		{
			printf("您猜的数字偏大\n"); 
		}
		else if( ret > guess)
		{
			printf("您猜的数字偏小\n"); 
		} 
		else
		{
			printf("恭喜您猜对了\n");
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
		printf("请输入您的选择：\n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1:	
				game();
				break;
			case 0: 
				printf("结束游戏\n");
				break;
			default:
				printf("输入错误，请重新输入\n"); 
				break; 
		} 
		
	} while (n);
	
	return 0;
} 
