#include<stdio.h>
#include<malloc.h>
#include<string.h>

void _MergeSort(int *arr, int begin, int end, int *temp)
{
	if (begin >= end)
		return;

	int mid = begin + ((end - begin) >> 1);

	_MergeSort(arr, begin, mid, temp);
	_MergeSort(arr, mid + 1, end, temp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;



	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			temp[i++] = arr[begin1++];
		}
		else
		{
			temp[i++] = arr[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		temp[i++] = arr[begin1++];
	}

	while (begin2 <= end2)
	{
		temp[i++] = arr[begin2++];
	}

	memcpy(arr + begin, temp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int *arr, int n)
{
	int* temp = (int*)malloc(sizeof(int) * 20);
	_MergeSort(arr, 0, n - 1, temp);
	
	free(temp);
	temp = NULL;
}




int main()
{
	int arr[10] = { 46, 74, 53, 14, 26, 36, 86, 65, 27, 34 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	MergeSort(arr, length);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}