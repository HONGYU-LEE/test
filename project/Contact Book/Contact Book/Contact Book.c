
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
		printf("通讯录已满，添加失败\n");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", p->data[p->size].name);
	printf("请输入电话：\n");
	scanf("%s", p->data[p->size].tel);
	printf("请输入性别：\n");
scanf("%s", p->data[p->size].gender);
	printf("请输入地址：\n");
	scanf("%s", p->data[p->size].addr);
	printf("请输入年龄：\n");
	scanf("%d", &(p->data[p->size].age));

	printf("添加成功！！！\n");
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
		printf("通讯录为空\n");
		return;
	}

	printf("请输入要删除的人的姓名：\n");
	scanf("%s", name);
	pos = GetPosition(name, p);

	if (-1 == pos)
	{
		printf("此人不存在\n");
	}
	else
	{
		for (i = pos; pos < p->size - 1; i++)
		{
			p->data[i] = p->data[i + 1];
		}
		p->size--;
		printf("删除成功！！！\n");
	}
}

void ShowContact(pcontact p)
{
	assert(p);
	system("cls");
	int i;
	if (!p->size)
	{
		printf("通讯录为空\n");
		return;
	}

	for (i = 0; i < p->size; i++)
	{
		printf("*******************************************\n");
		printf("**********    第 %d 位联系人     **********\n", i + 1);
		printf("姓名：%s \n", p->data[i].name);
		printf("性别：%s \n", p->data[i].gender);
		printf("年龄：%d \n", p->data[i].age);
		printf("地址：%s \n", p->data[i].addr);
		printf("电话：%s \n", p->data[i].tel);
		printf("*******************************************\n");
		
	}
}

void ModifyContact(pcontact p)
{
	assert(p);
	system("cls");
	char name[NAME_MAX_SIZE];
	int pos;
	printf("请输入要修改的人的姓名：\n");
	scanf("%s", name);
	pos = GetPosition(name, p);

	if (-1 == pos)
	{
		printf("此人不存在\n");
	}
	else
	{
		printf("请输入修改后的姓名：\n");
		scanf("%s", p->data[pos].name);
		printf("请输入修改后的电话：\n");
		scanf("%s", p->data[pos].tel);
		printf("请输入修改后的性别：\n");
		scanf("%s", p->data[pos].gender);
		printf("请输入修改后的年龄：\n");
		scanf("%d", &(p->data[pos].age));
		printf("请输入修改后的地址：\n");
		scanf("%s", p->data[pos].addr);
		printf("修改成功！！！\n");
	}
}

void SearchContact(pcontact p)
{
	assert(p);
	system("cls");
	char name[NAME_MAX_SIZE];
	int pos;
	printf("请输入要查找的人的姓名：\n");
	scanf("%s", name);
	pos = GetPosition(name, p);
	if (-1 == pos)
	{
		printf("此人不存在：\n");
	}
	else
	{
		printf("*******************************************\n");
		printf("姓名：%s \n", p->data[pos].name);
		printf("性别：%s \n", p->data[pos].gender);
		printf("年龄：%d \n", p->data[pos].age);
		printf("地址：%s \n", p->data[pos].addr);
		printf("电话：%s \n", p->data[pos].tel);
		printf("*******************************************\n");
		printf("查找成功！！！\n");
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
		printf("通讯录为空\n");
		return;
	}
	else
	{
		free(p->data);
		p->data = NULL;
		p->size = 0;
		p->capacity = 0;
		printf("通讯录清空成功！！！\n");
	}
}

int CheckCapacity(pcontact p)
{
	assert(p);
	if (p->size == p->capacity)
	{
		printf("通讯录已满，进行扩容\n");
		;
		info *temp = realloc(p->data, (p->capacity + CONTACT_SIZE) * sizeof(info));
		if (NULL == temp)
		{
			printf("扩容失败\n");
			return 0;
		}
		else
		{
			p->data = temp;
			p->capacity += CONTACT_SIZE;
			printf("扩容成功!!!\n");
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
	printf("排序成功！！！\n");
}

void SaveContact(pcontact p)
{
	assert(p);
	system("cls");
	FILE* pf = fopen("contact.txt", "w");
	int i;
	if (NULL == pf)
	{
		printf("文件打开失败\n");
		return;
	}
	for (i = 0; i < p->size; i++)
	{
		fwrite(&(p->data[i]), sizeof(info), 1, pf);
	}
	printf("通讯录保存成功\n");
	fclose(pf);
}

void LoadContact(pcontact p)
{
	assert(p);
	system("cls");
	FILE* pf = fopen("contact.txt", "r");
	if (NULL == pf)
	{
		printf("文件打开失败\n");
		return;
	}
	while (fread(&(p->data[p->size]), sizeof(info), 1, pf))
	{
		if (CheckCapacity(p))
		{
			p->size++;
		}
	}
	printf("通讯录读取成功\n");
	fclose(pf);
}