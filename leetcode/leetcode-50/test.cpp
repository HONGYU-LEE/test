class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        else if(n == 1)
            return x;
        //����߽�

        int i = n;
        double res = 1;

        while(i != 0)
        {
            if(i & 1)
            {
                res *= x;
            }
            //���Ϊ�������ݣ�������һ��x�������һλΪ1��˵�����������ȼ���i % 2 == 1

            x *= x;
            i /= 2;
            //�����и���������>>,����ǰ���ȶ����ݽ��д���
        }
        //�������㷨
        return  n > 0 ? res : 1 / res;
    }
};
