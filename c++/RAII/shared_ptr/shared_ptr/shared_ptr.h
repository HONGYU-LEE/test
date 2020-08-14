#pragma once
#include<mutex>

namespace lee
{
	template<class T>
	struct DelArray
	{
		void operator()(T* p)
		{
			delete[] p;
		}
	};

	template<class T>
	struct Del
	{
		void operator()(T* p)
		{
			delete p;
		}
	};

	struct Free
	{
		void operator()(void* p)
		{
			free(p);
		}
	};
	
	struct Fclose
	{
		void operator()(FILE* p)
		{
			fclose(p);
		}
	};

	/*
		c++11 shared_ptr
		实现思路:引用计数
		缺陷:会出现循环引用的问题
	*/
	template<class T, class Delete = Del<T>>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr, Delete del = Del<T>())
			: _ptr(ptr)
			, _pcount(new int(1))
			, _pmtx(new std::mutex)
			, _del(del)
		{}

		shared_ptr(shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)
		{
			//新增指向同一资源的指针，计数器+1
			add_ref_count();
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//释放之前指向的资源
				release();

				//此时指向同一资源，计数器加一
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				add_ref_count();
			}

			return *this;
		}

		~shared_ptr()
		{
			release();
		}

		T& operator *()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get() const
		{
			return _ptr;
		}

		size_t use_count() const 
		{
			return *_pcount;
		}
	private:
		//加锁保证线程安全
		void add_ref_count()
		{
			_pmtx->lock();

			++(*_pcount);

			_pmtx->unlock();
		}

		void release()
		{
			//需要用到一个标志位，当需要释放资源时，就在解锁后把锁给释放了
			bool flag = false;

			_pmtx->lock();
			//如果为0，则释放资源
			if(--(*_pcount) == 0)
			{
				if (_ptr)
				{
					_del(_ptr);
					_ptr = nullptr;
				}

				delete _pcount;
				_pcount = nullptr;
				flag = true;
			}
			_pmtx->unlock();

			if (flag == true)
			{
				delete _pmtx;
				_pmtx = nullptr;
			}
		}

		int* _pcount;
		std::mutex* _pmtx;
		T* _ptr;
		
		Delete _del;
	};
};