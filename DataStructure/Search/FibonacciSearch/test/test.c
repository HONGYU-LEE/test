#include<stdio.h>
#define MAXSIZE 100
void GitFib(int* fib)
{
	int i;
	fib[0] = 0;
	fib[1] = 1;
	for(i = 2; i < MAXSIZE; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
} 
int FibonacciSearch(int *a,int n,int key)
{
	int i,mid,low=0,high= n ,k=0;
	int fib[MAXSIZE] = {0};
	GitFib(fib); 
	while (n > fib[k] - 1)
	{
		k++;
	}
	//�ҳ�n��쳲��������е�λ�� 
	for (i = n; i<fib[k] -1; i++)
	{
		a[i] = a[n];
	}
	//��ȫ���� 
	while (low <= high)
	{
		mid = low + fib[k-1] - 1;
		if (key <= a[mid])
		{
			high = mid - 1;
			k -= 1;
		}
		else if (key > a[mid])
		{
			low = mid + 1;
			k -= 2;
		}
		else
		{
			if (mid <= n)
				return mid;
			else
				return n; 
		}
	}
}
int main()
{
	int a[] ={1,3,5,7,9,11,13,15,17,19};
	int key,i,n;
	n = sizeof(a)/sizeof(a[0])-1;
	printf("������Ҫ���ҵ�����:");
	scanf("%d",&key);
	printf("%d\n",FibonacciSearch(a,n,key));
	
	return 0;
}
