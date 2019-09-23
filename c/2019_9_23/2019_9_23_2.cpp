#include<stdio.h>
int Binary_Search(int right,int n,int arr[])
{
	int left =0,mid;
	while(left <= right)
	{
		mid = (right + left) / 2;
		if( n > arr[mid] )
		{
			left = mid + 1; 
		} 
		else if( n < arr[mid])
		{
			right = mid - 1;
		}
		else if( n == arr[mid])
		{
			return mid;
		}
	}
	
	if(left > right)
	{
		return -1;
	}
}
int main()
{
	int arr[] ={1,2,3,4,5,6,7,8,9,10};
	int n,i,right,left,mid;
	right = sizeof(arr)/sizeof(arr[0])-1;
	left =0;
	
	printf("请输入要查找的数据:");
	scanf("%d",&n);
	mid = Binary_Search(right,n,arr);
	
	if( -1 == mid )
	{
		printf("查找失败 ");	 
	}
	else
	{
		printf("下标为：%d",mid);
	}
	return 0;
}
