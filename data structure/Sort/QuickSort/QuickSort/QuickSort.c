#include"Stack.h"

//����
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//����ȡ�У��Ż�����, ��֤�м�ֵ��end��λ��
void chancePovit(int* arr, int begin, int end)
{
	int mid = ((end - begin) >> 1) + begin;

	if (arr[begin] > arr[end])
	{
		Swap(&arr[begin], &arr[end]);
	}

	if (arr[mid] < arr[begin])
	{
		Swap(&arr[mid], &arr[begin]);
	}

	if (arr[end] > arr[mid])
	{
		Swap(&arr[end], &arr[mid]);
	}
}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

// Hoare��
int Hoare(int* arr, int begin, int end)
{
	chancePovit(arr, begin, end);
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


//�ڿӷ�
int DigHole(int* arr, int begin, int end)
{
	chancePovit(arr, begin, end);
	int pivot = arr[end];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= pivot)
		{
			++begin;
		}

		arr[end] = arr[begin];
		while (begin < end && arr[end] >= pivot)
		{
			--end;
		}

		arr[begin] = arr[end];
	}

	arr[begin] = pivot;
	return begin;
}


//˫ָ�뷨
int PrevCurMethod(int* arr, int begin, int end)
{
	int cur = begin, prev = begin - 1;
	chancePovit(arr, begin, end);
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


//�ݹ����
void QuickSort(int* arr, int begin, int end)
{
	if (begin < end)
	{
		int pivot = PrevCurMethod(arr, begin, end);
		
		QuickSort(arr, begin, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
}

void QuickSort_Plus(int* arr, int begin, int end)
{
	while (begin < end)
	{
		int pivot = PrevCurMethod(arr, begin, end);

		QuickSort(arr, begin, pivot - 1);
		begin = pivot + 1;
	}
}

//�ǵݹ�
void noRecursive(int* arr, int begin, int end)
{
	Stack s;
	StackInit(&s);
	StackPush(&s, begin);
	StackPush(&s, end);

	while (!StackEmpty(&s))
	{
		//��Ϊ��ջʱ���������������������������ȳ���Ӧ�����������ٵ�������
		int right = StackTop(&s);
		StackPop(&s);

		int left = StackTop(&s);
		StackPop(&s);

		int povit = DigHole(arr, left, right);
		//��������[left][povit - 1] [povit + 1][right]
		if (left < povit)
		{
			StackPush(&s, left);
			StackPush(&s, povit - 1);
		}

		if (right > povit)
		{
			StackPush(&s, povit + 1);
			StackPush(&s, right);
		}
	}

	StackDestroy(&s);
}

int main()
{
	int arr[10] = { 46, 74, 53, 14, 26, 36, 86, 65, 27, 34 };
	int length = sizeof(arr) / sizeof(arr[0]) - 1;
	int i = 0;
	noRecursive(arr, 0, length);
	//QuickSort(arr, 0, length);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}