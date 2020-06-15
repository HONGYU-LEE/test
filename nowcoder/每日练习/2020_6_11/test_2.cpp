/*
密码强度等级
https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
*/

#include<iostream>

using namespace std;

int countNum(const string& str)
{
    int count = 0;
    for(const auto& i : str)
    {
        if(i >= '0' && i <= '9')
            count++;
    }
    
    if(count == 1)
        return 10;
    else if(count > 1)
        return 20;
    else 
        return 0;
}

int countCh(const string& str)
{
    int big = 0, small = 0;
    for(const auto& i : str)
    {
        if(i >= 'a' && i <= 'z')
            small++;
        else if(i >= 'A' && i <= 'Z')
            big++;
    }
    
    if((!big && small) || (big && !small))
        return 10;
    else if(big && small)
        return 20;
    else 
        return 0;
}

int countSymbol(const string& str)
{
    int count = 0;
    for(const auto& i : str)
    {
        if(  !(i >= 'a' && i <= 'z')
          && !(i >= 'A' && i <= 'Z')
          && !(i >= '0' && i <= '9') )
            count++;
    }
    
    if(count == 1)
        return 10;
    else if(count >1)
        return 25;
    else 
        return 0;
}

int main()
{
    string str;
    
    while(cin >> str)
    {
        int sum = 0, ch, symbol, num, length;
        length = str.size();
        
        if(length >= 8)
            sum += 25;
        else if(length >=5)
            sum += 10;
        else 
            sum += 5;
        
        symbol = countSymbol(str);
        num = countNum(str);
        ch = countCh(str);
        
        if(ch && symbol && (ch == 20) && num)
            sum += 5;
        else if(ch && num && symbol)
            sum += 3;
        else if(ch && num)
            sum += 2;
        
        sum = sum + num + ch + symbol;

        if(sum >= 90)
            cout << "VERY_SECURE" << endl;
        else if(sum >= 80)
            cout << "SECURE" << endl;
        else if(sum >= 70)
            cout << "VERY_STRONG" << endl;
        else if(sum >= 60)
            cout << "STRONG" << endl;
        else if(sum >= 50)
            cout << "AVERAGE" << endl;
        else if(sum >= 25)
            cout << "WEAK" << endl;
        else if(sum >= 0)
            cout << "VERY_WEAK" << endl;
    }
    
    return 0;
}
