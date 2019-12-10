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
//���ȥ���������������ǳ������ֻ�����˵�ַû�п�����ֵ��һ����һ�����������ٺ󽫱���
int main()
{
	Student s1;
	Student s2(s1);
	return 0;
}