/*
�����г��ִ�������һ�������
https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/ 


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {

		//Ħ��ͶƱ������������ͬʱƱ����һ�����ֲ�ͬʱƱ����һ��Ʊ��Ϊ��ʱ������ѡ��
		int count = 1;
		int res = numbers[0];

		for (size_t i = 1; i < numbers.size(); ++i)
		{
			//Ʊ��Ϊ����Ϊ��һ������ͶƱ
			if (!count)
			{
				count = 1;
				res = numbers[i];
			}
			//������ͬ��Ʊ����һ
			else if (numbers[i] == res)
			{
				++count;
			}
			//���ݲ�ͬƱ����һ
			else
			{
				--count;
			}
		}
		
        count = 0;
        //��֤�Ƿ����һ�� 
        for(size_t i = 0; i < numbers.size(); i++)
        {
            if(res == numbers[i])
                count++;
        }
        
        return count > (numbers.size() / 2) ? res : 0;
	}
};
