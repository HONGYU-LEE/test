/*
΢�ź��
https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?tpId=49&&tqId=29311&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��

����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�

��û�н���������һ�룬����0��
*/

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        //Ħ��ͶƱ��
        int res = gifts[0], count = 1;
        
        for(size_t i = 1; i < gifts.size(); i++)
        {
            if(count == 0)
            {
                res = gifts[i];
                count = 1;
            }
            else if(gifts[i] != res)
            {
                count--;
            }
            else
            {
                count++;
            }
        }
        count = 0;
        for(size_t i = 0; i < gifts.size(); i++)
        {
            if(gifts[i] == res)
                count++;
        }
        
        if(count >= (gifts.size() / 2))
            return res;
        else
            return 0;
    }
};
