#include"Stack.h"

void ChackCapacity(Stack* ps)
{
	void ChackCapacity(Stack * ps)
	{
		if (ps->top >= ps->capacity)
		{
			ps->capacity *= 2;
			ps->data = (DataType*)realloc(ps->data, ps->capacity * sizeof(DataType));

		}
	}
}
void StackInit(Stack* ps)
{
	ps->data = (DataType*)malloc(STACKSIZE * sizeof(DataType));
	ps->top = 0;
	ps->capacity = STACKSIZE;
}

// ��ջ 
void StackPush(Stack* ps, DataType data)
{
	ChackCapacity(ps);
	ps->data[ps->top++] = data;
}

// ��ջ 
void StackPop(Stack* ps)
{
	if (0 == ps->top)
		return;
	ps->top--;
}

// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* ps)
{
	if (0 == ps->top)
		return (DataType)0;
	return ps->data[ps->top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط���(1)�������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->top == 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}