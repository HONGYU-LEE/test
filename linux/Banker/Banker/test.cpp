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
		cout << "1.�жϵ�ǰϵͳ״̬" << endl;
		cout << "2.������Դ" << endl;
		cout << "0.�˳�" << endl;
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
			cout << "�����뷢������Ľ��̺�:" << endl;
			cin >> pid;

			cout << "�������������Դ������:" << endl;
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
			cout << "��������ȷѡ��" << endl;
			continue;
		}
	
		if (result == true)
		{
			cout << "��Դ����ɹ�, ϵͳ��ʱ��ȫ" << endl;
			banker.printSecurity();
		}
		else
		{
			cout << "��Դ����ʧ�ܣ���ʱ����ȫ" << endl;
		}
	}

	return 0;
}
