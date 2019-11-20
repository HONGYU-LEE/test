
#include "Contact Book.h"

void Menu()
{
	printf("************************************************\n");
	printf("**    0.�˳�����          1.�����ϵ��        **\n");
	printf("**    2.ɾ����ϵ��        3.�޸���ϵ��        **\n");
	printf("**    4.������ϵ��        5.ͨѶ¼����        **\n");
	printf("**    6.��ʾ������ϵ��    7.ɾ��������ϵ��    **\n");
	printf("**    8.����ͨѶ¼        9.��ȡͨѶ¼        **\n");
	printf("************************************************\n");
}

void Test()
{
	int input;
	contact book;
	void (*p[9])(pcontact p) =
	{
		AddContact,
		DelContact,
		ModifyContact,
		SearchContact,
		SortContact,
		ShowContact,
		EmptyContact,
		SaveContact,
		LoadContact,
	};
	//���ú���ָ������򻯲���Ҫ�Ĵ���

	InitContact(&book);
	//��ʼ��

	do
	{
		Menu();
		printf("������Ҫ���еĲ�����");
		scanf("%d", &input);
		if ((input <= 9 && input > 0))
		{
			(*p[input - 1])(&book);
		}
		else if (0 == input)
		{
			exit(0);
		}
		else
		{
			printf("�������\n");
		}
	} while (input);
}

int main()
{	
	Test();
	return 0;
}