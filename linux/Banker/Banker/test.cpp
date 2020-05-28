#include"Banker.hpp"
using namespace std;

int main()
{
	int flag = 0;
	Banker* backup = Input();
	bool result;

	while (1)
	{
		Banker banker = *backup;

		cout << "--------------------" << endl;
		cout << "1.判断当前系统状态" << endl;
		cout << "2.申请资源" << endl;
		cout << "0.退出" << endl;
		cout << "--------------------" << endl;
		cin >> flag;

		switch (flag)
		{
		case 1:
		{
			result = banker.CheckSafe();
			break;
		}

		case 2:
		{
			size_t pid;
			vector<int> request(banker.ResouceNum(), 0);
			cout << "请输入发起请求的进程号:" << endl;
			cin >> pid;

			cout << "请输入请求的资源的数量:" << endl;
			for (size_t i = 0; i < request.size(); i++)
			{

				cin >> request[i];
			}

			result = banker.CheckRequest(pid, request);
			break;
		}

		case 0:
			exit(0);
		default:
			cout << "请输入正确选项" << endl;
			continue;
		}
	
		if (result == true)
		{
			cout << "资源分配成功, 系统此时安全" << endl;
			banker.printSecurity();
		}
		else
		{
			cout << "资源分配失败，此时不安全" << endl;
		}
	}

	return 0;
}
