#include"Stack.h"

void test()
{
	Stack stack ;
	StackInit(&stack);
	StackPush(&stack, 1);
	printf("%d ", StackTop(&stack));
	StackPush(&stack, 2);
	printf("%d ", StackTop(&stack));
	StackPush(&stack, 3);
	printf("%d ", StackTop(&stack));
	StackPush(&stack, 4);
	printf("%d ", StackTop(&stack));
	printf("\n");
	printf("Ԫ�ظ���Ϊ%d\n", StackSize(&stack));
	printf("ջ�Ƿ�Ϊ��:%d\n", StackEmpty(&stack));

	printf("%d ", StackTop(&stack));
	StackPop(&stack);
	printf("%d ", StackTop(&stack));
	StackPop(&stack);
	printf("%d ", StackTop(&stack));
	StackPop(&stack);
	printf("%d ", StackTop(&stack));
	StackPop(&stack);

	printf("\n");

	printf("Ԫ�ظ���Ϊ%d\n", StackSize(&stack));
	printf("ջ�Ƿ�Ϊ��:%d\n", StackEmpty(&stack));
}


int main()
{
	test();
	return 0;
}