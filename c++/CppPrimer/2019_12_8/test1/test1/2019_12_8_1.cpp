#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Student
{
public:
	Student();
	Student(const Student& s1);
	~Student();
	void display();
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

void Student::display()
{
	cout << name << endl;
}
Student::Student(const Student& s1)
{
	name = new char[30];
	memcpy(name, s1.name, strlen(s1.name));
	cout << "Class construct" << endl;
}
//如果去掉这个构造器就是浅拷贝，只拷贝了地址没有拷贝数值，一旦第一个析构器销毁后因为引用已被销毁的空间将报错。
int main()
{
	Student s1;
	Student s2(s1);
	s1.display();
	s2.display();
	return 0;
}