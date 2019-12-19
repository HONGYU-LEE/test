#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define STACKSIZE 10
typedef int DataType;
typedef struct Stack
{
	DataType* data;
	int top;		// ջ��
	int capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ 
void StackPush(Stack* ps, DataType data);
// ��ջ 
void StackPop(Stack* ps);

// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط���(1)�������Ϊ�շ���0 
int StackEmpty(Stack* ps);
// ����ջ 
void StackDestroy(Stack* ps);

void ChackCapacity(Stack* ps);

