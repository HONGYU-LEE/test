class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;

        while(begin < end)
        {
            int sum = nums[begin] + nums[end];
            if(sum == target)
                break; 
            else if(sum < target)
            {
                begin++;
            } 
            else
            {
                end--;
            }
        }

        return {nums[begin], nums[end]};
    }
};
