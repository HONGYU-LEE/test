/*
数组中出现次数超过一半的数字
https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/ 


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {

		//摩尔投票法，当数字相同时票数加一，数字不同时票数减一，票数为空时更换候选人
		int count = 1;
		int res = numbers[0];

		for (size_t i = 1; i < numbers.size(); ++i)
		{
			//票数为零则为下一个数据投票
			if (!count)
			{
				count = 1;
				res = numbers[i];
			}
			//数据相同，票数加一
			else if (numbers[i] == res)
			{
				++count;
			}
			//数据不同票数减一
			else
			{
				--count;
			}
		}
		
        count = 0;
        //验证是否大于一半 
        for(size_t i = 0; i < numbers.size(); i++)
        {
            if(res == numbers[i])
                count++;
        }
        
        return count > (numbers.size() / 2) ? res : 0;
	}
};
