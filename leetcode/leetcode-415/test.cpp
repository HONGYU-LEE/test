class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string res;
        int next = 0, val1 = 0, val2 = 0, count = 0;

        //�������ַ���ȫ���������ֹͣ
        while(end1 >= 0 || end2 >= 0)
        {
            //���ĳ���ַ����Ѿ������꣬����������Ĳ��ֱ�Ϊ0���������
            if(end1 >= 0)
                val1 = num1[end1--] - '0';
            else 
                val1 = 0;

            if(end2 >= 0)
                val2 = num2[end2--] - '0';
            else
                val2 = 0;

            //�������ǰ��С��Ȼ���λ����
            count = val1 + val2 + next;
            next = 0;

            //���Ϊ��λ�������λ
            if(count > 9)
            {
                count -= 10;
                next = 1;
            }

            res.push_back(count + '0');
        }

        //�����һ�λ��н�λ��ʱ��
        if(next)
        {
            res.push_back('1');
        }

        //��ת����
        reverse(res.begin(), res.end());
        return res;
    }
};
