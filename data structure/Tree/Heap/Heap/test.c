#include "Heap.h"

int main()
{
	int arr[] = { 34, 53, 36, 46, 726, 14, 86, 65, 27, 4 };
	Heap hp;
	HeapCreate(&hp, arr, 10);
	HeapPrint(&hp);
	HeapPush(&hp, 1);
	printf("\n");
	HeapPrint(&hp);
	//printf("%d ", HeapEmpty(&hp));
	//printf("%d \n", HeapTop(&hp));
	//printf("%d \n", HeapSize(&hp));
	//HeapPop(&hp);
	//HeapPush(&hp, 45);
	//printf("\n");
	//HeapPrint(&hp);
	//HeapPush(&hp, 425);
	//HeapPush(&hp, 415);
	//HeapPush(&hp, 4);
	return 0;
}