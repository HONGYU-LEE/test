#include<unordered_map>
#include<list>

using namespace std;

class LRUCache
{
public:
	LRUCache(size_t capacity)
		: _capacity(capacity)
	{}

	int get(int key) 
	{
		auto ret = _hashmap.find(key);

		//���ҳɹ�
		if (ret != _hashmap.end())
		{
			//��ȡ���ݵ�λ��
			list<pair<int, int>>::iterator pos = ret->second;
			pair<int, int> kv = *pos;

			//�������ƶ�������
			_lrulist.erase(pos);
			_lrulist.push_front(kv);

			ret->second = _lrulist.begin();

			return kv.second;
		}
		//����ʧ�ܷ���-1
		else
		{
			return -1;
		}
	}

	void put(int key, int value) 
	{
		//�����ж������Ƿ���ڣ����ж��ǲ��뻹�Ǹ���
		auto ret = _hashmap.find(key);

		//������ݴ��ڣ����Ǹ���
		if (ret != _hashmap.end())
		{
			list<pair<int, int>>::iterator pos = ret->second;
			_lrulist.erase(pos);

			_lrulist.push_front(make_pair(key, value));
			ret->second = _lrulist.begin();
		}
		//����������ɾ��
		else
		{
			//��������
			if (_lrulist.size() == _capacity)
			{
				//ɾ�����δʹ�õ�����
				pair<int, int> back = _lrulist.back();
				_lrulist.pop_back();
				_hashmap.erase(back.first);
			}
			//��������
			_lrulist.push_front(make_pair(key, value));
			_hashmap.insert(make_pair (key, _lrulist.begin()));
		}
	}

private:
	//���ù�ϣ�����洢�����Լ�����������ʵ��o(1)��get��put
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
	//����˫�����������滺��ʹ�����������֤o(1)�Ĳ���ɾ��
	list<pair<int, int>> _lrulist;
	size_t _capacity;
};