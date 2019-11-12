#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int total = 20, bottle = 20, empty = 20, t;
	while (bottle)
	{
		bottle = empty / 2;
		//空瓶能换多少瓶
		t = empty % 2;
		//换剩下的空瓶
		empty = bottle + t;
		//换剩下的和刚喝完的
		total += bottle;
	}
	printf("最多可以喝%d瓶饮料\n",total);
	return 0;
}