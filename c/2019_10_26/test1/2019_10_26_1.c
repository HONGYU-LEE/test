#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i = 2, n, a = 0, b = 1, c = a + b, x, y, count = 0;
	scanf("%d", &n);
	while (c < n)
	{
		a = b;
		b = c;
		c = a + b;
		i++;
	}
	x = c - n;
	y = n - b;
	if (x < y)
	{
		count = x;
	}
	else
	{
		count = y;
	}
	printf("¾àÀëì³²¨ÄÇÆõÊýµÄ×î¶Ì¾àÀëÎª£º%d\n", count);
	return 0;
}