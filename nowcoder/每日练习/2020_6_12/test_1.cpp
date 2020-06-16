/*
最近公共祖先
https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。 
*/

class LCA {
public:
    int getLCA(int a, int b) {
        //最近公共祖先即两者最近交点，所以大的那一方/2找到他的根节点，直到两个节点相同时，说明找到交点，返回
        while(a != b)
        {
            if(a > b)
                a /= 2;
            else 
                b /= 2;
        }
        
        return a;
    }
};

class LCA {
public:
    int getLevel(int root)
    {
        int count = 1;
        while(root != 1)
        {
            root /= 2;
            count++;
        }
        
        return count;
    }
    
    int getLCA(int a, int b) {
        //如果有一个数为1，则他必定是公共祖先
        if(a == 1)
            return a;
        else if(b == 1)
            return b;
        
        
        int parentA = a;
        int parentB = b;
        
        //大的数据放在前面
        if(parentA < parentB)
        {
            swap(parentA, parentB);
        }
        
        int levelA = getLevel(parentA);
        int levelB = getLevel(parentB);
        
        //处理为同层
        while(levelA != levelB)
        {
            parentA /= 2;
            levelA--;
        }
        
        //求同层数据的公共祖先
        while(parentA != parentB)
        {
            parentA /= 2;
            parentB /= 2;
            
            if(parentA == 1 && parentB == 1)
                return 1;
        }
        
        return parentA;
    }
};
