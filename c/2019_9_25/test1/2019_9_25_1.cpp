#include<stdio.h>
#include<string.h>
#include<windows.h>

int main()
{
	char str1[20],str2[20];
	int size,i,right,left;
	gets(str1);
	strcpy(str2,str1); 
	size = strlen(str1);
	right = size - 1;
	left = 0;
	
	for(i=0; i<=right; i++)
	{
		str2[i] = ' '; 
	}
	
	while(left <= right)
	{
		str2[left] = str1[left];
		str2[right] = str1[right];	
		puts(str2); 
		Sleep(1000);
		left++;
		right--;	
	} 

	return 0;
}
