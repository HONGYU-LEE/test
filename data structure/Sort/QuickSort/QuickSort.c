#include<stdio.h>

void Swap(int* i, int* j)
{
	int temp;
	temp = 	*i;
	*i = *j;
	*j = temp;
}

void Qsort(int* arr, int low, int high)
{
	int pivot;	
	if (low < high)
	{
		pivot = Partition(arr, low, high);
		
		Qsort(arr, low, pivot - 1);
		Qsort(arr, pivot + 1, high);
	}
}



int Partition(int* arr, int low, int high)
{
	int pivotkey;
	pivotkey = arr[low]; 
	
	while (low < high)
	{
		while (low < high && arr[high] >= pivotkey)
		{
			high--;
		}
		Swap(&arr[low], &arr[high]);
		
		while (low <high && arr[low] <= pivotkey)
		{
			low++;
		}
		Swap(&arr[low], &arr[high]);
	}
	
	return low;
}

void QuickSort(int* arr, int length)
{
	Qsort(arr, 0, length);
} 

int main()
{
	int arr[10] = {46, 74, 53, 14, 26, 36, 86, 65, 27, 34};
	int length = sizeof(arr) / sizeof(arr[0]) - 1;
	int i = 0;
	QuickSort(arr, length); 
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
