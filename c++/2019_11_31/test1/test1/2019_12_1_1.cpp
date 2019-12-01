#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	ofstream outfile;
	outfile.open("test.dat", ios::out | ios::binary);
	char str[] = "hello world";
	int size = strlen(str);
	outfile.write(str, size);
	outfile.close();
	return 0;
}