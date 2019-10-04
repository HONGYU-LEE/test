#include<stdio.h>
int strlen(char *a)
{
	if(*a == '\0')
		return 0;
	return 1+strlen(a+1);
}
int main()
{
	char *a="helloworld";
	int count =strlen(a) ; 
	printf("%d\n",count); 
	return 0;
} 
