#include<iostream>
#include"auto_ptr.h"

using namespace std;
template<class T>
struct ListNode
{
	T data;
	struct weak_ptr<ListNode<T>> next;
	struct weak_ptr<ListNode<T>> prev;
};

int main()
{
	int* i = new int;
	lee::auto_ptr<int> ap(i);

	// �����ٴ�ʵ��ԭ����������ᷢ�֣����������ap�����ָ�븳���ˣ�����ap��������
	// ͨ��ap���������Դʱ�ͻ�������⡣
	lee::auto_ptr<int> copy(ap);

	cout << endl;
	return 0;
}