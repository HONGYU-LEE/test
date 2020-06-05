/*
字符串中找出连续最长的数字串
https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
读入一个字符串str，输出字符串str中的连续最长的数字串
*/ 

/*
	思路：如果当前为数字，则尾插进cur_num中，如果cur_num大于max_num则说明他是最长数字串，更新max。如果当前不为数字，则说明连续中断，清空cur_num重新计数 
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
