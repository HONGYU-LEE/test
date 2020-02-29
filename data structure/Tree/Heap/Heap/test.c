#include "Heap.h"

int main()
{
	int arr[] = {16, 72, 31, 23, 94, 53};
	Heap hp;
	HeapCreate(&hp, arr, 6);
	HeapPrint(&hp);
	//printf("%d ", HeapEmpty(&hp));
	//printf("%d \n", HeapTop(&hp));
	//printf("%d \n", HeapSize(&hp));
	HeapPop(&hp);
	HeapPush(&hp, 45);
	printf("\n");
	HeapPrint(&hp);
	HeapPush(&hp, 425);
	HeapPush(&hp, 415);
	HeapPush(&hp, 4);
	return 0;
}