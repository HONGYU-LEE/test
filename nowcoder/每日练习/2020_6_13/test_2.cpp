/*
查找组成一个偶数最接近的两个素数
https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
*/
#include<iostream>
#include<cmath>

using namespace std;

//判断素数
bool isNum(int num)
{
    int i  = 2;
    for(i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }
    
    if(i > sqrt(num))
        return true;
    else
        return false;
}

int main()
{
    int num;
    
    while(cin >> num)
    {
        //从中间开始向两边找，如果两边都为素数则说明是最接近的，直接输出
        int mid = num / 2;
        int x = mid, y = mid;
        
        for(int i = mid; i > 0; i--)
        {
            x = i;
            y = num - i;
            
            if(isNum(x) && isNum(y))
                break;
        }
        
        cout << x << endl;
        cout << y << endl;
    }
}
