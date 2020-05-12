#pragma once
#include<iostream>
#include<cstring>
#include<cassert>


namespace lee
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		friend std::ostream& operator<<(std::ostream& _cout, const string& s);
		friend std::istream& operator>>(std::istream& _cin, string& s);

		//���캯��
		string(const char* str = "")
			: _size(strlen(str))
			, _capacity(_size)
			, _str(new char[_size + 1])
		{
			strcpy(_str, str);
		}

		/*
		//�������캯��
		//��ͳд�����ռ俽����
		string(const string& s)
			: _size(s._size)
			, _capacity(s._capacity)
			, _str(new char[_size + 1])
		{
			strcpy(_str, s._str);
		}
		*/

		//�ִ�д����ֱ�ӹ���һ����ʱ����Ȼ����Ǹ���ʱ������н�����������ȥ�������ں�������������
		string(const string& s)
			: _size(0)
			, _capacity(0)
			, _str(nullptr)
		{
			string temp(s._str);
			swap(temp);
		}

		/*
		//��ͳд��,���ռ俽������
		string& operator=(const string& s)
		{
			//��ͬ�򲻽���
			if (this != &s)
			{
				char* str = new char[strlen(s._str) + 1];
				strcpy(str, s._str);
				delete[] _str;

				_str = str;

			}

			return *this;
		}
		*/

		//�ִ�д��,ֱ���ù��캯������Ȼ�󽻻�
		string& operator=(const string& s)
		{
			string temp(s._str);
			swap(temp);

			return *this;
		}

		//��������
		~string()
		{
			_size = _capacity = 0;
			delete[] _str;
			_str = nullptr;
		}

		/*
			------------------------------------------------------------
			��������
			Capacity
			------------------------------------------------------------
		*/

		//����capacity
		size_t capacity() const
		{
			return _capacity;
		}

		//����size
		size_t size() const
		{
			return _size;
		}

		//���Ϊ�շ���true,��Ϊ�շ���false
		bool empty() const
		{
			return !_size;
		}

		//���·���size
		void resize(size_t newSize, char c = '\0')
		{
			//���size����������
			if (_size < newSize)
			{
				//���capacity����������reserve����
				if (_capacity < newSize)
				{
					reserve(newSize);
				}

				//������Ŀռ�ȫ����ʼ��Ϊc
				memset(_str + _size, c, newSize - _size);
			}

			//���ռ乻��ʱ��ֱ�ӽض�����
			_size = newSize;
			_str[_size] = '\0';
		}

		//���·���capacity
		void reserve(size_t newCapacity)
		{
			if (_capacity >= newCapacity)
				return;


			char* str = new char[newCapacity + 1];
			strcpy(str, _str);
			delete[] _str;

			_str = str;
			_capacity = newCapacity;
		}

		/*
			------------------------------------------------------------
			����������
			Iterators:
			------------------------------------------------------------
		*/

		//�ײ���������
		iterator begin()
		{
			return _str;
		}

		//β��������
		iterator end()
		{
			return _str + _size;
		}

		//�ײ�����������
		const_iterator cbegin() const
		{
			return _str;
		}

		//β������������
		const_iterator cend() const
		{
			return _str + _size;
		}

		/*
			------------------------------------------------------------
			�޸Ĳ���
			Modifiers:
			------------------------------------------------------------
		*/

		//��ĳ��λ�ú�����ַ�
		string& insert(size_t pos, char c)
		{
			assert(pos < _size);

			if (_capacity == _size)
			{
				size_t newcapacity = (_capacity == 0) ? 2 : 2 * _capacity;

				reserve(newcapacity);
			}

			//���ݺ���
			for (size_t i = _size; i > pos; i--)
			{
				_str[i] = _str[i - 1];
			}


			_str[pos] = c;
			_str[++_size] = '\0';

			return *this;
		}

		//��ĳ��λ�ú�����ַ���
		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t size = strlen(str);

			//�������������������
			if (size + _size > _capacity)
			{
				reserve(size + _size);
			}

			//���ݺ���size��λ��
			for (size_t i = _size + size - 1; i > pos + size - 1; i--)
			{
				_str[i] = _str[i - size];
			}

			//�������ݵ���pos��λ��
			memcpy(_str + pos, str, size);
			_size += size;

			return *this;
		}

		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
		string& erase(size_t pos, size_t len = npos)
		{
			//����Ǹ�λ�ú���û����ô�����ݣ���ֱ�Ӵ��Ǹ�λ�ýضϣ�ɾ��������������
			if (len >= _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				//������ɾ����ǰ��pos��λ��
				for (size_t i = pos + len; i <= _size; i++)
				{
					_str[i - len] = _str[i];
				}
			}

			//��������size�ͽ�β��\0
			_size -= len;
			_str[_size] = '\0';
			return *this;
		}
		//β��

		void push_back(char c)
		{
			if (_capacity == _size)
			{
				size_t newcapacity = (_capacity == 0) ? 2 : 2 * _capacity;

				reserve(newcapacity);
			}

			_str[_size++] = c;
			_str[_size] = '\0';
		}

		//βɾ
		void pop_back()
		{
			_str[--_size] = '\0';
		}

		//׷���ַ�
		string& operator+=(char c)
		{
			push_back(c);

			return *this;
		}

		//β��׷���ַ���
		void append(const char* str)
		{
			size_t size = strlen(str);

			//�������������������
			if (size + _size > _capacity)
			{
				reserve(size + _size);
			}

			//β��׷���ַ���
			strcpy(_str + _size, str);
			_size += size;
		}

		//׷���ַ���
		string& operator+=(const char* str)
		{
			append(str);

			return *this;
		}

		//���string
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		//����string
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}



		/*
			------------------------------------------------------------
			Ԫ�ط��ʲ���
			Element access:
			------------------------------------------------------------
		*/

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index) const
		{
			assert(index < _size);
			return _str[index];
		}

		/*
			------------------------------------------------------------
			��ϵ�����
			relational operators:
			------------------------------------------------------------
		*/
		bool operator<(const string& s)
		{
			if (strcmp(_str, s._str) == -1)
				return true;
			else
				return false;
		}

		bool operator<=(const string& s)
		{
			return (*this < s) || (*this == s);
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator==(const string& s)
		{
			if (strcmp(_str, s._str) == 0)
				return true;
			else
				return false;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		/*
		------------------------------------------------------------
		�ַ�������
		String operations:
		------------------------------------------------------------
		*/
		//����C�����ַ���
		const char* c_str() const
		{
			return _str;
		}

		//�����ַ�c��һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const
		{
			assert(pos < _size);
			size_t i = pos;

			while (i < _size)
			{
				if (_str[i] == c)
					return i;

				i++;
			}

			return npos;
		}

		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const
		{
			const char* src = _str;
			const char* sub = s;

			while (*src)
			{
				//�������λ��ƥ�����������
				while (*src == *sub && *sub)
				{
					src++;
					sub++;
				}
				//���sub�����˵����ȫƥ�䣬����sub��һ�γ��ֵ�λ��
				if ('\0' == *sub)
				{
					return (src - _str - strlen(s));
				}
				//��ƥ������ݣ�����ƥ����һ��λ��
				else
				{
					sub = sub;
					src = ++src;
				}
			}

			return npos;
		}


	private:
		size_t _size;
		size_t _capacity;
		char* _str;
		static size_t npos;
	};

	size_t string::npos = -1;

	std::ostream& operator<<(std::ostream& out, const string& s)
	{
		out << s._str;
		return out;
	}

	std::istream& operator>>(std::istream& in, string& s)
	{
		//ֱ����cin�����str�����޷����ݵ����⣬��Ҫ�ֶ�����
		while (1)
		{
			char ch;
			ch = in.get();
			//�����ָ�������ͣ
			if (ch == '\n' || ch == ' ')
			{
				break;
			}
			else
			{
				s.push_back(ch);
			}
		}
		
		return in;
	}
}