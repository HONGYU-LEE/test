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
	int* arr1 = (int*)malloc(datasize * sizeof(int));
	int* arr2 = (int*)malloc(datasize * sizeof(int));
	printf("��һ������:\n\n");
	getsrand(arr1, datasize);
	show_arr(arr1, datasize);
	printf("\nð�������\n");
	BubbleSort(arr1, datasize);
	show_arr(arr1, datasize - 1);

	ret = BinarySearch(9, search, arr1);
	if (ret != -1)
		printf("\n�����������%d�ɹ����±�Ϊ%d\n", search, ret);
	else
		printf("\n�����������%dʧ��\n", search);

	printf("�ڶ�������:\n\n");
	getsrand(arr2, datasize);
	show_arr(arr2, datasize);
	printf("\n���������\n");
	QuickSort(arr2, datasize);
	show_arr(arr2, datasize - 1);

	ret = InsertSearch(datasize - 1, search, arr2);
	if (ret != -1)
		printf("\n�����������%d�ɹ����±�Ϊ%d\n", search, ret);
	else
		printf("\n�����������%dʧ��\n", search);

	free(arr1);
	free(arr2);

}
