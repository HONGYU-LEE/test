#include<iostream>
#include<string>
using namespace std;

class complex
{
public:
	complex(int r, int i) :real(r), imag(i) {};
	friend ostream& operator << (ostream& output, complex& c);

private:
	int real;
	int imag;
};

ostream& operator << (ostream& output, complex& c)
{
	output << '(' << c.real << ',' << c.imag << ')';
	return output;
}
int main()
{
	complex c1(3, 4);
	complex c2(5, 6);
	cout << c1 << endl;
	cout << c2 << endl;

	return 0;
}