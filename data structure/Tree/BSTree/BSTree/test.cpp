#include"BSTree_V.hpp"

using namespace std;

int main()
{
	lee::BSTree<int> tree;
	tree.Insert(3);
	tree.Insert(5);
	tree.Insert(7);
	tree.Insert(9);
	tree.Insert(1);
	tree.Insert(4);


	tree.InordTravel();


	return 0;
}