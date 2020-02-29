#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

typedef int DataType;

typedef struct Heap
{
	DataType *data;
	int size;
	int capacity;
}Heap;

void Swap(DataType* a, DataType* b);
void AdjustDown(DataType* data, int size, int root);
//���µ����㷨
void AdjustUp(DataType* data, int child);
//���µ����㷨
void HeapCreate(Heap* hp, DataType* data, int size);
//������
void HeapDestory(Heap* hp);
//���ٶ�
void HeapPush(Heap* hp, DataType x);
//���
void HeapPop(Heap* hp);
//����
int HeapSize(Heap* hp);
//�ѵ����ݸ���
int HeapEmpty(Heap* hp);
//�ж϶��Ƿ�Ϊ��
void HeapPrint(Heap* hp);
//��ʾ��
DataType HeapTop(Heap* hp);
//ȡ�Ѷ�����

