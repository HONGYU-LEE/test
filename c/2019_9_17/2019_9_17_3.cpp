#include<stdio.h>
int main()
{
	int a[10],max;
	printf("������ʮ������:\n"); 
	for(int i=0; i<10; i++){
	scanf("%d",&a[i]);
	}
	max = a[0];
	for(int j=1; j<10; j++)
		if(a[j] > max)
			max =a[j];
	printf("max����ֵΪ:%d",max);
	return 0;
}
