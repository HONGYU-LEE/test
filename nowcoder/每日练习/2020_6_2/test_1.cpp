#include<iostream>
#include<vector>
using namespace std;

/*
����������
https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false 
���ӣ�https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?orderByHotValue=1&page=1&onlyReference=false
��Դ��ţ����

ţţ��������������Ϊһ��������һ��������������,��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A,��������һ�������ǰ�����A��Ϊ���ɶ�����������,ţţ��֪�������ٿ��԰���������Ϊ��������������.
��������ʾ,ţţ���԰�����A����Ϊ[1,2,3]��[2,2,1]��������������,������Ҫ����Ϊ2������������,�������2

��������:
����ĵ�һ��Ϊһ��������n(1 �� n �� 10^5)

�ڶ��а���n������A_i(1 �� A_i �� 10^9),��ʾ����A��ÿ�����֡�


�������:
���һ��������ʾţţ���Խ�A���ٻ���Ϊ���ٶ�����������
ʾ��1
����
6
1 2 3 2 2 1
���
2
*/ 

/*
	�ǵ������� vec[i] >= vec[i + 1]
	���� vec[i] > vec[i + 1] ����ǵ����ж� 
	���� vec[i] < vec[i + 1] ����ǵݼ��ж� 
	���ֱ������ 
	�ǵݼ����� vec[i] <= vec[i + 1]
*/ 
int main()
{
	int size;
	while (cin >> size)
	{
        int count = 0;
        vector<int> vec;
        vec.resize(size , 0);
        
        for(int i = 0; i < size; i++)
        {
            cin >> vec[i];
        }
        
        int i = 0;
        
        while(i < size)
        {
            if(vec[i] < vec[i + 1])
            {
                while(i < size && vec[i] <= vec[i + 1])
                {
                    i++;
                }
                
                count++;
                i++;
            }
            else if(vec[i] == vec[i + 1])
            {
                i++;
            }
            else
            {
                while(i < size && vec[i] >= vec[i + 1])
                {
                    i++;
                }
                
                count++;
                i++;                
            }
        }
        
        cout << count << endl;        
    }
	return 0;
}
