#include<stdio.h>

void ShellSort(int* arr, int n)
{
	int i, j, temp;
	int gap = n;
	do
	{
		gap = gap / 3 + 1;
		//…Ë÷√‘ˆ¡ø 
		for (i = gap; i < n; i++)
		{
			if (arr[i] < arr[i - gap])
			{
				temp = arr[i];
				
				for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
				{
					arr[j + gap] = arr[j];
				}
				
				arr[j + gap] = temp;
			} 
		}
				
	} while (gap > 1);
}

int main()
{
	int arr[10] = {46, 74, 53, 14, 26, 36, 86, 65, 27, 34};
	int length = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	ShellSort(arr, length); 
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
