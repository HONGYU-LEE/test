#include"PSA.hpp"
#include<vector>
using namespace std;

void test()
{
	List List;
	size_t pcbNum;

	cout << "��������̵�����:" << endl;
	cin >> pcbNum;

	vector<string> processName(pcbNum);
	vector<size_t> time(pcbNum);
	vector<int> priority(pcbNum);


	cout << "���������н��̵�����:" << endl;
	for (size_t i = 0; i < pcbNum; i++)
	{
		cin >> processName[i];
	}

	for (size_t i = 0; i < pcbNum; i++)
	{
		cout << "���������" << processName[i] << "������ʱ��" << endl;
		cin >> time[i];
		cout << "���������" << processName[i] << "�����ȼ�" << endl;
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