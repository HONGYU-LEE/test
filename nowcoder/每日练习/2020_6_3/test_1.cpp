/*
�ַ������ҳ�����������ִ�
https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
����һ���ַ���str������ַ���str�е�����������ִ�
*/ 

/*
	˼·�������ǰΪ���֣���β���cur_num�У����cur_num����max_num��˵����������ִ�������max�������ǰ��Ϊ���֣���˵�������жϣ����cur_num���¼��� 
*/
 
#include<string>
#include<iostream>


using namespace std;

int main()
{
	string str;
	string max_num;
	string cur_num;

	getline(cin, str);

	for (auto i : str)
	{
		if (i >= '0' && i <= '9')
		{
			cur_num += i;
		}
		else
		{
			cur_num.clear();
		}

		if (cur_num.size() > max_num.size())
		{
			max_num = cur_num;
		}
	}

	cout << max_num << endl;

	return 0;
}
