#include<stdio.h>
int main()
{
	int a[10],max;
	printf("请输入十个数据:\n"); 
	for(int i=0; i<10; i++){
	scanf("%d",&a[i]);
	}
	max = a[0];
	for(int j=1; j<10; j++)
		if(a[j] > max)
			max =a[j];
	printf("max的数值为:%d",max);
	return 0;
}
