/*
�����������
https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b�������һ���㷨�����a��b�������������ȵı�š�
��������int a,b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ� 
*/

class LCA {
public:
    int getLCA(int a, int b) {
        //����������ȼ�����������㣬���Դ����һ��/2�ҵ����ĸ��ڵ㣬ֱ�������ڵ���ͬʱ��˵���ҵ����㣬����
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
        //�����һ����Ϊ1�������ض��ǹ�������
        if(a == 1)
            return a;
        else if(b == 1)
            return b;
        
        
        int parentA = a;
        int parentB = b;
        
        //������ݷ���ǰ��
        if(parentA < parentB)
        {
            swap(parentA, parentB);
        }
        
        int levelA = getLevel(parentA);
        int levelB = getLevel(parentB);
        
        //����Ϊͬ��
        while(levelA != levelB)
        {
            parentA /= 2;
            levelA--;
        }
        
        //��ͬ�����ݵĹ�������
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
