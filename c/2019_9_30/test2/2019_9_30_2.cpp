#include<stdio.h>
void a(int n)
{
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=i; j++)
			printf("%dx%d=%d ",i,j,i*j); 
		printf("\n"); 
	}	
}
int main()
{	
	int n;
	printf("请输入行数和列数\n");
	scanf("%d",&n); 
	a(n);
	return 0;
}
