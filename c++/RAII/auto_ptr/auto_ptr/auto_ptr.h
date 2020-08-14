namespace lee
{
	/*
		c++98 auto_ptr
		ʵ��˼·:����Ȩת��
		ȱ��:������Ȩת�ƺ�ᵼ�±�ת�Ƶ�ָ�����գ����ʾͻᱨ���������Ϥ�������Ծͻ�����⡣
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
				//�ͷŵ�ǰ��Դ
				if (_ptr)
				{
					delete _ptr;
				}

				//����Ȩת��
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

