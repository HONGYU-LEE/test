// write your code here cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long num;
    
    while(cin >> num)
    {
        if(num == 0)
            break;
        
        cout << (long long)pow(5, num) - 4 << " " << (long long)pow(4, num) + num - 4 << endl;
    }
    return 0;
}
