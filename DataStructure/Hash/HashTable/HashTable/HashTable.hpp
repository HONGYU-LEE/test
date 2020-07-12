#pragma once
#include<vector>

namespace lee
{
	//�㷨��ѧ���ܽ����һ�����������������������ݵ�Ч�ʸ���
	const int PRIMECOUNT = 28;
	const size_t primeList[PRIMECOUNT] = 
	{
	 53ul, 97ul, 193ul, 389ul, 769ul,
	 1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
	 49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
	 1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
	 50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
	 1610612741ul, 3221225473ul, 4294967291ul
	};

	enum State
	{
		EMPTY,
		EXITS,
		DELETE,
	};


	template<class T>
	struct HashData
	{
		HashData(const T& data = T(), const State& state = EMPTY)
			: _data(data)
			, _state(state)
		{}

		T _data;
		State _state;
	};

	template<class K, class T, class KeyOfT>
	class HashTable
	{
	public:
		typedef HashData<T> HashData;

		HashTable(size_t capacity = 10)
			: _table(capacity)
			, _size(0)
		{}

		size_t getNextPrime(size_t num)
		{
			size_t i = 0;

			for (i = 0; i < PRIMECOUNT; i++)
			{
				//���ر��Ǹ��������һ������ 
				if (primeList[i] > num)
				{
					return primeList[i];
				}
			}

			//��������ж��󣬻��Ƿ������һ������Ϊ���һ���Ѿ���32λ�������
			return primeList[PRIMECOUNT - 1];
		}

		//����������
		size_t HashFunc(const K& key)
		{
			return key % _table.size();
		}

		bool Insert(const T& data)
		{
			KeyOfT koft;
			//�жϴ�ʱ�Ƿ���Ҫ����
			//��װ�����Ӵ���0.7ʱ����
			if (_size * 10 / _table.size() >= 7)
			{
				//���ݵĴ�С���ձ�����õĽ�����������������������Ч�ʸ��ߣ�Ҳ����ֱ��2������1.5����
				std::vector<HashData> newTable(getNextPrime(_size));

				for (size_t i = 0; i < _table.size(); i++)
				{
					//���ɱ��е�����ȫ������ӳ�䵽�±���
					if (_table[i]._state == EXITS)
					{
						//���������ͻ�����ҵ�һ�����ʵ�λ��
						size_t index = HashFunc(koft(_table[i]._data));

						while (newTable[i]._state == EXITS)
						{
							i++;

							if (i == _table.size())
							{
								i = 0;
							}
						}

						newTable[i] = _table[i];
					}
				}

				//���ֱ�ӽ����ݽ��н������ɣ�ԭ�������ݻ����ź���ջ֡һ������
				_table.swap(newTable);
			}
			
			//�ù�ϣ���������ӳ���λ��
			size_t index = HashFunc(koft(data));

			//���Ǹ�λ�ÿ�ʼ̽��, �����λ���Ѿ�����ʱ�������������һ�����Ѿ����ڣ�һ���ǳ�ͻ������ʹ�õ�������̽��
			while (_table[index]._state == EXITS)
			{
				//����Ѿ������ˣ���˵�����ò���
				if (koft(_table[index]._data) == koft(data))
				{
					return false;
				}
				else
				{
					index++;
					index = HashFunc(index);
				}
			}

			//����ߵ����˵�����λ���ǿյĻ����Ѿ���ɾ����λ�ã��������������
			_table[index]._data = data;
			_table[index]._state = EXITS;
			_size++;

			return true;
		}

		HashData* Find(const K& key)
		{
			KeyOfT koft;
			size_t index = HashFunc(key);

			//������������ҵ�λ��Ϊ�գ���˵������ʧ��
			while (_table[index]._state != EMPTY)
			{
				//��ʱ�ж����λ�õ������Ƿ���ͬ�������ͬ��˵�����ֹ�ϣ��ͻ�������������
				if (koft(_table[index]._data) == key)
				{
					//��ʱ������״̬��һ���������Ѿ���ɾ����һ�������ݴ��ڡ�
					if (_table[index]._state == EXITS)
					{
						return &_table[index];
					}
					else if (_table[index]._state == DELETE)
					{
						return nullptr;
					}
				}

				index++;

				//���indexԽ�磬�����
				if (index == _table.size())
				{
					index = 0;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData* del = Find(key);

			//����Ҳ�����˵���Ѿ���ɾ��
			if (del == nullptr)
			{
				return false;
			}
			else
			{
				//�ҵ�����ֱ�Ӹ���״̬����
				del->_state = DELETE;
				_size--;
				return true;
			}
		}

	private:
		std::vector<HashData> _table;
		size_t _size;
	};
};