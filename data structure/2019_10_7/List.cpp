#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define StackSize 100 //�ٶ�Ԥ�����ջ�ռ����Ϊ100��Ԫ��
#define ERROR 1
#define OK 0
typedef char DataType;//�ٶ�ջԪ�ص���������Ϊ�ַ�

typedef struct
{
	DataType data[StackSize];
	int top;
}SeqStack;

void Init(SeqStack *&s)//��ʼ��ջ
{
    s=(SeqStack *)malloc(sizeof(SeqStack));
    s->top=-1;
}

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

DataType pop(SeqStack *s)
{
	if( s->top == 0 )
	{
		printf("ջ��\n");
		return  '\0';
	}	
	return s->data[s->top--];
}

int main()
{
	SeqStack *s;
	Init(s);
	int i=0,length,mid,flag=1;
	char str[StackSize],y,z;
	printf("��������Ҫ�жϻ��ĵ��ַ�����\n");
	gets(str);
	length = strlen(str);
	mid = length/2;
	
	for( i=0; i<length/2; i++)
	{
		push(s,str[i]);
	}
//��ʼ��ջ	
	if( length%2 != 0 )
		mid += 1;

	for( i=1; i<=length/2; i++)
	{
		y =pop(s);
		if( str[mid+i] == y )
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
