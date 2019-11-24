#include<stdio.h>

void InsertSort(int* arr, int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			temp = arr[i];
			for (j = i - 1; arr[j] > temp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		} 
	}
}

int main()
{
	int arr[10] = {46, 74, 53, 14, 26, 36, 86, 65, 27, 34};
	int length = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	InsertSort(arr, length); 
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
