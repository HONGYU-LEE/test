#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define LISTSIZE 10

typedef int DATATYPE;

typedef struct ListNode
{
	DATATYPE data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate();
// ˫����������
void ListDestory(ListNode* list);
// ˫�������ӡ
void ListPrint(ListNode* list);
// ˫������β��
void ListPushBack(ListNode* list, DATATYPE x);
// ˫������βɾ
void ListPopBack(ListNode* list);
// ˫������ͷ��
void ListPushFront(ListNode* list, DATATYPE x);
// ˫������ͷɾ
void ListPopFront(ListNode* list);
// ˫���������
ListNode* ListFind(ListNode* list, DATATYPE x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, DATATYPE x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);