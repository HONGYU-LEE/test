class Solution {
public:
    //要是组合起来的数据最小，就分别比较两者组合的顺序的大小，返回最小的组合
    static bool compare(const string& s1, const string& s2)
    {
        return s1 + s2 < s2 + s1;
    }
   
    string minNumber(vector<int>& nums) {   
        vector<string> str;
        string ret;

        //数字转字符串
        for(auto i : nums)
        {
            str.push_back(to_string(i));
        }

        //从小到大排序
        sort(str.begin(), str.end(), compare);

      //从小到大组合起来
        for(auto i : str)
        {
            ret += i;
        }

        return ret;
    }
};
