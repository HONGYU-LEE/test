class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == nullptr || length < 1)
                return;
        
        int count = 0, size = strlen(str);
           
        for(int i = 0; i < size; i++)
        {
            if(str[i] == ' ')
            {
                count++;
            }
        }
        
        int newsize = count * 2 + size;
        
        int i  = size, newi = newsize;
        
        while(i >= 0 && newi > i)
        {
            if(str[i] == ' ')
            {
                str[newi--] = '0';
                str[newi--] = '2';
                str[newi--] = '%';
            }
            else
            {
                str[newi--] = str[i];
            }
            
            i--;
        }
	}
};
