#include<iostream>
#include<string>
#include<vector>
#include<cassert>

class Banker
{
public:
	std::vector<std::string> _ResouceName; //资源名

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
		//计算出需要的资源数
		for (size_t i = 0; i < _processNum; i++)
		{	
			for (size_t j = 0; j < _resouceNum; j++)
			{
				_need[i][j] = _max[i][j] - _allocation[i][j];
			}
		}
	}

	//封装给外界获取数量的接口
	int ResouceNum() const
	{
		return _resouceNum;
	}

	int ProcessNum() const
	{
		return _processNum;
	}

	//输出安全序列
	void printSecurity()
	{
		std::cout << "--------------" << std::endl;
		std::cout << "安全序列为: " ;
		for (auto it : _Security)
		{
			std::cout << it << std::ends;
		}
		std::cout << "--------------" << std::endl;
		std::cout << std::endl;
	}

	//输出函数
	void OutPut()
	{
		std::cout << "*************************************" << std::endl;
		std::cout << "当前进程数:" << _processNum  << "  当前资源种类数量:" << _resouceNum << std::endl;

		for (size_t i = 0; i < _resouceNum; i++)
		{
			std::cout << "资源" << _ResouceName[i] << "可用数量为: " << _available[i] << std::endl;
		}

		std::cout << "--------------" << std::endl;
		for (size_t i = 0; i < _processNum; i++)
		{
			std::cout << "进程" << i << std::endl;

			for (size_t j = 0; j < _resouceNum; j++)
			{
				std::cout << "资源" << _ResouceName[j] << " 最大需求数量为: " << _max[i][j] << " 当前分配数量为: " << _allocation[i][j] << " 剩余需求数量为: " << _need[i][j] << std::endl;
			}
		}
		std::cout << "*************************************" << std::endl;
	}

	//银行家算法核心，判断请求算法
	bool CheckRequest(size_t pid, std::vector<int> request)
	{
		//检查资源请求是否合理
		for (size_t i = 0; i < _resouceNum; i++)
		{
			//需求资源数已经超过最大值
			if (request[i] > _need[pid][i])
			{
				std::cout << "需求资源数已经超过最大值" << std::endl;
				return false;
			}
				
			//尚无足够资源
			if (request[i] > _available[i])
			{
				std::cout << "尚无足够资源，进程等待" << std::endl;
				return false;
			}				
		}

		//尝试分配资源给进程，看看此次分配后系统是否处于安全状态
		for (size_t i = 0; i < _resouceNum; i++)
		{
			_available[i] -= request[i];
			_allocation[pid][i] += request[i];
			_need[pid][i] -= request[i];
		}

		//检查分配后系统是否安全
		if (CheckSafe() == true)
		{
			//分配后系统安全，正式分配
			std::cout << "本次资源" << pid << "分配成功" << std::endl;
			OutPut();

			return true;
		}
		else
		{
			//分配后不安全，分配失效，资源恢复
			std::cout << "本次资源分配后系统不安全，分配作废" << std::endl;
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



	//安全性算法
	bool CheckSafe()
	{
		std::vector<int> work(_available);   //表示系统可提供给进程继续运行所需的各类资源数目
		std::vector<bool> finish(_processNum, false);    //表示系统是否有足够的资源分配给该进程

		while (1)
		{
			size_t i = 0;
			//检查是否全部都处于安全状态
			for (i = 0; i < _processNum; i++)
			{
				if(finish[i] == false)
					break;
			}

			//如果全都处于安全状态，则说明此时系统也处于安全状态
			if (i == _processNum)
			{
				std::cout << "系统此时安全" << std::endl;
				return true;
			}

			for (i = 0; i < _processNum; i++)
			{
				//如果这个进程已经执行过，则跳过
				if (finish[i] == true)
				{
					continue;
				}
					
				//标志当前进程分配资源后是否安全
				bool flag = true;

				for (size_t j = 0; j < _resouceNum; j++)
				{
					//如果某一项资源不够分配，则说明当前进程不能执行，继续判断后面的
					if (_need[i][j] > work[j])
					{
						flag = false;
						break;
					}
				}

				if (flag == true)
				{
					std::cout << "执行进程" << i << " ,系统可利用资源更新" << std::endl;
					//加入安全序列中
					_Security.push_back(i);

					//调用进程运行，并且释放进程所占资源
					for (size_t j = 0; j < _resouceNum; j++)
					{
						work[j] += _allocation[i][j];
						finish[i] = true;

						std::cout << "可用资源"<< _ResouceName[j] << "更新为: " << work[j] << std::endl;
					}

					break;
					//调用完后进入下一轮查找安全进程
				}
			}

			//如果进程全部遍历完也没有任何一个执行，则说明此时无法分配，不安全
			if (i == _processNum)
			{
				std::cout << "系统此时不安全" << std::endl;
				return false;
			}
				
		}
	}

private:
	friend Banker* Input();		//输入函数	
	std::vector<int> _available;	//系统可利用的各类资源数目
	std::vector< std::vector<int >> _max;	//每一个进程对各种资源的最大需求
	std::vector< std::vector<int >> _allocation;	//系统中每一类资源当前已分配给每一进程的资源数
	std::vector< std::vector<int >> _need;	//每一个进程尚需的各类资源数
	std::vector<int> _Security; //安全序列
	size_t _processNum;	//进程数
	size_t _resouceNum;	//资源数
};

//输入函数
Banker* Input()
{
	size_t processNum, resouceNum;
	std::cout << "请输入进程数量:" << std::endl;
	std::cin >> processNum;

	std::cout << "请输入资源种类数量:" << std::endl;
	std::cin >> resouceNum;

	std::vector<std::string> ResouceName(resouceNum);
	std::vector<int> available(resouceNum);
	std::vector< std::vector<int >> max(processNum, std::vector<int>(resouceNum, 0));
	std::vector< std::vector<int >> allocation(processNum, std::vector<int>(resouceNum, 0));

	std::cout << "请输入资源名:" << std::endl;
	for (size_t i = 0; i < resouceNum; i++)
	{
		std::cin >> ResouceName[i];
	}

	std::cout << "请输入系统中该资源空闲数量:" << std::endl;
	for (size_t i = 0; i < resouceNum; i++)
	{
		std::cin >> available[i];
	}

	
	for (size_t i = 0; i < processNum; i++)
	{
		std::cout << "请输入进程" << i << "中资源的最大需求量:" << std::endl;
		for (size_t j = 0; j < resouceNum; j++)
		{
			
			std::cin >> max[i][j];
			
		}
	}

	
	for (size_t i = 0; i < processNum; i++)
	{
		std::cout << "请输入进程" << i << "中资源的已分配数量:" << std::endl;
		for (size_t j = 0; j < resouceNum; j++)
		{
			
			std::cin >> allocation[i][j];
		}
	}


	std::cout << "资源输入完毕" << std::endl;
	std::cout << "--------------" << std::endl;
	Banker* banker = new Banker(ResouceName, available, max, allocation);

	return banker;
}