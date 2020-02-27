#include <iostream> 
#include <string>

using namespace std;

int main()
{
	string max_word, prev_word, word;
	int max_count = 0, count = 0;
	
	while(cin >> word)
	{
		if(word == prev_word)
		{
			count++;
		}
		else 
		{
			count = 1;
			prev_word = word;
		}
		
		if(count > max_count)
		{
			max_count = count;
			max_word = word;
		}
	}
	
	if(max_count <= 1)
		cout << "no word was repeated" << endl;
	else
		cout << max_word << " repeated" << max_count << "times" << endl;
	return 0;
}
