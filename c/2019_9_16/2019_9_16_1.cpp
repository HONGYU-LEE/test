#include<iostream>
#include<math.h>
using namespace std;
//ÅĞ¶ÏÊÇ·ñÎªËØÊı
bool isPrimeNum(int num)
{
    int i = 0;
    for(i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    
    if(i > sqrt(num))
        return true;
    
    return false;
}
int main()
{
    int num;
        
    while(cin >> num)
    {
        //
        for(int i = 1; i < num; i++)
        {
            if(isPrimeNum(i) && (i % 10 == 1))
                cout << i << ' ';
            else
                cout << -1 << ' ';
            
        }

    }
    return 0;
}
