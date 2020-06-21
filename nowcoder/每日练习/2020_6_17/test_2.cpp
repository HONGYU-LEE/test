/*
�˿��ƴ�С
https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
������Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string cards;
    
    while(getline(cin, cards))
    {
        //���ĳһ������ը��ֱ�ӻ�ʤ
        if(cards.find("joker JOKER") != string::npos)
        {
            cout << "joker JOKER" << endl;
        }
        else
        {
            int i = cards.find('-');
            
            string left = cards.substr(0, i);
            string right = cards.substr(i + 1, cards.size());
            
            //����Ϊ�ո�����һ
            size_t leftNum = count(left.begin(), left.end(), ' ') + 1;
            size_t rightNum = count(right.begin(), right.end(), ' ') + 1;
            

            //����ֻ��ĳ��ը������ը����������¿������Ͷ���ͬ������ֻ��Ҫ�Ƚϵ�һ�����ּ��ɡ�
            if(leftNum == rightNum)
            {
                //��¼�����ƵĴ�С
                string str = "345678910JKQA2jokerJOKER";
                //�ҳ���һ��
                string leftCard = left.substr(0, left.find(' '));
                string rightCard = right.substr(0, right.find(' '));
                
                //�Ƚϵ�һ��
                if(str.find(leftCard) > str.find(rightCard))
                    cout << left << endl;
                else 
                    cout << right << endl;
            }
            //���ĳ����ը����ֱ�ӻ�ʤ
            else
            {
                if(leftNum == 4)
                    cout << left << endl;
                else if(rightNum == 4)
                    cout << right << endl;
                //����Ȳ���ͬ����û��ը������˵��������
                else
                    cout << "ERROR" << endl;
            }
            
        }
        
    }
    return 0;
}

