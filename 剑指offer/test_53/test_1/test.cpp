class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(!nums.size())
            return 0;

        int left = findLeft(nums, target);
        int right = findRight(nums, target);

        if(left == -1 && right == -1)
            return 0;

        return (right - left + 1);
    }

    int findLeft(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        int mid = (left + right) / 2;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(target == nums[mid])
            {
                right = mid;
            }
            else if(target < nums[mid])
            {
                right = mid;
            }
            else if(target > nums[mid])
            {
                left = mid + 1;
            }
        }

        if(left == nums.size())
            return -1;

        return nums[left] == target ? left : -1;
    }

    int findRight(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size();
        int mid = (left + right) / 2;

        while(left < right)
        {
            mid = (left + right) / 2;

            if(target == nums[mid])
            {
                left = mid + 1;
            }
            else if(target < nums[mid])
            {
                right = mid;
            }
            else if(target > nums[mid])
            {
                left = mid + 1;
            }
        }

        if(left == 0)
            return -1;

        return nums[left - 1] == target ? (left - 1) : -1;
    }

};
