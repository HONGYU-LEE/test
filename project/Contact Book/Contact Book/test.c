#include "Contact Book.h"

void Menu()
{
	printf("************************************************\n");
	printf("**    0.退出程序          1.添加联系人        **\n");
	printf("**    2.删除联系人        3.修改联系人        **\n");
	printf("**    4.查找联系人        5.通讯录排序        **\n");
	printf("**    6.显示所有联系人    7.删除所有联系人    **\n");
	printf("**    8.保存通讯录        9.读取通讯录        **\n");
	printf("************************************************\n");
}

void Test()
{
	int input;
	contact book;
	void (*p[10])(pcontact p) =
	{
		EndContact,
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
	//利用函数指针数组简化不必要的代码

	InitContact(&book);
	//初始化

	do
	{
		Menu();
		printf("请输入要进行的操作：");
		scanf("%d", &input);
		if ((input <= 9 && input >= 0))
		{
			(*p[input])(&book);
		}
		else
		{
			printf("输入错误：\n");
		}
	} while (input);
}

int main()
{	
	Test();
	return 0;
}