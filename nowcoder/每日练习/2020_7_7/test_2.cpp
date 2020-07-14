// write your code here cpp
/*
剪花布条
https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
一块花布条，里面有些图案，另有一块直接可用的小饰条，里面也有一些图案。对于给定的花布条和小饰条，计算一下能从花布条中尽可能剪出几块小饰条来呢？
*/
/*
判断子串出现的次数 
*/
#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1, str2;
    
    while(cin >> str1 >> str2)
    {
        int count = 0;
        size_t i = 0;
        for(size_t i = 0; i < str1.size(); i++)
        {
            if(str1[i] == str2[0])
            {
                size_t temp = i + 1, j = 1;
                
                for(; j < str2.size(); j++)
                {
                    if(str1[temp] == str2[j])
                    {
                        temp++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(j == str2.size())
                {
                    count++;
                    i = temp - 1;
                }
            }
        }
        cout << count << endl;
    }
    
    return 0;
}
