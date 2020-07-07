#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	double a = 3.141592653589793;
	cout << a << endl;
	cout.precision(8);
	cout << a << endl;
	cout.precision(10);
	cout << a << endl;
	cout.precision(12);
	cout << a << endl;
	return 0;
}