#include<stdio.h>
int main()
{
	int i,j,z;
	printf("�������������֣�\n"); 
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
	printf("�����:%d %d %d��",i,j,z);
	return 0;
}
