#include<stdio.h>

int  a(int x,int y)
{
	if(y == 0)
		return 1;
	return x*a(x,y-1);
}
int main()
{
	int x,y;
	printf("��������Ҫ����׳˵����֣�\n");
	scanf("%d",&x);
	printf("������η�����\n");
	scanf("%d",&y);
	printf("%d",a(x,y));
	return 0;
}
