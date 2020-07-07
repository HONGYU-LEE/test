#include<iostream>
#include<strstream>
using namespace std;

int main()
{
	char str[12];
	char str1[6] = "hello";
	char str2[6] = "world";
	ostrstream strout(str, 12, ios::out);
	strout << str1 << ' ' << str2 << ends;
	cout << str << endl;
	return 0;
}