/*
三角形
https://www.nowcoder.com/questionTerminal/c67a09062c0f4a5b964eef0945d3dd06
给定三条边，请你判断一下能不能组成一个三角形。
*/

#include<iostream>
using namespace std;

int main()
{
    double x, y, z;
    
    while(cin >> x >> y >> z)
    {
        if(x == 0 || y == 0 || z == 0)
        {
            cout << "No" << endl;
        }
        //三角形任意两边加起来必须大于第三边
        else if((x + y <= z) || (x + z <= y) || (y + z <= x))
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}
