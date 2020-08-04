#pragma once
#include<mutex>

namespace lee
{
	template<class Mutex>
	class lock_guard
	{
	public:
		lock_guard(Mutex& mtx)
			:_mtx(mtx)
		{
			_mtx.lock();
		}

		~lock_guard()
		{
			_mtx.unlock();
		}

		//防拷贝
		lock_guard(const lock_guard<Mutex>&) = delete;
		lock_guard<Mutex>& operator=(const lock_guard<Mutex>&) = delete;
	private:
		//保证操作的是同一个锁，需要使用引用
		Mutex &_mtx;
	};
};