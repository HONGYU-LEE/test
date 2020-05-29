#include<iostream>
#include<string>
#include<vector>
#include<cassert>

class Banker
{
public:
	std::vector<std::string> _ResouceName; //��Դ��

	Banker(std::vector<std::string> ResouceName
		, std::vector<int> available
		, std::vector< std::vector<int >> max
		, std::vector< std::vector<int >> allocation)

		: _ResouceName(ResouceName)
		, _available(available)
		, _max(max)
		, _allocation(allocation)
		, _need(_max.size(), std::vector<int>(_max[0].size(), 0))
		, _processNum(_max.size())
		, _resouceNum(_max[0].size())
	{
		//�������Ҫ����Դ��
		for (size_t i = 0; i < _processNum; i++)
		{	
			for (size_t j = 0; j < _resouceNum; j++)
			{
				_need[i][j] = _max[i][j] - _allocation[i][j];
			}
		}
	}

	//��װ������ȡ�����Ľӿ�
	int ResouceNum() const
	{
		return _resouceNum;
	}

	int ProcessNum() const
	{
		return _processNum;
	}

	//�����ȫ����
	void printSecurity()
	{
		std::cout << "--------------" << std::endl;
		std::cout << "��ȫ����Ϊ: " ;
		for (auto it : _Security)
		{
			std::cout << it << std::ends;
		}
		std::cout << "--------------" << std::endl;
		std::cout << std::endl;
	}

	//�������
	void OutPut()
	{
		std::cout << "*************************************" << std::endl;
		std::cout << "��ǰ������:" << _processNum  << "  ��ǰ��Դ��������:" << _resouceNum << std::endl;

		for (size_t i = 0; i < _resouceNum; i++)
		{
			std::cout << "��Դ" << _ResouceName[i] << "��������Ϊ: " << _available[i] << std::endl;
		}

		std::cout << "--------------" << std::endl;
		for (size_t i = 0; i < _processNum; i++)
		{
			std::cout << "����" << i << std::endl;

			for (size_t j = 0; j < _resouceNum; j++)
			{
				std::cout << "��Դ" << _ResouceName[j] << " �����������Ϊ: " << _max[i][j] << " ��ǰ��������Ϊ: " << _allocation[i][j] << " ʣ����������Ϊ: " << _need[i][j] << std::endl;
			}
		}
		std::cout << "*************************************" << std::endl;
	}

	//���м��㷨���ģ��ж������㷨
	bool CheckRequest(size_t pid, std::vector<int> request)
	{
		//�����Դ�����Ƿ����
		for (size_t i = 0; i < _resouceNum; i++)
		{
			//������Դ���Ѿ��������ֵ
			if (request[i] > _need[pid][i])
			{
				std::cout << "������Դ���Ѿ��������ֵ" << std::endl;
				return false;
			}
				
			//�����㹻��Դ
			if (request[i] > _available[i])
			{
				std::cout << "�����㹻��Դ�����̵ȴ�" << std::endl;
				return false;
			}				
		}

		//���Է�����Դ�����̣������˴η����ϵͳ�Ƿ��ڰ�ȫ״̬
		for (size_t i = 0; i < _resouceNum; i++)
		{
			_available[i] -= request[i];
			_allocation[pid][i] += request[i];
			_need[pid][i] -= request[i];
		}

		//�������ϵͳ�Ƿ�ȫ
		if (CheckSafe() == true)
		{
			//�����ϵͳ��ȫ����ʽ����
			std::cout << "������Դ" << pid << "����ɹ�" << std::endl;
			OutPut();

			return true;
		}
		else
		{
			//����󲻰�ȫ������ʧЧ����Դ�ָ�
			std::cout << "������Դ�����ϵͳ����ȫ����������" << std::endl;
			for (size_t i = 0; i < _resouceNum; i++)
			{
				_available[i] += request[i];
				_allocation[pid][i] -= request[i];
				_need[pid][i] += request[i];
			}
			OutPut();

			return false;
		}
	}



