/*
����ӷ�
https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
���дһ��������������������ӡ�����ʹ��+�����������������

��������int A��B���뷵��A��B��ֵ
*/

class UnusualAdd {
public:
    /*
    ˼·��λ���㡣ͨ��A ^ B���õ���ͬλ֮����ӵĽ����Ȼ����ͨ��A & B���ҵ���ͬ��λ��������Ӻ����ǽ�λ�Ľ��������<<1
    �������res = cur + next;
    ���������ֻ��мӺţ�������Ҫ�����ظ�����Ĺ��̣�ת��Ϊcur ^ next + cur & next << 1��
    ֱ����λ��ʧʱ��res = cur + 0����˵����ȫ������ϡ�
    */
    int addAB(int A, int B) {
        int cur, next;
        
        while(B != 0)
        {
            cur = A ^ B;
            next = unsigned(A & B) << 1;
            
            A = cur;
            B = next;
        }
        
        return A;
    }
};
