
#include "Contact Book.h"

void InitContact(pcontact p)
{
	p->size = 0;
	p->data = (info*)malloc(CONTACT_SIZE * sizeof(info));
	p->capacity = CONTACT_SIZE;
}

void AddContact(pcontact p)
{
	assert(p);
	system("cls");
	if (0 == CheckCapacity(p))
	{
		printf("ͨѶ¼���������ʧ��\n");
		return;
	}
	printf("������������\n");
	scanf("%s", p->data[p->size].name);
	printf("������绰��\n");
	scanf("%s", p->data[p->size].tel);
	printf("�������Ա�\n");
scanf("%s", p->data[p->size].gender);
	printf("�������ַ��\n");
	scanf("%s", p->data[p->size].addr);
	printf("���������䣺\n");
	scanf("%d", &(p->data[p->size].age));

	printf("��ӳɹ�������\n");
	p->size++;
}

void DelContact(pcontact p)
{
	assert(p);
	system("cls");
	int pos, i;
	char name[NAME_MAX_SIZE];
	if (!p->size)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}

	printf("������Ҫɾ�����˵�������\n");
	scanf("%s", name);
	pos = GetPosition(name, p);

	if (-1 == pos)
	{
		printf("���˲�����\n");
	}
	else
	{
		for (i = pos; pos < p->size - 1; i++)
		{
			p->data[i] = p->data[i + 1];
		}
		p->size--;
		printf("ɾ���ɹ�������\n");
	}
}

void ShowContact(pcontact p)
{
	assert(p);
	system("cls");
	int i;
	if (!p->size)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}

	for (i = 0; i < p->size; i++)
	{
		printf("*******************************************\n");
		printf("**********    �� %d λ��ϵ��     **********\n", i + 1);
		printf("������%s \n", p->data[i].name);
		printf("�Ա�%s \n", p->data[i].gender);
		printf("���䣺%d \n", p->data[i].age);
		printf("��ַ��%s \n", p->data[i].addr);
		printf("�绰��%s \n", p->data[i].tel);
		printf("*******************************************\n");
		
	}
}

void ModifyContact(pcontact p)
{
	assert(p);
	system("cls");
	char name[NAME_MAX_SIZE];
	int pos;
	printf("������Ҫ�޸ĵ��˵�������\n");
	scanf("%s", name);
	pos = GetPosition(name, p);

	if (-1 == pos)
	{
		printf("���˲�����\n");
	}
	else
	{
		printf("�������޸ĺ��������\n");
		scanf("%s", p->data[pos].name);
		printf("�������޸ĺ�ĵ绰��\n");
		scanf("%s", p->data[pos].tel);
		printf("�������޸ĺ���Ա�\n");
		scanf("%s", p->data[pos].gender);
		printf("�������޸ĺ�����䣺\n");
		scanf("%d", &(p->data[pos].age));
		printf("�������޸ĺ�ĵ�ַ��\n");
		scanf("%s", p->data[pos].addr);
		printf("�޸ĳɹ�������\n");
	}
}

void SearchContact(pcontact p)
{
	assert(p);
	system("cls");
	char name[NAME_MAX_SIZE];
	int pos;
	printf("������Ҫ���ҵ��˵�������\n");
	scanf("%s", name);
	pos = GetPosition(name, p);
	if (-1 == pos)
	{
		printf("���˲����ڣ�\n");
	}
	else
	{
		printf("*******************************************\n");
		printf("������%s \n", p->data[pos].name);
		printf("�Ա�%s \n", p->data[pos].gender);
		printf("���䣺%d \n", p->data[pos].age);
		printf("��ַ��%s \n", p->data[pos].addr);
		printf("�绰��%s \n", p->data[pos].tel);
		printf("*******************************************\n");
		printf("���ҳɹ�������\n");
	}
}

int GetPosition(char* name, pcontact p)
{
	assert(p);
	int pos;
	for (pos = 0; pos < p->size; pos++)
	{
		if (0 == strcmp(name, p->data[pos].name))
		{
			return pos;
		}
	}
	return -1;
}

void EmptyContact(pcontact p)
{
	assert(p);
	system("cls");
	if (!p->size)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	else
	{
		free(p->data);
		p->data = NULL;
		p->size = 0;
		p->capacity = 0;
		printf("ͨѶ¼��ճɹ�������\n");
	}
}

int CheckCapacity(pcontact p)
{
	assert(p);
	if (p->size == p->capacity)
	{
		printf("ͨѶ¼��������������\n");
		;
		info *temp = realloc(p->data, (p->capacity + CONTACT_SIZE) * sizeof(info));
		if (NULL == temp)
		{
			printf("����ʧ��\n");
			return 0;
		}
		else
		{
			p->data = temp;
			p->capacity += CONTACT_SIZE;
			printf("���ݳɹ�!!!\n");
		}
	}
	return 1;
}

void SortContact(pcontact p)
{
	assert(p);
	system("cls");
	int i, j, flag = 1;
	info temp = { 0 };
	for (i = p->size; i > 0 && flag; i--)
	{
		flag = 0;
		for (j = 1; j < p->size; j++)
		{
			if (strcmp(p->data[j].name, p->data[j - 1].name) < 0)
			{
				temp = p->data[j];
				p->data[j] = p->data[j - 1];
				p->data[j - 1] = temp;
				flag = 1;
			}
		}
	}
	printf("����ɹ�������\n");
}

void SaveContact(pcontact p)
{
	assert(p);
	system("cls");
	FILE* pf = fopen("contact.txt", "w");
	int i;
	if (NULL == pf)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	for (i = 0; i < p->size; i++)
	{
		fwrite(&(p->data[i]), sizeof(info), 1, pf);
	}
	printf("ͨѶ¼����ɹ�\n");
	fclose(pf);
}

void LoadContact(pcontact p)
{
	assert(p);
	system("cls");
	FILE* pf = fopen("contact.txt", "r");
	if (NULL == pf)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	while (fread(&(p->data[p->size]), sizeof(info), 1, pf))
	{
		if (CheckCapacity(p))
		{
			p->size++;
		}
	}
	printf("ͨѶ¼��ȡ�ɹ�\n");
	fclose(pf);
}