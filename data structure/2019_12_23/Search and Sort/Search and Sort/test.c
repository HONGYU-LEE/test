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
	printf("����Ϊ\n");
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
	printf("��һ������:\n\n");
	getsrand(arr1, 100);
	show_arr(arr1, 100);
	printf("\nð�������\n");
	BubbleSort(arr1, 100);
	show_arr(arr1, 99);

	ret = BinarySearch(99, search, arr1);
	if (ret != -1)
		printf("\n�����������%d�ɹ����±�Ϊ%d\n", search, ret);
	else
		printf("\n�����������%dʧ��\n", search);

	printf("�ڶ�������:\n\n");
	getsrand(arr2, 100);
	show_arr(arr2, 100);
	printf("\n���������\n");
	QuickSort(arr2, 100);
	show_arr(arr2, 99);

	ret = InsertSearch(99, search, arr2);
	if (ret != -1)
		printf("\n�����������%d�ɹ����±�Ϊ%d\n", search, ret);
	else
		printf("\n�����������%dʧ��\n", search);

	free(arr1);
	free(arr2);

}
