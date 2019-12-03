#include<iostream>
using namespace std;

template<class T>
class stack
{
public:
	stack(int size);
	~stack() { delete[] stck; }
	T pop();
	void push(T i);

private:
	int tos;
	int length;
	T* stck;
};

template<class T>
stack<T>::stack(int size)
{
	stck = new T[size];

	if (NULL == stck)
	{
		cout << "cannot allocate stack" << endl;
		exit(1);
	}

	length = size;
	tos = 0;
}

template<class T>
void stack<T>::push(T i)
{
	if (tos == length)
		cout << "stack is full" << endl;

	stck[tos] = i;
	tos++;
}

template<class T>
T stack<T>::pop()
{
	if (tos == 0)
		cout << "stack underflow" << endl;

	tos--;
	return stck[tos];
}


int main()
{
	stack<int> a(10);
	stack<double> b(8);
	stack<char> c(5);
	for (int i = 0; i < 10; i++)
	{
		a.push(i);
	}
	cout << "pop int stack :" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << a.pop() << ' ';
	}
	cout << endl;

	for (int i = 0; i < 8; i++)
	{
		b.push(i * 0.1);
	}
	cout << "pop double stack :" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << b.pop() << ' ';
	}
	cout << endl;

	for (int i = 0; i < 5; i++)
	{
		c.push('a' + i);
	}
	cout << "pop char stack :" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << c.pop() << ' ';
	}
	cout << endl;
	return 0;
}