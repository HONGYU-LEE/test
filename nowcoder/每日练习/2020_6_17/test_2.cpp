/*
扑克牌大小
https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。
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
        //如果某一边有王炸则直接获胜
        if(cards.find("joker JOKER") != string::npos)
        {
            cout << "joker JOKER" << endl;
        }
        else
        {
            int i = cards.find('-');
            
            string left = cards.substr(0, i);
            string right = cards.substr(i + 1, cards.size());
            
            //牌数为空格数加一
            size_t leftNum = count(left.begin(), left.end(), ' ') + 1;
            size_t rightNum = count(right.begin(), right.end(), ' ') + 1;
            

            //除了只有某边炸弹和王炸，其他情况下卡牌类型都相同，所以只需要比较第一个数字即可。
            if(leftNum == rightNum)
            {
                //记录所有牌的大小
                string str = "345678910JKQA2jokerJOKER";
                //找出第一张
                string leftCard = left.substr(0, left.find(' '));
                string rightCard = right.substr(0, right.find(' '));
                
                //比较第一张
                if(str.find(leftCard) > str.find(rightCard))
                    cout << left << endl;
                else 
                    cout << right << endl;
            }
            //如果某边有炸弹则直接获胜
            else
            {
                if(leftNum == 4)
                    cout << left << endl;
                else if(rightNum == 4)
                    cout << right << endl;
                //如果既不相同，又没有炸弹，则说明不成立
                else
                    cout << "ERROR" << endl;
            }
            
        }
        
    }
    return 0;
}

