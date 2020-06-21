/*
����
https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡�
�����������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������
*/

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int min = 0;
        int leftCount = 0, rightCount = 0;
        int leftMin = 26, rightMin = 26;
        
        for(size_t i = 0; i < left.size(); i++)
        {
        	//���ĳһ������һ��Ϊ0����˵����Զ������ԣ�ȫ��ȡ�� 
            if(!left[i] || !right[i])
            {
                min = min + left[i] + right[i];
            }
            else
            {
            	//�������ߺ��ұߵ�������������ͬһ��ɫ���ٵ����� 
                leftCount += left[i];
                rightCount += right[i];
                
                if(leftMin > left[i])
                {
                    leftMin = left[i];
                }
                
                if(rightMin > right[i])
                {
                    rightMin = right[i];
                }
            }
        }
        
        //�ҵ���С����һ�ߣ������˳��ִ������ٵ�������ȫ��ȡ�����������ܱ�֤��ʱ�����ٶ����ȡ��һ�����׾��ܱ鼰������ɫ���Ӷ�����ȡ�κ�һ�����׾��������� 
        min += ((rightCount < leftCount) ? (rightCount - rightMin) : (leftCount - leftMin));
            
        //�������߸�ȡһ�� 
        return min + 2;
    }
};
