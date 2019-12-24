#define _CRT_SECURE_NO_WARNINGS
#include"Search and Sort.h"



void getsrand(int* arr, int nums)
{
	int i = 0;
	while (i < nums)
	{
		arr[i++] = rand() % 200 + 1;
	}
}

void show_arr(int* arr, int nums)
{
	int i;
	printf("数据为\n");
	for (i = 0; i < nums; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	srand((int)time(NULL));
	int search = rand() % 200 + 1;
	int ret;
	int* arr1 = (int*)malloc(100 * sizeof(int));
	int* arr2 = (int*)malloc(100 * sizeof(int));
	printf("第一次数据:\n\n");
	getsrand(arr1, 100);
	show_arr(arr1, 100);
	printf("\n冒泡排序后\n");
	BubbleSort(arr1, 100);
	show_arr(arr1, 99);

	ret = BinarySearch(99, search, arr1);
	if (ret != -1)
		printf("\n查找随机数字%d成功，下标为%d\n", search, ret);
	else
		printf("\n查找随机数字%d失败\n", search);

	printf("第二次数据:\n\n");
	getsrand(arr2, 100);
	show_arr(arr2, 100);
	printf("\n快速排序后\n");
	QuickSort(arr2, 100);
	show_arr(arr2, 99);

	ret = InsertSearch(99, search, arr2);
	if (ret != -1)
		printf("\n查找随机数字%d成功，下标为%d\n", search, ret);
	else
		printf("\n查找随机数字%d失败\n", search);

	free(arr1);
	free(arr2);

}
