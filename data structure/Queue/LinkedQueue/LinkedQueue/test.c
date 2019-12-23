#pragma once
#include"LinkedQueue.h"

test()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d\n", QueueSize(&q));
	QueuePush(&q, 4);

	printf("%d\n", QueueEmpty(&q));
	printf("%d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	printf("%d\n", QueueEmpty(&q));
	printf("%d\n", QueueSize(&q));
}

int main()
{
	test();
	return 0;
}