/*
Fibonacci数列
https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
*/
#include<iostream>
using namespace std;

int main()
{
    int prev = 0, cur = 1, next = 1;
    int num;
    while(cin >> num)
    {
        int x = 0, y = 0;
        
        while(num > next)
        {
            prev = cur;
            cur = next;
            next = prev + cur;
            
            x = next - num;
            y = num - cur;
        }
        
        int res = x > y ? y : x;
        
        cout << res << endl;
    }
    
    return 0;
}
