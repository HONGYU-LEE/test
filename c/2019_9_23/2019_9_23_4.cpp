#include<stdio.h>
int main()
{
	char n;
	while(1)
	{
		n =getchar();
		if( n >= '0' && n <= '9')
			continue;
		else if( n>= 'a' && n<= 'z')
		{
			n -= 32;
		} 
		else if( n>= 'A' && n<= 'Z')
		{
			n += 32;
		}
		printf("%c",n); 
	}
	return 0;
} 
