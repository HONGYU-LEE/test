/*
mkdir 
链接：https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a
来源：牛客网

工作中，每当要部署一台新机器的时候，就意味着有一堆目录需要创建。例如要创建目录“/usr/local/bin”，就需要此次创建“/usr”、“/usr/local”以及“/usr/local/bin”。好在，Linux下mkdir提供了强大的“-p”选项，只要一条命令“mkdir -p /usr/local/bin”就能自动创建需要的上级目录。
现在给你一些需要创建的文件夹目录，请你帮忙生成相应的“mkdir -p”命令。
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    size_t num;
    
    while(cin >> num)
    {
        vector<string> res(num);
        vector<bool> flag(num, true);
        for(size_t i = 0; i < num; i++)
        {
            cin >> res[i];
        }
        //排序，让数据更容易判断
        sort(res.begin(), res.end());
         
        for(size_t i = 1; i < num; i++)
        {
            //相同时删除其中一个
            if(res[i - 1] == res[i])
            {
                res[i - 1] = false;
            }
            //如果前一个为后一个子串，则删除子串
            else if( res[i - 1].size() < res[i].size()
                     && res[i - 1] == res[i].substr(0, res[i - 1].size())
                     && res[i][res[i - 1].size()] == '/'
                   )
            {
                flag[i - 1] = false;
            }
            
        }
            
        for(size_t i = 0; i < num; i++)
        {
            if(flag[i] == true)
            {
                cout << "mkdir -p " << res[i] << endl;
            }
        }
        
        cout << endl;
    }
    
    return 0;
}
