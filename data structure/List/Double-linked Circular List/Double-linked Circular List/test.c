#define _CRT_SECURE_NO_WARNINGS
#include"Double-linked circular list.h"
void test()
{
	ListNode* list = ListCreate();
	printf("ͷ��\n");
	ListPushFront(list, 1);
	ListPrint(list);
	ListPushFront(list, 2);
	ListPrint(list);
	ListPushFront(list, 3);
	ListPrint(list);
	ListPushFront(list, 4);
	ListInsert(list->next, 5);
	ListPrint(list);
	//printf("ͷɾ\n");
	//ListPopFront(list);
	//ListPrint(list);
	//ListPopFront(list);
	//ListPrint(list);
	//ListPopFront(list);
	//ListPrint(list);
	//ListPopFront(list);
	//ListPrint(list);
	//printf("β��\n");
	//ListPushBack(list, 1);
	//ListPrint(list);
	//ListPushBack(list, 2);
	//ListPrint(list);
	//ListPushBack(list, 3);
	//ListPrint(list);
	//ListPushBack(list, 4);
	//ListPrint(list);
	//printf("βɾ\n");
	//ListPopBack(list);
	//ListPrint(list);
	//ListPopBack(list);
	//ListPrint(list);
	//ListPopBack(list);
	//ListPrint(list);
	//ListPopBack(list);
	//ListPrint(list);
}

int main()
{
	test();
	return 0;
}