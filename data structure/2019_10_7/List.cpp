#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define StackSize 100 //�ٶ�Ԥ�����ջ�ռ����Ϊ100��Ԫ��
typedef char DataType;//�ٶ�ջԪ�ص���������Ϊ�ַ�

typedef struct
{
	DataType data[StackSize];
	int top;
}SeqStack;

void Init(SeqStack *&s)
{
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
}
//��ʼ��ջ
void push(SeqStack *s,DataType e)
{
	if( s->top == StackSize )
	{
		printf("ջ��\n");
	}
	else
	{
		s->top++;
        s->data[s->top]=e;
	}
}
//��ջ 
DataType pop(SeqStack *s)
{
	if( s->top == -1 )
	{
		printf("ջ��\n");
		return  '\0';
	}	
	return (s->data[s->top--]);
}
//��ջ 
int main()
{
	SeqStack *s;
	int i=0,length,mid,flag=1;
	char str[StackSize],y,z;
	printf("��������Ҫ�жϻ��ĵ��ַ�����\n");
	gets(str);
	length = strlen(str);
	mid = length/2-1;
//midΪ�ַ����м��ַ����±�
	Init(s);
	
	for( i=0; i<length/2; i++)
	{
		push(s,str[i]);
	}
//��ջ	
	if( length%2 != 0 )
		mid += 1;
//�ж��ַ�����������������ż������Ϊ����ʱ���м���һ����ʼ�Ƚ� 
	for( i=1; i<=length/2; i++)
	{
		if( str[mid+i] == pop(s) )
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	} 
	if( flag == 1 )
		printf("���ַ���Ϊ����\n"); 
	else
		printf("���ַ������ǻ���");

	return 0;
}
