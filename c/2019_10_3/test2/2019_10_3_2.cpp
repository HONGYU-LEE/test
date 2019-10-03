#include<stdio.h>

void reverse_string(char * a)
{
	if(*a != '\0')
	{
		reverse_string(a+1);
	}
	if(*a != '\0')
		printf("%c",*a);
	 
} 
int main()
{
	char *a ="HELLO WORLD";
	printf("%s\n",a);
	reverse_string(a); 
	return 0; 
} 
