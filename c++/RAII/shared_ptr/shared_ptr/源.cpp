#include<thread>
#include"shared_ptr.h"
#include<iostream>
using namespace std;


int x2()
{
	lee::shared_ptr<int> sp(new int);
	cout << sp.use_count() << endl;
	int n = 100000;

	std::thread t1([&]() {
		for (int i = 0; i < n; ++i)
		{
			lee::shared_ptr<int> sp1(sp);
		}
		});

	std::thread t2([&]() {
		for (int i = 0; i < n; ++i)
		{
			lee::shared_ptr<int> sp2(sp);
		}
		});

	t1.join();
	t2.join();

	cout << sp.use_count() << endl;

	return 0;
}
#include<memory>
class A
{
public:
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a1;
	int _a2;
};
int x4()
{



	return 0;
}
int main()
{
	lee::shared_ptr<A> sp1(new A);
	lee::shared_ptr<A, lee::DelArray<A>> sp2(new A[10], lee::DelArray<A>());
}
