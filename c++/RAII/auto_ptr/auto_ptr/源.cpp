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

	// 现在再从实现原理层来分析会发现，这里拷贝后把ap对象的指针赋空了，导致ap对象悬空
	// 通过ap对象访问资源时就会出现问题。
	lee::auto_ptr<int> copy(ap);

	cout << endl;
	return 0;
}