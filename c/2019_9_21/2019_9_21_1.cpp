#include<stdio.h>
int main()
{	
	int i,j,t,n;
	int a[] = {1,3,5,7,9};
	int b[] = {2,4,6,8,10};
	n = sizeof(a)/sizeof(a[0]);
	for(i=0 ; i<n; i++){
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
	printf("����a��Ԫ��Ϊ��"); 
	for(i=0 ; i<n; i++)
		printf("%d ",a[i]);
	printf("\n����b��Ԫ��Ϊ��"); 
	for(i=0 ; i<n; i++)
		printf("%d ",b[i]);
	return 0;
}
