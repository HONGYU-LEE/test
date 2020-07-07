#include<iostream>

using namespace std;

class division
{
public:
	division(int i, int j);
	~division();
	int divide();
private:
	int x;
	int y;
};

division::division(int i, int j)
{
		x = i, y = j;

		cout << "Class construct" << endl;
}

int division::divide()
{
	if (y == 0) 
		throw y;
	cout << x << " / " << y << " = ";
	return x / y;
}
division::~division()
{
	cout << "Class Destruction" << endl;
}
int main()
{
	division s1(0, 5);
	division s2(4, 0);
	division s3(4, 4);

	try
	{
		cout << s1.divide() << endl;
		cout << s2.divide() << endl;
		cout << s3.divide() << endl;
	}
	catch (int y)
	{
		cout << "Capture exception" << endl;
	}
	return 0;
}