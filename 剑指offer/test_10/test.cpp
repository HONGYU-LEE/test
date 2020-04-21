class Solution {
public:
    int fib(int n) {
        int first = 0, second = 1, third = 1;

        if(n < 1)
            return 0;
        else if(n < 2)
            return 1;

        for(int i = 1; i < n; i++)
        {
            third = (second + first) % 1000000007;

            first = second;
            second = third;
        }

        return third;
    }
};
