/*
链接：https://www.nowcoder.com/questionTerminal/c0a4b917a15f40a49ca10532ab9019fb
来源：牛客网
斐波那契凤尾
NowCoder号称自己已经记住了1-100000之间所有的斐波那契数。
为了考验他，我们随便出一个数n，让他说出第n个斐波那契数。当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。
*/

//超过6位时就只保留后六位数值即可 
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
    //先计算完再根据输入来查找。
    vector<int> res(100001, 0);
    res[0] = 1;
    res[1] = 1;
    for(size_t i = 2; i < 100001; i++)
    {
        res[i] = res[i - 1] + res[i - 2];
            
        if(res[i] > 999999)
        {
            res[i] %= 1000000;
        }
    }
    
    int num;
    
    while(cin >> num)
    {
        //超过六位数才补0
        if(num > 29)
            cout << setfill('0') << setw(6) << res[num] << endl;
        else
            cout << res[num] << endl;
    }
    
    return 0;
}
