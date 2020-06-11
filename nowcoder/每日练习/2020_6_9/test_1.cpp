/*
	两种排序方法
	https://www.nowcoder.com/practice/839f681bf36c486fbcc5fcb977ffe432?tpId=85&&tqId=29844&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
	考拉有n个字符串字符串，任意两个字符串长度都是不同的。考拉最近学习到有两种字符串的排序方法： 1.根据字符串的字典序排序。例如：
"car" < "carriage" < "cats" < "doggies < "koala"
2.根据字符串的长度排序。例如：
"car" < "cats" < "koala" < "doggies" < "carriage"
考拉想知道自己的这些字符串排列顺序是否满足这两种排序方法，考拉要忙着吃树叶，所以需要你来帮忙验证。
*/
 
/*
	直接遍历，通过比较大小和字节序来判断即可 
*/ 

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    size_t size = 0;
    bool flag1 = true, flag2 = true;
    
    while(cin >> size)
    {
        vector<string> str(size);
        
        for(size_t i = 0; i < size; i++)
        {
            cin >> str[i];
        }
        
        for(size_t i = 1; i < size; i++)
        {
            if(str[i] <= str[i - 1])
            {
                flag1 = false;
                break;
            }
        }
        
        for(size_t i = 1; i < size; i++)
        {
            if(str[i].size() <= str[i - 1].size())
            {
                flag2 = false;
                break;
            }
        }
        
        if(flag1 && flag2)
        {
            cout << "both" << endl;
        }
        else if(flag1 && !flag2)
        {
            cout << "lexicographically" << endl;
        }
        else if(!flag1 && flag2)
        {
            cout << "lengths" << endl;
        }
        else
        {
            cout << "none" << endl;
        }
    }
    return 0;
}
