#define _CRT_SECURE_NO_WARNINGS
#include"Double-linked circular list.h"
void test()
{
	ListNode* list = ListCreate();
	//ListPushFront(list, 1);
	//ListPushFront(list, 2);
	//ListPushFront(list, 3);
	//ListPushFront(list, 4);


	//ListPushBack(list, 1);
	//ListPushBack(list, 2);
	//ListPushBack(list, 3);
	//ListPushBack(list, 4);

	ListInsert(list, 1);
	ListPrint(list);
	ListInsert(list, 2);
	ListPrint(list);
	ListInsert(list, 3);
	ListPrint(list);
	ListInsert(list, 4);
	ListPrint(list);

	//ListPopBack(list);
	ListErase(list->prev);
	ListPrint(list);
	ListErase(list->prev);
	ListPrint(list);
	ListErase(list->prev);
	ListPrint(list);
	ListErase(list->prev);
	ListPrint(list);
}

int main()
{
	test();
	return 0;
}