namespace lee
{
	/*
		c++98 auto_ptr
		实现思路:管理权转移
		缺陷:当管理权转移后会导致被转移的指针悬空，访问就会报错，如果不熟悉它的特性就会出问题。
	*/
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			: _ptr(ptr)
		{}

		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		auto_ptr(auto_ptr<T>& ap)
			: _ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				//释放当前资源
				if (_ptr)
				{
					delete _ptr;
				}

				//管理权转移
				_ptr = ap._ptr;
				ap._ptr = nullptr;
			}

			return *this;
		}

		T& operator *()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
};

