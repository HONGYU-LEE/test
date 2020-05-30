class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        //�ȷ���k��Ԫ�أ�ά��һ����k��Ԫ�صĶ�
        for(size_t i = 0; i < k; i++)
        {
            heap.push(nums[i]);
        }
        //����ȶѶ��������,ʹ�Ѷ�Ϊ��K������
        for(size_t i = k; i < nums.size(); i++)
        {
            if(heap.top() < nums[i])
            { 
                heap.pop(); 
                heap.push(nums[i]);  
            }           
        }
        return heap.top();
    }
};
