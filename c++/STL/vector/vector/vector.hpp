#pragma once
#include<cassert>

namespace lee
{
	//��ģ��
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		/*
		------------------------------------------------------------
		Ĭ�ϳ�Ա��������
		Member functions
		------------------------------------------------------------
		*/
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{}

		vector(int n, const T& value = T())
		{
			assert(n > 0);

			//ֱ����resize�Ϳ��ԣ�����һ��
			resize(n, value);
		}



		vector(const_iterator first, const_iterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			reserve(last - first);

			//���
			while (first != last)
			{
				*_finish++ = *first++;
			}

			_endOfStorage = _finish;
		}

		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endOfStorage(nullptr)
		{
			/*
			ֱ�ӹ���һ��Ȼ�󽻻�
			vector temp(v.begin(), v.end());
			swap(temp);
			*/

			reserve(v.capacity());

			for (const auto& i : v)
			{
				push_back(i);
			}
		}

		vector<T>& operator=(vector<T> v)
		{
			//ֱ�Ӻ��βν�����������ȥ������Ҳ����ջ֡����ʱ�����
			swap(v);

			return *this;
		}


		~vector()
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}

		/*
		------------------------------------------------------------
		����������
		Iterators:
		------------------------------------------------------------
		*/
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		/*
			------------------------------------------------------------
			��������
			Capacity
			------------------------------------------------------------
		*/

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endOfStorage - _start;
		}

		void reserve(size_t n)
		{
			//����û�����򲻲���
			if (n <= capacity())
				return;

			//������޸ĵ�_finish��_start�����Ժ����޷�����size����
			size_t length = size();
			T* temp = new T[n];

			//�ж�_start�Ƿ�Ϊ�գ���ֹ�ͷſ�ָ��
			if (_start)
			{
				//��������ﲻ����stringһ��ʹ��strcpy����memcpy����Ϊ���������ǰ����ֽڿ���
				//����һ��ԭ�򣬾��Ƕ���ĳЩ������string��memcpy����ʱ��ֱ��ǳ����_str,�ͻ�������⣬�����ʹ�ø�ֵ����Զ����ö�Ӧ���͵����ظ�ֵ�����
				for (size_t i = 0; i < length; i++)
				{
					temp[i] = _start[i];
				}

				delete[] _start;
			}

			_start = temp;
			_finish = _start + length;
			_endOfStorage = _start + n;
		}


		//valueΪ�����͵�ȱʡֵ
		void resize(size_t n, const T& value = T())
		{
			//���ԭ���Ĵ����ʼ�����������
			if (size() < n)
			{
				//�����������������
				if (capacity() < n)
				{
					reserve(n);
				}

				//��������Ĳ��ֳ�ʼ��Ϊvalue
				while (_finish < _start + n)
				{
					*_finish++ = value;
				}
			}
			//���������ԭ����С����ֱ�ӴӶ�Ӧλ�ýض�����
			else
			{
				_finish = _start + n;
			}
		}

		bool empty() const
		{
			return _start == _finish;
		}
		/*
		------------------------------------------------------------
		Ԫ�ط��ʲ���
		Element access:
		------------------------------------------------------------
		*/

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		/*
			------------------------------------------------------------
			�޸Ĳ���
			Modifiers:
			------------------------------------------------------------
		*/

		void push_back(const T& x)
		{
			//��������������
			if (_finish == _endOfStorage)
			{
				size_t newCapacity = capacity() == 0 ? 2 : 2 * capacity();
				reserve(newCapacity);
			}

			*_finish++ = x;
		}

		void pop_back()
		{
			
			assert(_start < _finish);

			_finish--;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endOfStorage, v._endOfStorage);
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);

			//�ռ�����������
			if (_finish == _endOfStorage)
			{
				size_t newCapacity = capacity() == 0 ? 2 : 2 * capacity();
				reserve(newCapacity);
			}

			//���ݺ���
			for (auto i = _finish; i >= pos; i--)
			{
				*i = *(i - 1);
			}

			//�������ݣ����ҽ���λ�ú���
			*pos = x;
			_finish++;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos <= _finish);

			//����ǰ��
			for (auto i = pos; i <= _finish; i++)
			{
				*i = *(i + 1);
			}

			_finish--;
			return pos;
		}

		void clear()
		{
			_finish = _start;
		}

	private:
		iterator _start; // ָ�����ݵĿ�ʼ
		iterator _finish; // ָ�����ݵĽ���
		iterator _endOfStorage; // ָ��洢������β
	};
}