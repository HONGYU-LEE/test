#include<stdio.h>
#include<string.h>
 
int main()
{
	int i; 	
	char str1[]="password";
	char str2[20]={0};


	for(i=0; i<3; i++)
	{
		printf("ÇëÊäÈëÃÜÂë£º\n"); 
		scanf("%s",str2);
		
		if( 0 == strcmp(str1,str2) )
		{
			printf("ÃÜÂëÕýÈ·£¬ÊäÈë³É¹¦\n");
			break; 
		}
		else
		{
			printf("ÃÜÂë´íÎó\n"); 
		} 
	}
	
	if( 3 == i )
	{
		printf("Èý´ÎÃÜÂë´íÎó£¬ÍË³ö³ÌÐò\n"); 
	} 
	return 0;
} 
