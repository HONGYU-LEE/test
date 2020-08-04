#include<mutex>
#include<iostream>
#include"lock_guard.h"
using namespace std;

mutex mtx;
static int n = 0;
void Func()
{
	for (size_t i = 0; i < 1000000; ++i)
	{
		lock_guard<mutex> lock(mtx);
		++n;
	}
}
int main()
{
	int begin = clock();
	thread t1(Func);
	thread t2(Func);
	t1.join();
	t2.join();
	int end = clock();
	cout << n << endl;
	cout << "cost time:" << end - begin << endl;

	return 0;
}