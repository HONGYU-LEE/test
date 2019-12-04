#include "SeqList.h"

void SeqListInit(SeqList* list, size_t capacity)
{
	assert(list);
	DATATYPE* temp;
	temp = (DATATYPE*)malloc(capacity * sizeof(DATATYPE));
	if (NULL == list)
	{
		printf("��ʼ��ʧ��\n");
		return;
	}
	list->data = temp;
	list->size = 0;
	list->capicity = capacity;
}

void SeqListDestory(SeqList* list)
{
	assert(list);
	list->size = 0;
	list->capicity = 0;
	free(list->data);
	list->data = NULL;
}

int CheckCapacity(SeqList* list)
{
	assert(list);
	DATATYPE* temp;
	if (list->capicity == list->size)
	{
		temp = realloc(list, 2 * LISTSIZE * sizeof(DATATYPE));
		if (NULL == temp)
		{
			printf("����ʧ��\n");
			return 0;
		}
		else
		{
			list->data = temp;
			printf("���ݳɹ�\n");
		}
	}
	return 1;
}

void SeqListPrint(SeqList* list)
{
	assert(list);
	size_t i = 0;
	for (i = 0; i < list->size; i++)
	{
		printf("%d ", list->data[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* list, DATATYPE x)
{
	assert(list);
	if (!CheckCapacity(list))
	{
		printf("˳�������\n");
		return;
	}
	
	list->data[list->size++] = x;

}

void SeqListPushFront(SeqList* list, DATATYPE x)
{
	assert(list);
	int i;
	if (!CheckCapacity(list))
	{
		printf("˳�������\n");
		return;
	}
	for (i = list->size; i > 0; i--)
	{
		list->data[i] = list->data[i - 1];
	}

	list->data[0] = x;
	list->size++;
}

int SeqListFind(SeqList* list, DATATYPE x)
{
	assert(list);
	size_t i;
	for (i = 0; i < list->size; i++)
	{
		if (x == list->data[i])
		{
			printf("���ҳɹ�\n");
			return i;
		}
	}

	printf("����ʧ��\n");
	return -1;
}

void SeqListPopBack(SeqList* list)
{
	assert(list);
	if (list->size == 0)
	{
		printf("���ѿ�\n");
		return;
	}

	list->size--;
}

void SeqListPopFront(SeqList* list)
{
	assert(list);
	size_t i;
	if (list->size == 0)
	{
		printf("���ѿ�\n");
		return;
	}
	for (i = 0; i < list->size - 1; i++)
	{
		list->data[i] = list->data[i + 1];
	}
	list->size--;
}

void SeqListInsert(SeqList* list, size_t pos, DATATYPE x)
{
	assert(list);
	int i = 0;
	if (!CheckCapacity(list))
	{
		printf("˳�������\n");
		return;
	}
	for (i = (int)list->size; i > pos -1; i--)
	{
		list->data[i] = list->data[i - 1];
	}
	list->data[pos - 1] = x;
	list->size++;
}

void SeqListErase(SeqList* list, size_t pos)
{
	assert(list);
	size_t i;
	if (list->size == 0)
	{
		printf("���ѿ�\n");
		return;
	}
	for (i = pos - 1; i < list->size - 1; i++)
	{
		list->data[i] = list->data[i + 1];
	}

	list->size--;
}