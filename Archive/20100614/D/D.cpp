#include <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n<=5)puts("The stranger will win!!");
		else if(n>=16)puts("I will win!!");
		else puts("It's an endless game!!");
	}
	return 0;
}