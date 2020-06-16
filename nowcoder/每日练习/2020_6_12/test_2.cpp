/*
求最大连续bit数
https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
输入: 一个byte型的数字
输出: 无
返回: 对应的二进制数字中1的最大连续数
*/
/*
思路，遍历32位，每次判断当前位是否为1，如果连续则计数，不连续则归零重新计数，如果超过最大值则更新 
*/

#include<iostream>

using namespace std;

int main()
{
    int num;
    
    while(cin >> num)
    {
        int count = 0, max = 0;
        for(int i = 0; i < 32; i++)
        {
            if(num % 2 == 1)
                count++;
            else
                count = 0;
            
            num >>= 1;
            
            if(count > max)
                max = count;
        }
        
        cout << max << endl;
    }
    return 0;
}
