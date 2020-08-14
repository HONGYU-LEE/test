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
		ʵ��˼·:���ü���
		ȱ��:�����ѭ�����õ�����
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
			//����ָ��ͬһ��Դ��ָ�룬������+1
			add_ref_count();
		}

		shared_ptr<T>& operator=(shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//�ͷ�֮ǰָ�����Դ
				release();

				//��ʱָ��ͬһ��Դ����������һ
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
		//������֤�̰߳�ȫ
		void add_ref_count()
		{
			_pmtx->lock();

			++(*_pcount);

			_pmtx->unlock();
		}

		void release()
		{
			//��Ҫ�õ�һ����־λ������Ҫ�ͷ���Դʱ�����ڽ�����������ͷ���
			bool flag = false;

			_pmtx->lock();
			//���Ϊ0�����ͷ���Դ
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