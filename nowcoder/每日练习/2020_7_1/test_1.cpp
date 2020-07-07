class Solution {
public:
    /**
     *  奇数位上都是奇数或者偶数位上都是偶数
     *  输入：数组arr，长度大于2
     *  len：arr的长度
     *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
     */
    void oddInOddEvenInEven(vector<int>& arr, int len) {
        //双指针，一个指向奇数位一个指向偶数位，不符合时交换
        int i = 0, j = 1;
        
        while(i < len && j < len)
        {
            //找到偶数位上不为偶数的位置
            while(!(arr[i] & 1) && i < len)
            {
                i += 2;
            }
            
            //找到奇数位上不为奇数的位置
            while((arr[j] & 1) && j < len)
            {
                j += 2;
            }
            
            //加个判断防止越界
            if(i < len && j < len)
            {
                swap(arr[i], arr[j]);
            }
            
            i += 2;
            j += 2;
        }
    }
};
