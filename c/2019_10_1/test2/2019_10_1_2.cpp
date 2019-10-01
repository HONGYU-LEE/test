#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
void init(int n,int *p)
{
	int i;
	printf("请输入数组元素：\n"); 
	for(i=0; i<n; i++)
	{
		scanf("%d",&p[i]);
	}
}
void empty(int n,int *p)
{

	memset(p, 0, n*sizeof(p[0]));	
} 
void reverse(int n,int *p)
{
	int t,right,i;
	right = n-1;
	for(i=0; i< n/2; i++)
	{
		t = p[i];
		p[i] = p[right-i];
		p[right-i] = t;
	}
}
void show(int n,int *p)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ",p[i]);
	}	
}
int main()
{
	int n,*p;
	printf("请输入数组的长度：\n");
	scanf("%d",&n);
	p = (int *)malloc(n*sizeof(int));
	empty(n,p);
	init(n,p);
	reverse(n,p); 
	show(n,p);
	return 0;
} 
