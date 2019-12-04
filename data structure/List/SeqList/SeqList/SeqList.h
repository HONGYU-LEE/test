#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define DATATYPE int 
#define LISTSIZE 10

typedef struct SeqList
{
	DATATYPE* data; // ָ��̬���ٵ�����
	size_t size;    // ��Ч���ݸ���
	size_t capicity;  // �����ռ�Ĵ�С
}SeqList;

void SeqListInit(SeqList* list, size_t capacity);
int CheckCapacity(SeqList* list);
void SeqListDestory(SeqList* list);
void SeqListPrint(SeqList* list);
void SeqListPushBack(SeqList* list, DATATYPE x);
void SeqListPushFront(SeqList* list, DATATYPE x);
int SeqListFind(SeqList* list, DATATYPE x);
void SeqListPopBack(SeqList* list);
void SeqListPopFront(SeqList* list);
void SeqListInsert(SeqList* list, size_t pos, DATATYPE x);
void SeqListErase(SeqList* list, size_t pos);