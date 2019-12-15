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
//���ȥ���������������ǳ������ֻ�����˵�ַû�п�����ֵ��һ����һ�����������ٺ���Ϊ�����ѱ����ٵĿռ佫����
int main()
{
	Student s1;
	Student s2(s1);
	s1.display();
	s2.display();
	return 0;
}