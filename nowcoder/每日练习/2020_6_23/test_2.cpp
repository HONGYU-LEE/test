/*
MP3光标位置
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
		int cur = 1, pageFirst = 1; //只有一页 
		
		if(num <= 4) 
		{ 
			for(auto ch : str) 
			{ 
				//从第一首直接到最后一首 
				if(cur == 1 && ch == 'U') ch = num;
				 //最后一首直接到第一首 
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
		//多页时 
		else
		{ 
			for(auto ch : str) 
			{ 
				//如果当前在第一页第一首U，则直接跳到最后一页最后一首 
				if(pageFirst == 1 && cur == 1 && ch == 'U') 
				{ 
					cur = num; 
					pageFirst = cur - 3; 
				}
				//如果在最后一页最后一个D，直接到第一页第一个 
				else if(pageFirst == num - 3 && cur == num && ch == 'D') 
				{ 
					cur = 1; 
					pageFirst = 1; 
				}
				//如果当前涉及到翻页，则cur和pageFirst两个一起前进 
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
