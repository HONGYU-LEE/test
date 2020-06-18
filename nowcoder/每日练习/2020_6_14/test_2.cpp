/*
��ʯ��
https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&&tqId=29852&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void divisorNum(int n, vector<int> &divNum)
{
    //һ������һ��Լ���ض���һ���������Ŀ�����һ��С�����Ŀ���
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            divNum.push_back(i);
            
            //��������ڱ���˵�����ǿ�����n / i�Ǵ��ڿ�������һ��Լ��
            if(n / i != i)
                divNum.push_back(n / i);
        }
    }
}

//��̬�滮
int Jump(int N, int M)
{
    //�࿪һ����ֹԽ��
    vector<int> step(M + 1, 0);
    step[N] = 1;
    
    for(int i = N; i < M; i++)
    {
        //���Ϊ0����˵����λ�ò��ɴ
        if(step[i] == 0)
            continue;        
        //���汾�����п��ߵĲ���
        vector<int> divNum;
        //��ȡ���п��߲���
        divisorNum(i, divNum);
        
        for(size_t j = 0; j < divNum.size(); j++)
        {
            /*
                ���ֿ��ߵľ���ΪdivNum[j] + i;
                ��ΪҪ����̾��룬Ҳ���ǵ�ǰ��ȥ�Ĳ�������ԭ������Ĳ�������Сֵ������״̬����Ϊ
                step[divNum[j] + i] = min(step[divNum[j] + i], step[i] + 1)
            */
            //���߾������С�ڵ���M�������Խ�硣step[divNum[j] + i] == 0��˵���Ǹ�λ�õ�һ�ε��
            if(divNum[j] + i <= M && step[divNum[j] + i] != 0)
            {
                step[divNum[j] + i] = min(step[divNum[j] + i], step[i] + 1);
            }
            //����Ǹ�λ���ǵ�һ�ε�������Ǹ�λ�ø���Ϊ��ǰλ�õ���С����+1
            else if(divNum[j] + i <= M)
            {
                step[divNum[j] + i] = step[i] + 1;
            }
        }
    }
    
    //���ɴ�
    if(step[M] == 0)
        return -1;
    
    return step[M] - 1;
}

int main()
{
    int N, M;
       
    while(cin >> N >> M)
    {
        cout << Jump(N, M) << endl;
    }
    
    return 0;
}
