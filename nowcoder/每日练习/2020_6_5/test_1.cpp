/*
统计回文
https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。花花非常喜欢这种拥有对称美的回文串，生日的时候她得到两个礼物分别是字符串A和字符串B。现在她非常好奇有没有办法将字符串B插入字符串A使产生的字符串是一个回文串。你接受花花的请求，帮助她寻找有多少种插入办法可以使新串是一个回文串。如果字符串B插入的位置不同就考虑为不一样的办法。
例如：
A = “aba”，B = “b”。这里有4种把B插入A的办法：
* 在A的第一个字母之前: "baba" 不是回文
* 在第一个字母‘a’之后: "abba" 是回文
* 在字母‘b’之后: "abba" 是回文
* 在第二个字母'a'之后 "abab" 不是回文
所以满足条件的答案为2 
*/

//思路：直接暴力解法，分别在每一个位置插入字符串，然后判断是否为回文后计数即可 
 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isReverse(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    
    return temp == str;
}
int main()
{
    string s1, s2;
    
    while(getline(cin, s1) && getline(cin, s2))
    {
        int count = 0;
        
        for(size_t i = 0; i <= s1.size(); i++)
        {
            string temp = s1;
            temp.insert(i, s2);
            
            if(isReverse(temp) == true)
                count++;
        }
        
        cout << count << endl;
    }
    return 0;
}
