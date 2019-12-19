#include"Stack.h"

void StackInit(Stack* ps)
{
	ps->data = (DataType*)malloc(STACKSIZE * sizeof(DataType));
	ps->top = 0;
	ps->capacity = STACKSIZE;
}

// ��ջ 
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	ChackCapacity(ps);

	ps->data[ps->top++] = data;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps && ps->top > 0);

	ps->top--;
}

// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->data[ps->top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط���(1)�������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->top ? 0 : 1;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void ChackCapacity(Stack* ps)
{
	if (ps->top == ps->capacity)
	{
		DataType* temp = (DataType*)realloc(ps->data, (ps->capacity + STACKSIZE) * sizeof(DataType));
		if (temp != NULL)
			ps->data = temp;
		else
			return;
	}

	ps->capacity += STACKSIZE;
}