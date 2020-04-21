class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		int size = nums.size();
		if (size < 2)
			return false;
		//如果少于两个则必定没有重复的
		for (int i = 0; i < size; ++i)
		{
			if (nums[i] < 0 || nums[i] > size - 1)
			{
				return false;
			}
		}
		//范围检查
		for (int i = 0; i < size; ++i)
		{
			while (nums[i] != i)
			{
				//如果这个数字在i出现过，还在对应数值下标的数字出现过，则说明出现了两次，该数字重复
				if (nums[i] == nums[nums[i]])
				{
					return nums[i];
				}

				swap(nums[i], nums[nums[i]]);
				//如果第i个位置的数值不为i,说明没有放到对应位置，我们应该数字m与对应下标的数据进行交换
			}
		}
		return false;
	}
};
//原地置换

