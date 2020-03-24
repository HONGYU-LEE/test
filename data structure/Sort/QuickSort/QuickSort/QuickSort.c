#include<stdio.h>

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Hoare法
int Hoare(int* arr, int begin, int end)
{
	int pivot = arr[end];
	int pivot_index = end;
	while (begin < end)
	{
		while (begin < end && arr[begin] <= pivot)
		{
			++begin;
		}

		while (begin < end && arr[end] >= pivot)
		{
			--end;
		}

		Swap(&arr[begin], &arr[end]);
	}

	Swap(&arr[begin], &arr[pivot_index]);

	return begin;
}


//挖坑法
int DigHole(int* arr, int begin, int end)
{
	int pivot = arr[end];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= pivot)
		{
			++begin;
		}

		arr[begin] = arr[end];

		while (begin < end && arr[end] >= pivot)
		{
			--end;
		}

		arr[end] = arr[begin];
	}

	arr[begin] = pivot;
	return begin;
}


//双指针法
int PrevCurMethod(int* arr, int begin, int end)
{
	int cur = begin, prev = begin - 1;
	int pivot = arr[end];
	while (cur < end)
	{
		if (arr[cur] < pivot && ++prev != cur)
		{
			Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	++prev;
	Swap(&arr[cur], &arr[prev]);

	return prev;
}


//递归多趟
void QuickSort(int* arr, int begin, int end)
{
	if (begin < end)
	{
		int pivot = PrevCurMethod(arr, begin, end);

		QuickSort(arr, begin, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

int main()
{
	int arr[10] = { 46, 74, 53, 14, 26, 36, 86, 65, 27, 34 };
	int length = sizeof(arr) / sizeof(arr[0]) - 1;
	int i = 0;
	QuickSort(arr, 0, length);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}