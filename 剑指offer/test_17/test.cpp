class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = pow(10, n);
        vector<int> res;
        for(int i = 1; i < max; i++)
        {
            res.push_back(i);
        }

        return res;
    }
};
