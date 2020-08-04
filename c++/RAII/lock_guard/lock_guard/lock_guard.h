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

		//������
		lock_guard(const lock_guard<Mutex>&) = delete;
		lock_guard<Mutex>& operator=(const lock_guard<Mutex>&) = delete;
	private:
		//��֤��������ͬһ��������Ҫʹ������
		Mutex &_mtx;
	};
};