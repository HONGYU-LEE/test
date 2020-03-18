#include<stdio.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
} 

void Double_SelectSort(int *arr, int n)
{
	int begin = 0, end = n - 1, i;
	
	while(begin < end)
	{
		int min = begin, max = end;
		
		for(i = begin; i <= end; ++i)
		{
			if(arr[max] < arr[i])
				max = i;
			
			if(arr[min] > arr[i])
				min = i;
		}
		
		swap(&arr[begin], &arr[min]);
		
		if(begin == max)
			max = min;
		
		swap(&arr[end], &arr[max]);
			
		++begin;
		--end;
	}
}

int main()
{
	int arr[] = {46, 74, 53, 14, 26, 36, 86, 65, 27, 34};
//	int arr[] = {34, 53, 36, 46, 726, 14, 86, 65, 27, 4};
	int length = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	Double_SelectSort(arr, length);
	for(i = 0; i < length; i++)  
	{
		printf("%d ", arr[i]);
	}
	return 0;
} 
