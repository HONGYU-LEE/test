/*
https://www.nowcoder.com/questionTerminal/71d3849a19f04a1591c415964ac148f1
养兔子
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。
*/
//斐波那契数列
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<long long> res(91);
    res[0] = 1;
    res[1] = 1;
    
    for(size_t i = 2; i < 91; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
    }
    
    int num;
    
    while(cin >> num)
    {
        cout << res[num] << endl;
    }
    return 0;
}

