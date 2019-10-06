#include<stdio.h>
int main()
{
	int i,n,sum=1;
	printf("ÇëÊäÈëÒª½×³ËÊı:\n");
	scanf("%d",&n);
	while(n>0)
	{
		sum *= n;
		n--;
	}
	printf("%d",sum); 
	return 0;
} 
