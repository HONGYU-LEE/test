#include<stdio.h>

int swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int x,y; 
	printf("������Ҫ�������������ݣ�\n");
	scanf("%d%d",&x,&y);
	swap(&x,&y);
	printf("%d %d\n",x,y);
	return 0; 
} 
