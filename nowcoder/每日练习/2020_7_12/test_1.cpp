/*
数据库连接池
链接：https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e
来源：牛客网

Web系统通常会频繁地访问数据库，如果每次访问都创建新连接，性能会很差。为了提高性能，架构师决定复用已经创建的连接。当收到请求，并且连接池中没有剩余可用的连接时，系统会创建一个新连接，当请求处理完成时该连接会被放入连接池中，供后续请求使用。

现在提供你处理请求的日志，请你分析一下连接池最多需要创建多少个连接。

*/
#include<vector>
#include<string>
#include<iostream>
using namespace std;

/*
	维护一个数组，当当前连接数大于最大连接数时则更新 
*/
int main()
{
    size_t num;
    
    while(cin >> num)
    {
        vector<string> vec;
        size_t max = 0;
        for(size_t i = 0; i < num; i++)
        {
            string id, option;
            cin >> id >> option;
            
            if(option == "connect")
            {
                vec.push_back(id);
            }
            else
            {
                for(size_t i = 0; i < vec.size(); i++)
                {
                    if(vec[i] == id)
                    {
                        vec.erase(vec.begin() + i);
                        break;
                    }
                }
            }
            
            if(vec.size() > max)
            {
                max = vec.size();
            }
        }
        
        cout << max << endl;
    }
}
