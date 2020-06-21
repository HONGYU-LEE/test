/*
手套
https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。
所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
给定颜色种数n(1≤n≤13),同时给定两个长度为n的数组left,right,分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。
*/

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        int min = 0;
        int leftCount = 0, rightCount = 0;
        int leftMin = 26, rightMin = 26;
        
        for(size_t i = 0; i < left.size(); i++)
        {
        	//如果某一手套有一边为0，则说明永远不能配对，全部取出 
            if(!left[i] || !right[i])
            {
                min = min + left[i] + right[i];
            }
            else
            {
            	//计算出左边和右边的手套总数，和同一颜色最少的手套 
                leftCount += left[i];
                rightCount += right[i];
                
                if(leftMin > left[i])
                {
                    leftMin = left[i];
                }
                
                if(rightMin > right[i])
                {
                    rightMin = right[i];
                }
            }
        }
        
        //找到最小的那一边，将除了出现次数最少的手套外全部取出，这样就能保证此时从最少端随便取出一个手套就能遍及所有颜色，从对面再取任何一个手套就能完成配对 
        min += ((rightCount < leftCount) ? (rightCount - rightMin) : (leftCount - leftMin));
            
        //左右两边各取一个 
        return min + 2;
    }
};
