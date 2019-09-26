#include<stdio.h>

void print()
{
	char a;
	scanf("%c",&a); 
	
	if( a != '\n')
		print();
		
	if( a != '\n')
		printf("%c",a);	
}

int main()
{
	print();
	return 0; 
} 
