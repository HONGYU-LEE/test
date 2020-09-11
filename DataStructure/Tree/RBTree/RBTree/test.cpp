//#include"RBTree.hpp"
//
//using namespace std;
//template<class K, class V>
//struct KeyOfValue
//{
//	const K& operator()(const std::pair<K, V>& kv)
//	{
//		return kv.first;
//	}
//};
//
////int main()
////{
////	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
////	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
////	RBTree<int, int, KeyOfValue<int, int>> t;
////	for (auto e : a)
////	{
////		t.Insert(make_pair(e, e));
////	}
////
////	t.InOrder();
////	cout << t.IsValidRBTree() << endl;
////}
//enum Color
//{
//	BLACK,
//	RED,
//};
//
//int main()
//{
//	lee::RBTree<int, pair<int, int> , KeyOfValue<int, int>> t;
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//	}
//
//	auto i = t.begin();
//
//	while (i != t.end())
//	{
//		cout << (*i).first << endl;
//		i++;
//
//	}
//
//
//	//for (auto it : t)
//	//{
//	//	cout << it.first << endl;
//	//}
//
//	return 0;
//}

#include"RBTree_ds.hpp"
using namespace std;

int main()
{
	lee::RBTree<int, string> tree;
	if (tree.Insert(make_pair(1, "hellor")))
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
	
	tree.Insert(make_pair(3, "sky"));
	tree.Insert(make_pair(8, "this"));
	tree.Insert(make_pair(2, "knight"));
	tree.Insert(make_pair(4, "world"));

	tree.InOrderTravel();
}