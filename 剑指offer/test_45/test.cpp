class Solution {
public:
    //Ҫ�����������������С���ͷֱ�Ƚ�������ϵ�˳��Ĵ�С��������С�����
    static bool compare(const string& s1, const string& s2)
    {
        return s1 + s2 < s2 + s1;
    }
   
    string minNumber(vector<int>& nums) {   
        vector<string> str;
        string ret;

        //����ת�ַ���
        for(auto i : nums)
        {
            str.push_back(to_string(i));
        }

        //��С��������
        sort(str.begin(), str.end(), compare);

      //��С�����������
        for(auto i : str)
        {
            ret += i;
        }

        return ret;
    }
};
