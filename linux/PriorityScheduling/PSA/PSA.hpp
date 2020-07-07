#pragma
#include <string>
#include <iostream>
#include <list>
class List;
class PCB
{
public:
	friend class List;
	friend void PSA(List& q);

	PCB(std::string processName, size_t time, size_t priority, size_t order)
		: _processName(processName)
		, _time(time)
		, _priority(priority)
		, _status('R')
		, _order(order)
	{}

	//���н���
	void Run()
	{
		std::cout << "---����" << _processName << "��������---" << std::endl;

		--_priority;
		--_time;

		if (!_time)
		{
			_status = 'E';
		}
		std::cout << "������: " << _processName << "  ���ȼ�: " << _priority << "  ʣ������ʱ��: " << _time << " ״̬: " << _status << std::endl;
		std::cout << "---����" << _processName << "���н���---" << std::endl;
		std::cout << std::endl;

		//����ʱ���������޸�״̬Ϊ����
		if (!_time)
		{
			_status = 'E';
		}
	}

	//�жϵ�ǰ״̬�Ƿ����
	bool isEnd() const
	{
		return (_status == 'E');
	}

private:
	std::string _processName;	//������
	size_t _time;	//����ʱ��
	int _priority;	//������
	char _status;	//״̬
	size_t _order;	//˳��
};

class List
{
public:
	friend void PSA(List& q);

	void Push(const PCB& data)
	{

		auto it = _list.begin();

		while (it != _list.end())
		{
			//�����Ⱥ�˳���Լ����ȼ���С���뵽���ʵ�λ��
			if (data._priority > it->_priority || ((data._priority == it->_priority) && (data._order < it->_order)))
			{
				_list.insert(it, data);
				return;
			}
			else
			{
				it++;
			}
		}
		//�����ǰ��Ķ�С��β��
		_list.push_back(data);	
	}

	//����������н�����Ϣ
	void Print() const
	{
		std::cout << "--------------------------------" << std::endl;
		for (auto it = _list.begin(); it != _list.end(); it++)
		{
			std::cout << "������: " << it->_processName << "  ���ȼ�: " << it->_priority << "  ʣ������ʱ��: " << it->_time << " ״̬: " << it->_status << std::endl;
		}
		std::cout << "--------------------------------" << std::endl;
		std::cout << std::endl;
	}

private:
	std::list<PCB> _list;
};

void PSA(List& q)
{
	while (!q._list.empty())
	{
		//ȡ����������
		auto cur = q._list.front();
		cur.Run();
		q._list.pop_front();

		//�����û�����������·������
		if (!cur.isEnd())
		{
			q.Push(cur);
		}
		else
		{
			std::cout << "����" << cur._processName << "���н����� �˳�" << std::endl;
		}
		q.Print();
	}
	std::cout << "************���Ƚ���************" << std::endl;
}