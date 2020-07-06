/*
快到碗里来
https://www.nowcoder.com/questionTerminal/82424d93369649b98720743c25edc6ce
小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。

现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。
*/


/*
计算周长后判断即可 
*/

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    double s1, s2;
    
    while(cin >> s1 >> s2)
    {
        double perimeter = s2 * 2 * 3.14;
        
        if(s1 < perimeter)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
