#include"Stack.h"

void StackInit(Stack* ps)
{
	ps->data = (DataType*)malloc(STACKSIZE * sizeof(DataType));
	ps->top = 0;
	ps->capacity = STACKSIZE;
}

// 入栈 
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	ChackCapacity(ps);

	ps->data[ps->top++] = data;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps && ps->top > 0);

	ps->top--;
}

// 获取栈顶元素 
DataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->data[ps->top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

// 检测栈是否为空，如果为空返回非零(1)，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->top ? 0 : 1;
}

// 销毁栈 
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