#include<iostream>
#include<string>
using namespace std;

template<class T>
void OutputArray(const T* array, const int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

int main()
{

	int array1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int count_1 = sizeof(array1) / sizeof(array1[0]);
	cout << "array1 cout contains:" << endl;
	OutputArray(array1, count_1);

	double array2[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1 };
	int count_2 = sizeof(array2) / sizeof(array2[0]);
	cout << "array2 cout contains:" << endl;
	OutputArray(array2, count_2);

	char array3[12] = "helloworld";
	int count_3 = strlen(array3);
	cout << "array3 cout contains:" << endl;
	OutputArray(array3, count_3);

	return 0;
}