#include<stdio.h>
int main()
{
	int i,j,z;
	printf("�������������֣�\n"); 
	scanf("%d%d",&i,&j);
	z = i;
	if(i > j)
		z = j;
	for(int max =z; max>0; max--)
			if(i%max==0 && j%max==0){
			printf("���Լ��Ϊ%d\n",max); 
				break;
			}
	return 0;
}
