/*
星际密码
链接：https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
来源：牛客网
星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，通过一张表里的信息映射成最终4位密码。表的规则是：n对应的值是矩阵X的n次方的左上角，如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
例如n=2时，
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
即2对应的数是“0002”。
https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062

其实就是斐波那契数列
*/
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    //最大数据是10000，所以建立一个1w大小的斐波那契数列表
    //0的位置不存在
    int arr[10001] = {1, 1};
    for(int i = 2; i < 10001; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10000;
    }
    
    int size = 0;
    
    while(cin >> size)
    {
        int index;
        for(int i = 0; i < size; i++)
        {
            cin >> index;
        
            printf("%04d", arr[index]);
        }
        
        cout << endl;
    }
    return 0;
}
