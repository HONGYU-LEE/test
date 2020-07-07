#include"PSA.hpp"
#include<vector>
using namespace std;

void test()
{
	List List;
	size_t pcbNum;

	cout << "请输入进程的数量:" << endl;
	cin >> pcbNum;

	vector<string> processName(pcbNum);
	vector<size_t> time(pcbNum);
	vector<int> priority(pcbNum);


	cout << "请输入所有进程的名字:" << endl;
	for (size_t i = 0; i < pcbNum; i++)
	{
		cin >> processName[i];
	}

	for (size_t i = 0; i < pcbNum; i++)
	{
		cout << "请输入进程" << processName[i] << "的运行时间" << endl;
		cin >> time[i];
		cout << "请输入进程" << processName[i] << "的优先级" << endl;
		cin >> priority[i];

		PCB p(processName[i], time[i], priority[i], i);
		List.Push(p);
	}
	List.Print();
	PSA(List);
}

int main()
{
	test();
}