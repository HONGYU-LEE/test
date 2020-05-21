class Solution {
public:
    /*
      �е������ڻ������ڣ����ʹ���Ŀ��ʱ���ƶ�small,ȥ�������е���Сֵ
      ����С��Ŀ��ʱ���ƶ�big,������������һ�����ֵ,��֤�ܻ�ȡ�������С�
    */
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        vector<int> temp;

        
        int small = 1, big = 2;
        int mid = (target + 1) / 2;
        int count = small + big;
        //���������е����ֵֻ��Ϊ���е��м�ֵ�����Ե�small����midʱ˵���ѱ�����

        while(small < mid)
        {
            //�����Ŀ����ͬ�������ݱ���
            if(count == target)
            {
                temp = addNum(small, big);
                res.emplace_back(temp);
            }

            //�����ǰ�ʹ���Ŀ�꣬smallС��mid��˵����û�����꣬��ʱ������Ԫ���������࣬ȥ����Сֵ��
            while(count > target && small < mid)
            {
                count -= small;
                small++;

                if(count == target)
                {
                    temp = addNum(small, big);
                    res.emplace_back(temp);
                }
            }

            //�������ݽ�������
            big++;
            count += big;
        }
    
        return res;
    }

    vector<int> addNum(int small, int big)
    {
        vector<int> temp;
        //�������ֵ��ӽ�������
        //emplaceЧ�ʱ�push�ߣ�������ʱ���ݵĹ���
        for(int i = small; i <= big; i++)
        {
            temp.emplace_back(i);
        }

        return temp;
    }
};
