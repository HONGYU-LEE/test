#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DataType;
typedef struct {
	DataType* queue;
	int front;
	int rear;
	int length;
} CircularQueue;

CircularQueue* CircularQueueCreate(int k);
//ѭ�����г�ʼ��
bool CircularQueueEnQueue(CircularQueue* obj, DataType value);
//ѭ���������
bool myCircularQueueDeQueue(CircularQueue* obj);
//ѭ�����г���
DataType CircularQueueFront(CircularQueue* obj);
//��ȡѭ�����ж���
DataType CircularQueueRear(CircularQueue* obj);
//��ȡѭ�����ж�β
int CircularQueueSize(CircularQueue* obj);
//ѭ�����г���
bool CircularQueueIsEmpty(CircularQueue* obj);
//�ж�ѭ�������Ƿ�Ϊ��
bool CircularQueueIsFull(CircularQueue* obj);
//�ж�ѭ�������Ƿ�����
void CircularQueueFree(CircularQueue* obj);
//����ѭ������