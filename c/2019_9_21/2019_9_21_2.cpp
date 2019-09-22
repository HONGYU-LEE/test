#include<stdio.h>
int main()
{	
	int i,j=1;
	double sum=0;
	for(i=1; i<=100; i++){
		sum += ((1.0/i)*j);
		j *= -1; 
	}
	printf("½á¹ûÎª%lf",sum);
	return 0;
}
