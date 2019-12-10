#include<iostream>

using namespace std;

class Student
{
public:
	Student();
	Student(const Student& s1);
	~Student();

private:
	char* name;
};

Student::Student()
{
	name = new char[30];
	cout << "Class construct" << endl;
}

Student::~Student()
{
	delete name;
	cout << "Class Destruction" << endl;
}
Student::Student(const Student& s1)
{
	name = new char[30];
	memcpy(name, s1.name, strlen(s1.name));
	cout << "Class construct" << endl;
}
//如果去掉这个构造器就是浅拷贝，只拷贝了地址没有拷贝数值，一旦第一个析构器销毁后将报错。
int main()
{
	Student s1;
	Student s2(s1);
	return 0;
}