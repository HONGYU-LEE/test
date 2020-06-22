/*
超长正整数相加
https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&&tqId=21301&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        string res;
        int next = 0, cur, temp;
        int i = s1.size() - 1, j = s2.size() - 1;
        int x, y;

        while(i >= 0 || j >= 0)
        {
            if(i >= 0)
                x = s1[i--] - '0';
            else
                x = 0;
            
            if(j >= 0)
                y = s2[j--] - '0';
            else 
                y = 0;
            
            temp = next + x + y;
            next = 0;
            
            if(temp > 9)
            {
                temp -= 10;
                next = 1;
            }
            
            res += (temp + '0');
        }
        if(next)
            res += '1';
        
        reverse(res.begin(), res.end());

        
        cout << res << endl;
    }
    return 0;
}
