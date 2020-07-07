#include "BinaryTree.h"
#include "LinkedQueue.h"

//����������
BTNode* BinaryTreeCreate(BTDataType* arr, int n, int* pi)
{
	if ('#' == arr[*pi])
	{
		++(*pi);
		return NULL;
	}
		
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->data = arr[(*pi)++];

	root->left = BinaryTreeCreate(arr, n, pi);
	root->right = BinaryTreeCreate(arr, n, pi);

	return root;
}
// ����������
void BinaryTreeDestory(BTNode* root)
{
	BTNode* node = root;
	if (!node)
		return;
	BinaryTreeDestory(node->left);
	BinaryTreeDestory(node->right);

	free(node);
	node = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (!root)
		return 0;

	return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (!root)
		return 0;
	if (!root->right && !root->left)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// ��������k��ڵ����

int BinaryTreeHigh(BTNode* root)
{
	if (!root)
		return 0;
	int leftHigh = BinaryTreeHigh(root->left);
	int rightHigh = BinaryTreeHigh(root->right);

	return leftHigh < rightHigh ? rightHigh + 1 : leftHigh + 1;
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (!root)
		return 0;
	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* node;
	if (!root)
		return NULL;
	if (root->data = x)
		return root;
	
	node = BinaryTreeFind(root->left, x);
	if (node)
		return node;

	node = BinaryTreeFind(root->right, x);
	if (node)
		return node;

	return NULL;

}

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	if (!root)
		return;

	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (!root)
		return;

	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);

}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (!root)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}

// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if(root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* node = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", node->data);


		if(node->left)
			QueuePush(&q, node->left);
		if(node->right)
			QueuePush(&q, node->right);
	}
	printf("\n");
	QueueDestroy(&q);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (1)
	{
		BTNode* node = QueueFront(&q);
		if (!node)
			break;
		else
			QueuePop(&q);

		QueuePush(&q, node->left);
		QueuePush(&q, node->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* node = QueueFront(&q);

		if (node)
		{
			QueueDestroy(&q);
			return 0;
		}
		else
			QueuePop(&q);

	}

	QueueDestroy(&q);
	return 1;
}