#include "BinaryTree.h"

int main()
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	char str[] = "ABD##E##CF##G##";

	int i = 0;
	
	node = BinaryTreeCreate(str, sizeof(str) / sizeof(str[0]), &i);
	//printf("�������Ϊ��");
	//BinaryTreePrevOrder(node);
	//printf("\n");
	//printf("�������Ϊ��");
	//BinaryTreeInOrder(node);
	//printf("\n");
	//printf("�������Ϊ��");
	//BinaryTreePostOrder(node);
	//printf("\n");
	printf("�������Ϊ��");
	BinaryTreeLevelOrder(node);
	printf("\n");

	//printf("�ڵ���Ϊ��%d \n", BinaryTreeSize(node));
	//printf("Ҷ�ӽڵ���Ϊ��%d \n", BinaryTreeLeafSize(node));
	//printf("��k��ڵ���Ϊ�ڵ���Ϊ��%d \n", BinaryTreeLevelKSize(node, 2));
	//printf("�������߶�Ϊ��%d \n", BinaryTreeHigh(node));
	//BTNode* ret = BinaryTreeFind(node, 'g');
	//printf("%c\n", ret->data);
	//printf("�������ǲ�����ȫ������%d", BinaryTreeComplete(node));
	
	return 0;
}