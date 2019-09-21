#include<stdio.h>
int main()
{
	int i,j,z;
	printf("请输入两个数字：\n"); 
	scanf("%d%d",&i,&j);
	z = i;
	if(i > j)
		z = j;
	for(int max =z; max>0; max--)
			if(i%max==0 && j%max==0){
			printf("最大公约数为%d\n",max); 
				break;
			}
	return 0;
}
