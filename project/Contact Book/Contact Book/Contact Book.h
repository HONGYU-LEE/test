#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<Windows.h>
#define NAME_MAX_SIZE 20
#define TEL_MAX_SIZE 20
#define ADDR_MAX_SIZE 30
#define GENDER_MAX_SIZE 10
#define CONTACT_SIZE 10

typedef struct info
{
	char name[NAME_MAX_SIZE];
	char tel[TEL_MAX_SIZE];
	char addr[ADDR_MAX_SIZE];
	char gender[GENDER_MAX_SIZE];
	int age;
	//�ȴ���ĸ��ַ����ٴ�����Σ������ڴ�������ﵽ�ռ��������
}info;

typedef struct 
{
	info* data;
	int capacity;
	int size;
}contact, *pcontact;
//����˳���������������������

void InitContact(pcontact p);
void AddContact(pcontact p);
void DelContact(pcontact p);
void SearchContact(pcontact p);
void SortContact(pcontact p);
void ShowContact(pcontact p);
void ModifyContact(pcontact p);
void EmptyContact(pcontact p);
int CheckCapacity(pcontact p);
int GetPosition(char* name, pcontact p);
void SaveContact(pcontact p);
void LoadContact(pcontact p);
void EndContact(pcontact p);

