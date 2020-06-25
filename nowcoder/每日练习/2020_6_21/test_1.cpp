/*
汽水瓶 
https://www.nowcoder.com/practice/fe298c55694f4ed39e256170ff2c205f?tpId=37&&tqId=21245&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
有这样一道智力题：“某商店规定：三个空汽水瓶可以换一瓶汽水。小张手上有十个空汽水瓶，她最多可以换多少瓶汽水喝？”答案是5瓶，方法如下：先用9个空瓶子换3瓶汽水，喝掉3瓶满的，喝完以后4个空瓶子，用3个再换一瓶，喝掉这瓶满的，这时候剩2个空瓶子。然后你让老板先借给你一瓶汽水，喝掉这瓶满的，喝完以后用3个空瓶子换一瓶满的还给老板。如果小张手上有n个空汽水瓶，最多可以换多少瓶汽水喝？
*/

#include<iostream>
#include<vector>

using namespace std;
int main()
{
    int num;
    
    while(cin >> num)
    {
        int count = 0;
        int empty = num;
        int lost = num;
        
        while(empty > 2)
        {
            lost = empty % 3;
            empty /= 3;
            count += empty;
            
            empty += lost;
            
            if(empty == 2)
            {
                count++;
                break;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
