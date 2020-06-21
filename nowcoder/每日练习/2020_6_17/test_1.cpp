/*
��ȫ������
https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&&tqId=21279&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����

�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������

���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��

��������count(int n),���ڼ���n����(��n)��ȫ���ĸ��������㷶Χ, 0 < n <= 500000

����n������ȫ���ĸ����� �쳣�������-1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//�ҳ����г��˱��������Լ��
void getDivNum(int num, vector<int>& divNum)
{
    for(int i = 1; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            divNum.push_back(i);
            
            if((num / i != i) && (num / i != num))
                divNum.push_back(num / i);
        }
    }
}

int main()
{
    int num;
    
    while(cin >> num)
    {
        vector<int> divNum;
        int count = 0;
        
        for(int i = 2; i <= num; i++)
        {
            divNum.clear();
            getDivNum(i, divNum);
            
            //�ж�Լ�����Ƿ���ڱ���
            int sum = 0;
            for(size_t i = 0; i < divNum.size(); i++)
            {
                sum += divNum[i];
            }
            
            if(sum == i)
                count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}
