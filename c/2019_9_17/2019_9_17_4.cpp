#include<stdio.h>
int main()
{
	int i,j,z;
	printf("请输入三个数字：\n"); 
	scanf("%d%d%d",&i,&j,&z);
	if( i<j ){
		i^=j;
		j^=i;
		i^=j;
	} 
	if( i<z ){
		i^=z;
		z^=i;
		i^=z;
		
	}
	if( j<z ){
		j^=z;
		z^=j;
		j^=z;
		
	}
	printf("排序后:%d %d %d：",i,j,z);
	return 0;
}
