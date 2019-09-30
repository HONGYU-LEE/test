#include<stdio.h>
#include<stdlib.h>

int singleNumber(int* nums, int numsSize){
        int num = 0,i;
        for(i=0; i<numsSize; i++)
        {
            num ^= nums[i];
        }
        return num;
}

int main()
{	
	int numsSize,*nums,i;
	printf("请输入数组的长度:");
	scanf("%d",&numsSize); 
	nums = (int*)malloc(numsSize*sizeof(int));
	for(i=0; i<numsSize; i++)
	{
		scanf("%d",&nums[i]);
	}
	printf("%d",singleNumber(nums,numsSize)); 
	return 0;	
}


