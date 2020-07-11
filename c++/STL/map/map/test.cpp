#include<iostream>
#include"map.hpp"
#include<string>
using namespace std;

template<class K, class V>
struct MapKeyOfValue
{
	const K& operator()(const std::pair<K, V>& kv)
	{
		return kv.first;
	}
};
int main()
{
	lee::map<int, string> map;

	map.insert(make_pair(3, "hello"));
	map.insert(make_pair(4, "word"));
	map.insert(make_pair(9, "sky"));
	map.insert(make_pair(5, "walk"));
	map.insert(make_pair(1, "olive"));
	map.insert(make_pair(546, "barry"));
	string strs[] = { "����", "ӣ��", "����", "ƻ��", "����", "����", "����", "ƻ��" };
	lee::map<string, int> countMap;
	for (auto& str : strs)
	{
		// 1�����ˮ������map�У���operator[]�����pair<str, 0>, ����ӳ�����(����)�����ý�����++��
		// 2�����ˮ����map�У���operator[]����ˮ����Ӧ��ӳ�����(����)�����ã�����++��
		countMap[str]++;
	}

	for (auto kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}


}