	//��ȫ���㷨
	bool CheckSafe()
	{
		std::vector<int> work(_available);   //��ʾϵͳ���ṩ�����̼�����������ĸ�����Դ��Ŀ
		std::vector<bool> finish(_processNum, false);    //��ʾϵͳ�Ƿ����㹻����Դ������ý���

		while (1)
		{
			size_t i = 0;
			//����Ƿ�ȫ�������ڰ�ȫ״̬
			for (i = 0; i < _processNum; i++)
			{
				if(finish[i] == false)
					break;
			}

			//���ȫ�����ڰ�ȫ״̬����˵����ʱϵͳҲ���ڰ�ȫ״̬
			if (i == _processNum)
			{
				std::cout << "ϵͳ��ʱ��ȫ" << std::endl;
				return true;
			}

			for (i = 0; i < _processNum; i++)
			{
				//�����������Ѿ�ִ�й���������
				if (finish[i] == true)
				{
					continue;
				}
					
				//��־��ǰ���̷�����Դ���Ƿ�ȫ
				bool flag = true;

				for (size_t j = 0; j < _resouceNum; j++)
				{
					//���ĳһ����Դ�������䣬��˵����ǰ���̲���ִ�У������жϺ����
					if (_need[i][j] > work[j])
					{
						flag = false;
						break;
					}
				}

				if (flag == true)
				{
					std::cout << "ִ�н���" << i << " ,ϵͳ��������Դ����" << std::endl;
					//���밲ȫ������
					_Security.push_back(i);

					//���ý������У������ͷŽ�����ռ��Դ
					for (size_t j = 0; j < _resouceNum; j++)
					{
						work[j] += _allocation[i][j];
						finish[i] = true;

						std::cout << "������Դ"<< _ResouceName[j] << "����Ϊ: " << work[j] << std::endl;
					}

					break;
					//������������һ�ֲ��Ұ�ȫ����
				}
			}

			//�������ȫ��������Ҳû���κ�һ��ִ�У���˵����ʱ�޷����䣬����ȫ
			if (i == _processNum)
			{
				std::cout << "ϵͳ��ʱ����ȫ" << std::endl;
				return false;
			}
				
		}
	}

private:
	friend Banker* Input();		//���뺯��	
	std::vector<int> _available;	//ϵͳ�����õĸ�����Դ��Ŀ
	std::vector< std::vector<int >> _max;	//ÿһ�����̶Ը�����Դ���������
	std::vector< std::vector<int >> _allocation;	//ϵͳ��ÿһ����Դ��ǰ�ѷ����ÿһ���̵���Դ��
	std::vector< std::vector<int >> _need;	//ÿһ����������ĸ�����Դ��
	std::vector<int> _Security; //��ȫ����
	size_t _processNum;	//������
	size_t _resouceNum;	//��Դ��
};

//���뺯��
Banker* Input()
{
	size_t processNum, resouceNum;
	std::cout << "�������������:" << std::endl;
	std::cin >> processNum;

	std::cout << "��������Դ��������:" << std::endl;
	std::cin >> resouceNum;

	std::vector<std::string> ResouceName(resouceNum);
	std::vector<int> available(resouceNum);
	std::vector< std::vector<int >> max(processNum, std::vector<int>(resouceNum, 0));
	std::vector< std::vector<int >> allocation(processNum, std::vector<int>(resouceNum, 0));

	std::cout << "��������Դ��:" << std::endl;
	for (size_t i = 0; i < resouceNum; i++)
	{
		std::cin >> ResouceName[i];
	}

	std::cout << "������ϵͳ�и���Դ��������:" << std::endl;
	for (size_t i = 0; i < resouceNum; i++)
	{
		std::cin >> available[i];
	}

	
	for (size_t i = 0; i < processNum; i++)
	{
		std::cout << "���������" << i << "����Դ�����������:" << std::endl;
		for (size_t j = 0; j < resouceNum; j++)
		{
			
			std::cin >> max[i][j];
			
		}
	}

	
	for (size_t i = 0; i < processNum; i++)
	{
		std::cout << "���������" << i << "����Դ���ѷ�������:" << std::endl;
		for (size_t j = 0; j < resouceNum; j++)
		{
			
			std::cin >> allocation[i][j];
		}
	}


	std::cout << "��Դ�������" << std::endl;
	std::cout << "--------------" << std::endl;
	Banker* banker = new Banker(ResouceName, available, max, allocation);

	return banker;
}