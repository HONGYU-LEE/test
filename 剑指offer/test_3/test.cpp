class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int size = nums.size();
		if (size < 2)
			return false;
		//�������������ض�û���ظ���
		for (int i = 0; i < size; ++i)
		{
			if (nums[i] < 0 || nums[i] > size - 1)
			{
				return false;
			}
		}
		//��Χ���
		for (int i = 0; i < size; ++i)
		{
			while (nums[i] != i)
			{
				//������������i���ֹ������ڶ�Ӧ��ֵ�±�����ֳ��ֹ�����˵�����������Σ��������ظ�
				if (nums[i] == nums[nums[i]])
				{
					return nums[i];
				}

				swap(nums[i], nums[nums[i]]);
				//�����i��λ�õ���ֵ��Ϊi,˵��û�зŵ���Ӧλ�ã�����Ӧ������m���Ӧ�±�����ݽ��н���
			}
		}
		return false;
	}
};
//ԭ���û�

