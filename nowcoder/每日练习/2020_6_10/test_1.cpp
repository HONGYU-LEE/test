/*
另类加法
https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。

给定两个int A和B。请返回A＋B的值
*/

class UnusualAdd {
public:
    /*
    思路：位运算。通过A ^ B来得到不同位之间相加的结果，然后又通过A & B来找到相同的位，两者相加后则是进位的结果，所以<<1
    结果就是res = cur + next;
    但是这里又会有加号，所以需要继续重复上面的过程，转换为cur ^ next + cur & next << 1。
    直到进位消失时即res = cur + 0，则说明完全处理完毕。
    */
    int addAB(int A, int B) {
        int cur, next;
        
        while(B != 0)
        {
            cur = A ^ B;
            next = unsigned(A & B) << 1;
            
            A = cur;
            B = next;
        }
        
        return A;
    }
};
