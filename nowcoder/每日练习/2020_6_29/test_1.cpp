/*
变态跳台阶
https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/


/*
根据结果总结规律，每层是上一层两倍 
*/
class Solution {
public:
    //根据数学归纳得出，每层的次数是上一层的两倍
    
    int jumpFloorII(int number) {
        if(number == 1)
            return 1;
        
        return 2 * jumpFloorII(number - 1);
    }
};
