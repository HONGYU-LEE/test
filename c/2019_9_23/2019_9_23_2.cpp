#include<stdio.h>
int Search(int right,int n,int arr[])
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
	int arr[] ={1,3,5,7,9,11,13,15,17,19};
	int n,i,right,left,mid;
	right = sizeof(arr)/sizeof(arr[0])-1;
	left =0;
	
	printf("������Ҫ���ҵ�����:");
	scanf("%d",&n);
	mid = Search(right,n,arr);
	
	if( -1 == mid )
	{
		printf("����ʧ�� ");	 
	}
	else
	{
		printf("�±�Ϊ��%d",mid);
	}
	return 0;
}
