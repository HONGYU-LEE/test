/*
��̬��̨��
https://www.nowcoder.com/questionTerminal/22243d016f6b47f2a6928b4313c85387
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
*/


/*
���ݽ���ܽ���ɣ�ÿ������һ������ 
*/
class Solution {
public:
    //������ѧ���ɵó���ÿ��Ĵ�������һ�������
    
    int jumpFloorII(int number) {
        if(number == 1)
            return 1;
        
        return 2 * jumpFloorII(number - 1);
    }
};
