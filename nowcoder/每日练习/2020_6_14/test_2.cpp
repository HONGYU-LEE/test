/*
跳石板
https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&&tqId=29852&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void divisorNum(int n, vector<int> &divNum)
{
    //一个数的一对约数必定是一个大于他的开方，一个小于他的开方
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            divNum.push_back(i);
            
            //如果不等于本身，说明不是开方，n / i是大于开方的另一个约数
            if(n / i != i)
                divNum.push_back(n / i);
        }
    }
}

//动态规划
int Jump(int N, int M)
{
    //多开一个防止越界
    vector<int> step(M + 1, 0);
    step[N] = 1;
    
    for(int i = N; i < M; i++)
    {
        //如果为0，则说明该位置不可达。
        if(step[i] == 0)
            continue;        
        //保存本轮所有可走的步数
        vector<int> divNum;
        //获取所有可走步数
        divisorNum(i, divNum);
        
        for(size_t j = 0; j < divNum.size(); j++)
        {
            /*
                本轮可走的距离为divNum[j] + i;
                因为要求最短距离，也就是当前过去的步数和他原本所需的步数的最小值。所以状态方程为
                step[divNum[j] + i] = min(step[divNum[j] + i], step[i] + 1)
            */
            //可走距离必须小于等于M，否则会越界。step[divNum[j] + i] == 0则说明那个位置第一次到达。
            if(divNum[j] + i <= M && step[divNum[j] + i] != 0)
            {
                step[divNum[j] + i] = min(step[divNum[j] + i], step[i] + 1);
            }
            //如果那个位置是第一次到达，所以那个位置更新为当前位置的最小步数+1
            else if(divNum[j] + i <= M)
            {
                step[divNum[j] + i] = step[i] + 1;
            }
        }
    }
    
    //不可达
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
