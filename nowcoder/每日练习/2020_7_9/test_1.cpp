/*
链接：https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855
来源：牛客网
收件人列表
NowCoder每天要给许多客户写电子邮件。正如你所知，如果一封邮件中包含多个收件人，收件人姓名之间会用一个逗号和空格隔开；如果收件人姓名也包含空格或逗号，则姓名需要用双引号包含。
现在给你一组收件人姓名，请你帮他生成相应的收件人列表。
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int num;
    while(cin >> num)
    {
        string res;
        bool first = true;
        cin.get();
        for(size_t i = 0; i < num; i++)
        {
            string temp;
            getline(cin, temp);
           
            //没有空格和逗号时
            if(temp.find(' ') == string::npos && temp.find(',') == string::npos)
            {
                if(first == false)
                {
                    cout << ", ";
                }
                
                cout << temp;
            }
            else
            {
                if(first == false)
                {
                    cout << ", ";
                }
                
                cout << '"' << temp << '"';
            }
            first = false;
        }
        cout << endl;
    }
    return 0;
}
