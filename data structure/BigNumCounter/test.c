
#include "BigNumber Counter.h"

void Menu()
{
	printf("************************************************\n");
	printf("**    1.�����ӷ�          2.��������          **\n");
	printf("**    3.�����˷�          4.��������          **\n");
	printf("**               0.�˳�                       **\n");
	printf("************************************************\n");
}

void test()
{
	void (*Counter[4])(BigNum * s1, BigNum * s2, BigNum * s3) =
	{
		AddBigNum,
		MinusBigNum,
		MuliplyBigNum,
		DivideBigNum,
	};
	//����ָ����ֵ�򻯴���
	int input = 0;
	BigNum s1, s2, s3;


	char str1[NUMSIZE];
	char str2[NUMSIZE];

	printf("�������һ����������");
	scanf("%s",str1);
	InitBigNum(&s1, str1);

	printf("������ڶ�����������");
	scanf("%s", str2);
	InitBigNum(&s2, str2);

	do
	{
		Menu();
		printf("������Ҫ���еĲ�����");
		scanf("%d", &input);
		InitBigNum(&s3, "0");
		if ((input <= 4 && input > 0))
		{
			(*Counter[input - 1])(&s1, &s2, &s3);
			printf("��������%s\n\n", s3.data);
		}
		else if(0 == input)
		{
			printf("�����˳���\n");
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
	
	test();
	return 0;
}