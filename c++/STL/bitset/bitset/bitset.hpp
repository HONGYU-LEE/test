#pragma once
#include<vector>

namespace lee
{
	class bitset
	{
	public:

		//ÿһ��λ��ʶһ�����ݣ�һ������4���ֽڣ��ɴ洢32��λ, ������Ҫ/32������������λ����+1��Ϊ��ȡ��
		bitset(size_t size = 32) 
			: _bits((size >> 5) + 1, 0)
			, _size(0)
		{}

		//���ݵĶ�Ӧ��ʶλ��1
		void set(size_t x)
		{
			//���������������һ��������
			size_t index = x >> 5;
			//������ڸ����͵���һ��λ��
			size_t pos = x % 32;

			//��Ӧλ�� ��1
			_bits[index] |= (1 << pos);
			++_size;
		}

		//���ݵĶ�Ӧ��ʶλ��0
		void reset(size_t x)
		{
			size_t index = x >> 5;
			size_t pos = x % 32;

			//��Ӧλ����������
			_bits[index] &= ~(1 << pos);
			++_size;
		}
		
		//�ж������Ƿ����
		bool test(size_t x) const
		{
			size_t index = x >> 5;
			size_t pos = x % 32;

			return _bits[index] & (1 << pos);
		}

		size_t size() const
		{
			return _size;
		}

	private:
		std::vector<int> _bits;
		size_t _size;
	};
};