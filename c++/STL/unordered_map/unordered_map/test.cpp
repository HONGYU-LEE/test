#include"unordered_map.hpp"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	lee::unordered_map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("left", "���"));
	dict.insert(make_pair("string", "�ַ���"));
	dict["left"] = "ʣ��";
	dict["end"] = "β��";

	//unordered_map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}

	return 0;
}