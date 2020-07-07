class Solution {
public:
    /**
     *  ����λ�϶�����������ż��λ�϶���ż��
     *  ���룺����arr�����ȴ���2
     *  len��arr�ĳ���
     *  ��arr����������λ�϶�����������ż��λ�϶���ż��
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        //˫ָ�룬һ��ָ������λһ��ָ��ż��λ��������ʱ����
        int i = 0, j = 1;
        
        while(i < len && j < len)
        {
            //�ҵ�ż��λ�ϲ�Ϊż����λ��
            while(!(arr[i] & 1) && i < len)
            {
                i += 2;
            }
            
            //�ҵ�����λ�ϲ�Ϊ������λ��
            while((arr[j] & 1) && j < len)
            {
                j += 2;
            }
            
            //�Ӹ��жϷ�ֹԽ��
            if(i < len && j < len)
            {
                swap(arr[i], arr[j]);
            }
            
            i += 2;
            j += 2;
        }
    }
};
