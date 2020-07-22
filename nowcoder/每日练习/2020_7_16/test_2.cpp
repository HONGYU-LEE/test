/*
������
https://www.nowcoder.com/questionTerminal/a811535fed784ea492b63622c28c75c5
NowCoder��������������壬���ڸ���һ����֣������æ�ж�������û���������飨�������Ҳ�㣩��
*/

#include<iostream>
#include<vector>

using namespace std;

bool search(string (&str)[20])
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            //���Ϊ��������
            if(str[i][j] == '.')
            {
                continue;
            }
            else
            {
                //����Ǻ�����߰��壬�������ж���Χ�ĸ�λ��
                int left = 1, down = 1, left_line = 1, right_line = 1;
                
                char flag = str[i][j];
                for(int x = 1; x < 5; x++)
                {
                    if(i < 16 && str[i + x][j] == flag)
                    {
                        left++;
                    }
                    
                    if(j < 16 && str[i][j + x] == flag)
                    {
                        down++;
                    }
                    
                    if(i < 16 && j < 16 && str[i + x][j + x] == flag)
                    {
                        left_line++;
                    }
                    
                    if(i < 16 && j > 3 && str[i + x][j - x] == flag)
                    {
                        right_line++;
                    }
                }
                
                if(left >= 5 || down >= 5 || left_line >= 5 || right_line >= 5)
                {
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main()
{
    string str[20];
    while(cin >> str[0])
    {
        for(size_t i = 1; i < 20; i++)
        {
            cin >> str[i];
        }
        
        if(search(str))
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
