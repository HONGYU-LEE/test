/*
���������ַ�����������Ӵ� 
���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
https://www.nowcoder.com/practice/181a1a71c7574266ad07f9739f791506?tpId=37&&tqId=21288&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1, s2;
    
    while(cin >> s1 >> s2)
    {
        if(s1.size() > s2.size())
            s1.swap(s2);
        
        string sub;
        string minSub;
        int count = 0;
        
        int i  = 0;
        while(i < s1.size())
        {
            if(sub.empty() || (s2.find(sub) != string::npos))
            {
                sub += s1[i++];
            }
            else
            {
                sub.erase(sub.begin());
            }
            
            if((s2.find(sub) != string::npos) && (sub.size() > count))
            {
                minSub = sub;
                count = minSub.size();
            }
            
        }
        
        cout << minSub << endl;
    }
    return 0;
}
