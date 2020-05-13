class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int begin = 0, end = nums.size() - 1;
        int mid = (end - begin) / 2 + begin;
        while(begin <= end)
        {
            mid = (end - begin) / 2 + begin;

            if(nums[mid] == mid)
            {
                begin = mid + 1;
            }
            else if(nums[mid] != mid)
            {
                end = mid - 1;
            }
        }

        return begin;
    }
};
