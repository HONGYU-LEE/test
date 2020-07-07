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

	//运行进程
	void Run()
	{
		std::cout << "---进程" << _processName << "正在运行---" << std::endl;

		--_priority;
		--_time;

		if (!_time)
		{
			_status = 'E';
		}
		std::cout << "进程名: " << _processName << "  优先级: " << _priority << "  剩余运行时间: " << _time << " 状态: " << _status << std::endl;
		std::cout << "---进程" << _processName << "运行结束---" << std::endl;
		std::cout << std::endl;

		//运行时间已满，修改状态为结束
		if (!_time)
		{
			_status = 'E';
		}
	}

	//判断当前状态是否结束
	bool isEnd() const
	{
		return (_status == 'E');
	}

private:
	std::string _processName;	//进程名
	size_t _time;	//运行时间
	int _priority;	//优先数
	char _status;	//状态
	size_t _order;	//顺序
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
			//按照先后顺序以及优先级大小插入到合适的位置
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
		//如果比前面的都小就尾插
		_list.push_back(data);	
	}

	//输出表中所有进程信息
	void Print() const
	{
		std::cout << "--------------------------------" << std::endl;
		for (auto it = _list.begin(); it != _list.end(); it++)
		{
			std::cout << "进程名: " << it->_processName << "  优先级: " << it->_priority << "  剩余运行时间: " << it->_time << " 状态: " << it->_status << std::endl;
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
		//取出队首运行
		auto cur = q._list.front();
		cur.Run();
		q._list.pop_front();

		//如果还没运行完则重新放入表中
		if (!cur.isEnd())
		{
			q.Push(cur);
		}
		else
		{
			std::cout << "进程" << cur._processName << "运行结束， 退出" << std::endl;
		}
		q.Print();
	}
	std::cout << "************调度结束************" << std::endl;
}