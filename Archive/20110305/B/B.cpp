#include <stdio.h>

char s[2000];

int main()
{
	int i,a,b,c;
	while(gets(s))
	{
		for(i=0;s[i]=='o';i++);a=i;
		if(s[i]!='z')
		{
			puts("Wrong Answer");
			continue;
		}
		for(i++;s[i]=='o';i++);b=i-a-1;
		if(s[i]!='j')
		{
			puts("Wrong Answer");
			continue;
		}
		for(i++;s[i]=='o';i++);c=i-a-b-2;
		if(s[i])
		{
			puts("Wrong Answer");
			continue;
		}
		while(1)
		{
			if(a==c && b==1)
			{
				puts("Accepted");
				break;
			}
			if(b>=1 && c>=a)
			{
				b--;c-=a;
			}
			else
			{
				puts("Wrong Answer");
				break;
			}
		}
	}
	return 0;
}
