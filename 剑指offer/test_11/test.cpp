class Solution {
public:
    int numWays(int n) {
        int first = 1, second = 2, third = 3;

        if(n <= 1)
            return first;
        else if(n <= 2)
            return second;

        for(int i = 2; i < n; i++)
        {
            third = (second + first) % 1000000007;

            first = second;
            second = third;
        }

        return third;
    }
};
