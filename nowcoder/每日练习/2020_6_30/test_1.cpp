/*
https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
*/

class Solution {
public:
    int Add(int num1, int num2)
    {
        int carry, sum;
        
        while(carry)
        {
            sum = num1 ^ num2;
            carry = unsigned(num1 & num2) << 1;
            
            num1 = sum;
            num2 = carry;
        }
        
        return sum;
    }
};
