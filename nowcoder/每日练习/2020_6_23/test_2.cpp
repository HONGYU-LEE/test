/*
MP3���λ��
https://www.nowcoder.com/practice/eaf5b886bd6645dd9cfb5406f3753e15?tpId=37&&tqId=21287&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
*/

#include<iostream>
#include<string> 
using namespace std; 

int main() 
{ 
	string str; 
	int num;
	while(cin >> num >> str) 
	{ 
		int cur = 1, pageFirst = 1; //ֻ��һҳ 
		
		if(num <= 4) 
		{ 
			for(auto ch : str) 
			{ 
				//�ӵ�һ��ֱ�ӵ����һ�� 
				if(cur == 1 && ch == 'U') ch = num;
				 //���һ��ֱ�ӵ���һ�� 
				 else if(cur == num && ch == 'D') 
				 	ch = 1; 
				 else if(ch == 'U') cur--; 
				 else if(ch == 'D') cur++; 
			}
			
			for(size_t i = 1; i <= num; i++) 
				cout << i << ' '; 
				
			cout << endl; 
			cout << cur << endl; 
		}
		//��ҳʱ 
		else
		{ 
			for(auto ch : str) 
			{ 
				//�����ǰ�ڵ�һҳ��һ��U����ֱ���������һҳ���һ�� 
				if(pageFirst == 1 && cur == 1 && ch == 'U') 
				{ 
					cur = num; 
					pageFirst = cur - 3; 
				}
				//��������һҳ���һ��D��ֱ�ӵ���һҳ��һ�� 
				else if(pageFirst == num - 3 && cur == num && ch == 'D') 
				{ 
					cur = 1; 
					pageFirst = 1; 
				}
				//�����ǰ�漰����ҳ����cur��pageFirst����һ��ǰ�� 
				else if(pageFirst != 1 && cur == pageFirst && ch == 'U') 
				{ 
					pageFirst--; 
					cur--; 
				}
				else if(pageFirst != num - 3 && cur == pageFirst + 3 && ch == 'D') 
				{ 
					pageFirst++; 
					cur++; 
				}
				else if(ch == 'U') 
				{ 
					cur--; 
				}
				else if(ch == 'D') 
				{ 
					cur++; 
				} 
			}
			
				for(size_t i = pageFirst; i <= pageFirst + 3; i++) 
					cout << i << ' '; 
					
				cout << endl; 
				cout << cur << endl; 
		} 
	}	
	
	return 0; 
}
